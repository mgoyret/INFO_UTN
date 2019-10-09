/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 3, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */
#include "functions.h"

/* 1. Definicion de la funcion "calculo" */

/**
 * \fn      int add(int a, int b)
 * \brief   Realiza cualquiera de las cuatro operacione basicas, segun digite el usuario, entre dos numeros pasados como parametros.
 * \author  Marcos Goyret
 * \date    Jun 3, 2019
 * \param   operadorA Primer operando.
 * \param   operadorB Segundo operando.
 * \param   operacion operacion a realizar
 */
int calculo(float operadorA, float operadorB, float* resultado, char operacion)
{
    if((operacion=='/')&&(operadorB==0))
    {
        return ERROR;
    }
    //El valor del resultado es pasado por referencia al main
    switch (operacion)
    {
    case '+': *resultado = operadorA+operadorB; 
        break;
    case '-': *resultado = operadorA-operadorB;
        break;
    case '*': *resultado = operadorA*operadorB;
        break;
    case '/': *resultado = operadorA/operadorB;
        break;
    default: 
        break;
    }

    return EXITO;
}