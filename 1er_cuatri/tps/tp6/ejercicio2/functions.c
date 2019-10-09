/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 12, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"

/* 1. Definicion de la funcion "reemplazar" */

/**
 * \fn      int reemplazar(char* a, char sust)
 * \brief   Reemplaza un caracter especificado por un '*'.
 * \author  Marcos Goyret
 * \date    Jun 12, 2019
 * \param   p, i contadores.
 * \return  cantidad de veces que se reemplazo el caracter.
 */

int reemplazar(char* a, char sust)
/* Recibo "a" y "sust" como parámetros de la función y retorno el contenido de "p" */
{
    int p = 0, i = 0;
    
    for(i=0; i<strlen(a); i++)
    {
        if(a[i]==sust)
        {
            a[i] = '*';
            p++;
        }
    }
    return p;
}

/* 2. Definicion de la funcion "clear" */

/**
 * \fn      void clean(char* a)
 * \brief   Elimina el caracter '\n' de un string.
 * \author  Marcos Goyret
 * \date    Jun 12, 2019
 * \param   a string ingresado.
 */

void clean(char* a)
/* Recibo "a" como parámetro de la función y no retorno nada */
{
    if (a[strlen(a)-1] == '\n') 
    {
        a[strlen(a)-1] = 0;
    }
}