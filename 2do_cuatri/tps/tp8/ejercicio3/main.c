/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 26, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/* 1. Tomo numero ingresado por usuario y pido esa cantidad de bytes al S.O. Es para testear el logfile*/
int main ()
{
    int *vec = NULL;
    int val = 0, cant = 0;

    printf("\ningrese numero de bytes:    ");
    scanf("%d", &val);
    log_msg(INFO, __FILE__, __LINE__, "Numero pedido asignado a variable var");

    if(val != 0)
    {
        vec = (int*)malloc((cant + 1)*sizeof(int));
        if(vec != NULL)
        {
            log_msg(INFO, __FILE__, __LINE__, "memoria alocada exitosamente");
            while (val != 0)
            {
                printf("ingrese numero de bytes:    ");
                scanf("%d", &val);
                if(val != 0)
                {
                    vec = (int*)realloc(vec, val*sizeof(int));
                    if(vec != NULL)
                    {
                        log_msg(INFO, __FILE__, __LINE__, "Memoria realocada exitosamente");
                    }
                    else
                    {
                        log_msg(ERROR, __FILE__, __LINE__, "Error al realocar memoria");
                    }
                    
                }
                else
                {
                    printf("Se ingreso '0'\n");
                }
                
            }
        }
        else
        {
            log_msg(ERROR, __FILE__, __LINE__, "Error al alocar memoria");
        }
        
    }
    else
    {
        log_msg(DEBUG, __FILE__, __LINE__, "Se ingreso 0, fin");
    }

    free(vec);
    
    return 0;
}