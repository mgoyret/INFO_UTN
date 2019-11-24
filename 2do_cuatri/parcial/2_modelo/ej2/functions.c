#include "functions.h"

DATOS buscar_disp(char* disp, char* camp, char* file, int val)
{
    DATOS var;
    FILE* fp = NULL;
    char line[LINE], auxline[LINE], *token = NULL, buff[500];
    int flag = 0;
    memset(buff, '\0', 500);

    fp = fopen(file, "r+");
    if (fp != NULL)
    {
        while (!feof(fp))
        {
            fgets(line, LINE, fp);
            strcpy(auxline, line);
            token = strtok(auxline, "[");
            token = strtok(token, "]");
            if (strcmp(token, disp) == 0)
            {
                strcat(buff, line);
                flag = FOUND_DISP;
                var = cambiar_valor(disp, camp, fp, &flag, val, buff);
            }
            else
            {
                strcat(buff, line);
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
        fclose(fp);
    }
    else
    {
        HIGHLIGHT RED printf("Error en funcion fopen\n"); DEFAULT
    }
    fp = fopen(file, "w");
    if (fp != NULL)
    {
        fwrite(buff, sizeof(char), strlen(buff), fp);
    }

    return var;
}

DATOS cambiar_valor(char* disp, char* camp, FILE* fp, int* flag, int val, char* buff)
{
    DATOS var;
    char line[LINE], auxline[LINE], *token;
    //int len = 0;

    do
    {
        fgets(line, LINE, fp);
        //len = strlen(line);
        strcpy(auxline, line);
        token = strtok(auxline, "=");
        if(strcmp(token, camp) == 0)
        {
            /* La idea principal era solo reescribir esa linea del archivo, pero la cantidad de caracteres a escribir
                debia coincidir con la cantidad de caracteres en esa linea, sino, se escribia sobre la linea siguiente ya que en
                realidad es todo un array seguido */
            //fseek(fp, -len, SEEK_CUR);
            memset(line, '\0', LINE);
            //line[len-1] = '\n';
            sprintf(line, "%s=%d\n", camp, val);
            //fwrite(line, sizeof(char), len-1, fp);
            *flag = FOUND_CAMP;

            strcat(buff, line);

            strcpy(var.disp, disp);
            strcpy(var.camp, camp);
            var.valor = val;            
        }
        else
        {
            strcat(buff, line);
        }
        
    }while((*flag != FOUND_CAMP) && !feof(fp));

    return var;
}