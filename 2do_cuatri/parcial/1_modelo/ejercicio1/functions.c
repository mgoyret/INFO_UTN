#include "functions.h"

int lecturaPacientes(paciente_t **inicio, char* archivo)
{
    FILE* fp = NULL;
    int exit = 0, cnt = 0;
    char name[40], buff[30];
    long dni = -1;
    float time = -1;

    memset(buff, '\0', 30);

    fp = fopen(archivo, "r");
    if (fp != NULL)
    {
        while (!feof(fp))
        {
            if(fread(name, sizeof(char), 40, fp) != 0)
            {
                printf("LEI: '%s'\n", name);
                if(fread(buff, sizeof(long), 1, fp) != 0)
                {
                    printf("LEI: '%s'\n", buff);
                    dni = atol(buff);
                    memset(buff, '\0', 30);
                    if(fread(buff, sizeof(float), 1, fp) != 0)
                    {
                        printf("LEI: '%s'\n", buff);
                        time = atof(buff);
                        memset(buff, '\0', 30);
                        if (cnt == 0)
                        {
                            *inicio = (paciente_t*)malloc(sizeof(paciente_t)*(cnt+1));
                        }
                        else
                        {
                            *inicio = (paciente_t*)realloc(*inicio, sizeof(paciente_t)*(cnt+1));
                        }
                        if(inicio != NULL)
                        {
                            cnt++;
                            /* (*arr).camp = arr->camp */
                            printf("tiene: '%s'\n", inicio[cnt-1]->name);
                            strcpy((inicio[cnt-1])->name, name);
                            printf("Nombre cargado. En array: '%s'\n", (*inicio[cnt-1]).name);
                            (*inicio[cnt-1]).dni = dni;
                            printf("Dni cargado. En array: '%ld'\n", inicio[cnt-1]->dni);
                            (*inicio[cnt-1]).time = time;
                            printf("Hora cargada. En array: '%f'\n", inicio[cnt-1]->time);
                        }
                        else
                        {
                            SPACE HIGHLIGHT RED
                            printf("Error al asignar memoria dinamica");
                            SPACE DEFAULT
                            exit = -2;
                        }
                    }
                    else
                        printf("No hay mas horas\n");
                }
                else
                    printf("No hay mas dni\n");
            }
            else
                printf("No hay mas nombres\n");

        }
        SPACE HIGHLIGHT BLUE
        printf("Fin del archivo");
        SPACE DEFAULT
    }
    else
    {
        RED HIGHLIGHT SPACE
        printf("Error en funcion open");
        SPACE DEFAULT
        exit = -1;
    }
    
    return exit;
}