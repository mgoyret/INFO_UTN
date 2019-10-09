/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            May 17, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

/* 1. Definicion de la funcion "add" */

/**
 * \fn      int add(int a, int b)
 * \brief   Suma los dos número enteros pasados como parámetros.
 * \author  Marcos Goyret
 * \date    May 17, 2019
 * \param   a Primer operando.
 * \param   b Segundo operando.
 * \return  suma de a y b.
 */
    
int add(int a, int b) {
    /* 2. Recibo "a" y "b" como parámetros de la función y retorno el contenido de "result" */
    int result;
    result = a + b;
    return result;
}
