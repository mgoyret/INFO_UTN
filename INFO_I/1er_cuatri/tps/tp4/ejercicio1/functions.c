/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            May 29, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"
/*  Definicion de la funcion "factorial" */

/**
 * \fn      unsigned long factorial(unsigned int numero)
 * \brief   indica el factorial de un numero pasado como parametro
 * \author  Marcos Goyret
 * \date    May 29, 2019
 * \param   numero operando
 * \return  factorial de numero
 */
unsigned long factorial(unsigned int numero)
/* Recibo "numero" como parámetro de la función y retorno el contenido de "res" */
{
    int i;
    int res = 1;

    printf("%u \n", numero);

    for(i=1;i<numero;i++)
    {
        res *= (numero*(numero-1));
        numero -= 2;
        i=0;
    }
    
    return res;
}