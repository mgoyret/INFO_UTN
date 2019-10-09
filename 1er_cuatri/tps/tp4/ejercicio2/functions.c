/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            May 29, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"

/* Definicion de la funcion "verificar_primo" */

/**
 * \fn      int verificar_primo(unsigned int numero)
 * \brief   verifica si el numero pasado como parametro es o no es primo
 * \author  Marcos Goyret
 * \date    May 29, 2019
 * \param   numero numero a verificar
 * \return  "1" si el parametro ingresado es primo, "0" si no lo es
 */

int verificar_primo(unsigned int numero)
    /* Recibo "numero" como parámetro de la función y retorno el contenido de "res" */
{
    int i, res, divisores = 0;
    for(i=1;i<=numero;i++)
    {
        if((numero%i)==0)
        divisores++;
    }
    if(divisores==2)
    {
        res = 1;
    }
    else
    {
        res = 0;
    }
    return res;
}