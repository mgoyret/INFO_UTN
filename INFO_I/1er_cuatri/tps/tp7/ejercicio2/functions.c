/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 21, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"

/* 1. Definicion de la funcion "printstr" */

/**
 * \fn      void printstr(char* pal, int largo)
 * \brief   Imprime en pantalla un string pasado como parametro.
 * \author  Marcos Goyret
 * \date    Jun 21, 2019
 * \param   pal string.
 * \param   largo cantidad de elementos del string.
 */

void printstr(char* pal, int largo)
/* 2. Recibo "pal" y "largo" como parámetros de la función y no retorno nada */
{
    int i = 0;
    printf("El string es:   {");
    for(i = 0; i < (largo - 1); i++)
    {
        printf("%c, ", pal[i]);
    }
    printf("%c}", pal[largo - 1]);
}