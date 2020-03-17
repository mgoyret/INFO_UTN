#include "functions.h"

int lecturaPacientes(paciente_t **inicio, char* archivo)
{
    FILE* fp = NULL;
    paciente_t *aux = NULL;
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
            memset(name, '\0', 40);
            dni = -1;
            time = -1;
            
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
                            aux = (paciente_t*)malloc(sizeof(paciente_t)*(++cnt));
                        }
                        else
                        {
                            aux = (paciente_t*)realloc((*inicio), sizeof(paciente_t)*(++cnt));
                        }
                        
                        if(aux != NULL)
                        {
                            (*inicio) = aux;
                            /* (*arr).camp = arr->camp */

                            printf("Cargando nuevo elemento del array de estructuras estructura\n");

                            memset((*inicio)[cnt-1].name, '\0', 40);
                            (*inicio)[cnt-1].dni = 0;
                            (*inicio)[cnt-1].time = 0;

                            strcpy((*inicio)[cnt-1].name, name);
                            (*inicio)[cnt-1].dni = dni;
                            (*inicio)[cnt-1].time = time;

                            GREEN
                            printf("Nueva posicion del array:\n\nName '%s'\nDNI '%ld'\nTime '%f'\n\n", (*inicio)[cnt-1].name, (*inicio)[cnt-1].dni, (*inicio)[cnt-1].time);
                            DEFAULT
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