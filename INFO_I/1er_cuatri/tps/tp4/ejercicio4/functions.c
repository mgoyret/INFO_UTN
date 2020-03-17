/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            May 29, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"

/* Definicion de la funcion "my_pow" */

/**
 * \fn      int add(int a, int b)
 * \brief   Suma los dos número enteros pasados como parámetros.
 * \author  Marcos Goyret
 * \date    May 29, 2019
 * \param   x base.
 * \param   y exponente.
 * \return  x elevado a la y.
 */
float my_pow(float x, int y)
/* Recibo "x" e "y" como parámetros de la función y retorno el contenido de "res" */
{
    float res = 1;
    int i;
    
    if(y>0)
    {
        for(i=1;i<=y;i++)
        {
            res = res*x;
        }
    }
    else
    {
        if(y<0)
        {
            for(i=1;i<=(y*(-1));i++)
            {
                res = res*x;
            }
            res = 1/res;
        }
        else
        {
            res = 1;
        }
        
    }

    return res;
}