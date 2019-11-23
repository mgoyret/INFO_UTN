#include "functions.h"

DATOS buscar_disp(char* disp, char* camp, char* file, int val)
{
    DATOS var;
    FILE* fp = NULL;
    char line[LINE], *token = NULL;
    int flag = 0;

    fp = fopen(file, "r+");
    if (fp != NULL)
    {
        while (!feof(fp))
        {
            fgets(line, LINE, fp);
            token = strtok(line, "[");
            token = strtok(token, "]");
            if (strcmp(token, disp) == 0)
            {
                flag = FOUND_DISP;
                var = cambiar_valor(disp, camp, fp, &flag, val);
            }            
        }
        if(flag == 0) // no se encontro el dispositivo
        {
            HIGHLIGHT RED printf("Dispositivo inexistente\n"); DEFAULT
        }
        else if(flag == FOUND_DISP) //se encontro dispositivo pero no el campo
        {
            HIGHLIGHT RED printf("Campo inexistente\n"); DEFAULT
        }
        if (flag != FOUND_CAMP) // no se encontro el campo
        {
            var.disp[0] = '\0';
            var.camp[0] = '\0';
            var.valor = -1;
        }
        if(flag == FOUND_CAMP)
        {
            SPACE
            printf("Dispositivo: '%s'\nCampo: '%s'\nValor: '%d'\n", var.disp, var.camp, var.valor);
        }
        
        
        if (feof(fp))
        {
            HIGHLIGHT BLUE printf("Se encontro EOF\n"); DEFAULT
        }
    }
    else
    {
        HIGHLIGHT RED printf("Error en funcion fopen\n"); DEFAULT
    }

    return var;
}

DATOS cambiar_valor(char* disp, char* camp, FILE* fp, int* flag, int val)
{
    DATOS var;
    char line[LINE], *token;
    int len = 0;

    do
    {
        fgets(line, LINE, fp);
        len = strlen(line);
        token = strtok(line, "=");
        if(strcmp(token, camp) == 0)
        {
            fseek(fp, -len, SEEK_CUR);
            memset(line, ' ', len);
            //line[len-1] = '\n';
            sprintf(line, "%s=%d", camp, val);
            fwrite(line, sizeof(char), len-1, fp);
            *flag = FOUND_CAMP;

            strcpy(var.disp, disp);
            strcpy(var.camp, camp);
            var.valor = val;            
        }
    }while((*flag != FOUND_CAMP) && !feof(fp));

    return var;
}