#include "functions.h"

DATOS obtener_info(char* disp, char* camp, char* file)
{
    DATOS var;
    FILE* fp = NULL;
    char line[LINE], *token = NULL;
    int flag = 0;

    fp = fopen(file, "r");
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
                var = obtener_campos(disp, camp, fp, &flag);
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

DATOS obtener_campos(char* disp, char* camp, FILE* fp, int* flag)
{
    DATOS var;
    char line[LINE], *token;

    do
    {
        fgets(line, LINE, fp);
        token = strtok(line, "=");
        if(strcmp(token, camp) == 0)
        {
            *flag = FOUND_CAMP;
            GREEN printf("Campo encontrado\n"); DEFAULT

            token = strtok(NULL, "\n");
            
            strcpy(var.disp, disp);
            strcpy(var.camp, camp);
            var.valor = atoi(token);
        }
    }while((*flag != FOUND_CAMP) && !feof(fp));

    return var;
}