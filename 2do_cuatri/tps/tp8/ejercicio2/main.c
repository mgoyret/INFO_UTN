/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 31, 2019
 * \details         Usar MakeFile para compilar, linkear y ejecutar
 */

#include "functions.h"

/* 1. Se requiere ingresar 2 argumentos por consola */
int main(int argc, char **argv)
{
   	FILE *fp = NULL;
    int wcnt = 0, tcnt = 0;

    if(argc == 3)
    {
        fp = fopen(argv[1], "r");
        if(fp != NULL)
        {
        /* 2. Invoco a funcion 'word_cnt' pasandole 'fp' y 'argv[2]' como parametros */
            wcnt = word_cnt(fp, argv[2]);
        /* 3. Invoco a funcion 'total_cnt' pasandole 'fp' como parametro */
            tcnt = total_cnt(fp);
            fclose(fp);

            printf("\nArchivo:  %s\nCantidad de palabras total: %d\nCantidad de veces que esta la palabra '%s': %d\n", argv[1], tcnt, argv[2], wcnt);
        }
        else
        {
            printf("Error al abrir el archivo\n");
        }
    }
    else
    {
        printf("Cantidad de argumentos invalida\nIngrese nombre del archivo y palabra a buscar\n");
    }
    

    return 0;
}