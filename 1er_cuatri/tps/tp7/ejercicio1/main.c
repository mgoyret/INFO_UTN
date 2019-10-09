/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 17, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    char* vec = NULL;
    int aux = 0, suma = 0;

    /* 1. Solicito  bytes a reservar por consola */
    printf("Ingrese cantidad de bytes:  ");
    scanf("%d", &aux);
    if(aux > 0)
    {
        vec = (char*)malloc(aux*(sizeof(char)));
        suma += aux;
        printf("%d bytes reservados\n", suma);
        while ((aux != 0) && (vec != NULL) && (suma > 0))
        {
            printf("Ingrese cantidad de bytes:  ");
            scanf("%d", &aux);
            if(aux != 0)
            {
                suma += aux;
                if(suma > 0)
                {
                    vec = (char*)realloc(vec, suma*(sizeof(char)));
                    if(vec != NULL)
                    {
                        printf("%d bytes reservados\n", suma);
                    }
                    else
                    {
                        printf("Realocacion fallida\n");
                        free(vec);
                        return 0;

                    }     
                }
                else
                {
                    printf("Finalizacion del programa\n");
                    printf("Se trataron de reservar 0 o menos bytes\n");
                    free(vec);
                    return 0;
                }
            }
            else
            {
                printf("Finalizacion de programa, se ingreso 0\n"); 
                printf("%d bytes reservados antes de finalizar el programa.\n", suma);
                free(vec);
            }
        }
    }
    else
    {
        if(aux == 0) printf("Finalizacion de programa, se ingreso 0\n");
            else
                printf("Finalizacion de programa, se pretende reservar una cantidad menor que 0\n");
    }   
    return 0;
}