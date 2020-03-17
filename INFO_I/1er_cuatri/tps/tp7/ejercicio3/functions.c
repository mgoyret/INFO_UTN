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

void printstr(char* pal, unsigned int largo)
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



/* 3. Definicion de la funcion "orderstr" */

/**
 * \fn      void orderstr(char* pal, unsigned int largo)
 * \brief   ordena alfabeticamente un string pasado como parametro.
 * \author  Marcos Goyret
 * \date    Jun 21, 2019
 * \param   pal string.
 * \param   largo cantidad de elementos del string.
 */

void orderstr(char* pal, unsigned int largo)
/* 4. Recibo "pal" y "largo" como parámetros de la función y no retorno nada */
{
    int i, j, EstaOrdenado; //EstaOrdenado == variable flag
    int aux;

    for(i=0; i<largo; i++)
    {
        if((pal[i] >= 'A') && (pal[i] <= 'Z'))
        {
            pal[i] = pal[i] + 32;
        }
    }
    for(i=0;i<(largo-1);i++)
    {
        EstaOrdenado = 1;

        for(j=0;j<(largo-1-i);j++)
        {
            if(pal[j]>pal[j+1])
            {
                aux  = pal[j+1];
                pal[j+1] = pal[j];
                pal[j] = aux;
                EstaOrdenado = 0;   //solo lo hace si tuvo que swappear alguna vez
            }
        }
        if(EstaOrdenado)   //0=falso, osea q si EstaOrdenado = 0, no entra.        
        {
            break;
        }
    }
    printf("\nEl string fue ordenado\n\n");
}