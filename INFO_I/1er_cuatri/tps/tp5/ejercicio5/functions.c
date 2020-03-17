/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 2, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"

/* 1. Definicion de la funcion "calculo_vector" */

/**
 * \fn      int calculo_vector(float vector[], unsigned int largo, float num, char op)
 * \brief   operacion entre valor y vector pasada como parametro
 * \author  Marcos Goyret
 * \date    Jun 2, 2019
 * \param   vector[] Primer operando.
 * \param   num Segundo operando.
 * \param   op operacion
 * \param   largo largo del vector
 * \return  validez de la operacion
 */

int calculo_vector(float vector[], unsigned int largo, float num, char op)
{
    int i;
    if((op=='/')&&(num==0))
    {
        return ERROR;
    }
        else
        {
            for(i=0; i<largo; i++)
            {
                switch (op)                 /* 2. recibo operandos y operador y paso resultado por referencia */
                {
                    case '+': *(vector+i) = vector[i] + num;
                        break;
                    case '-': *(vector+i) = vector[i] - num;
                        break;
                    case '*': *(vector+i) = vector[i] * num;
                        break;
                    case '/': *(vector+i) = vector[i] / num;
                        break;
                    default: 
                        break;
                }
            }
        }
        


    return EXITO;   //retorno validez de la operacion
}

/* 3. Definicion de la funcion "calcular_derivada_discreta" */

/**
 * \fn      void printar(int vectorIn[], unsigned int largo)
 * \brief   imprime un vector pasado como parametro.
 * \author  Marcos Goyret
 * \date    Jun 6, 2019
 * \param   vectorIn vector ingresado.
 * \param   largo largo del vector.
 */

void printar(float vector[], unsigned int largo)
{
    int i;
    printf("{");
    for(i=0; i<(largo-1); i++)
        {
            printf("%.3f, ", vector[i]);
        }
    printf("%.3f}\n", vector[largo-1]);
}