/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 6 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"

/* 1. Definicion de la funcion "calcular_derivada_discreta" */

/**
 * \fn      void calcular_derivada_discreta(int vectorIn[], int vectorOut[], unsigned int largo)
 * \brief   Devuelve la derivada discreta por diferencias finitas de un vector pasado como parametro.
 * \author  Marcos Goyret
 * \date    Jun 6, 2019
 * \param   vectorIn vector ingresado.
 * \param   vectorOut vector resultado
 * \param   largo largo del vector.
 */

void calcular_derivada_discreta(int vectorIn[], int vectorOut[], unsigned int largo)
{
    int i;
    vectorOut[0] = 0;
    for(i=1; i<largo; i++)
    {
        vectorOut[i] = vectorIn[i] - vectorIn[i-1];
    }
}

/* 2. Definicion de la funcion "printar" */

/**
 * \fn      void printar(int vectorIn[], unsigned int largo)
 * \brief   imprime un vector pasado como parametro.
 * \author  Marcos Goyret
 * \date    Jun 6, 2019
 * \param   vectorIn vector ingresado.
 * \param   largo largo del vector.
 */

void printar(int vectorIn[], unsigned int largo)
{
    int i;
    printf("{");
    for(i=0; i<(largo-1); i++)
        {
            printf("%d, ", vectorIn[i]);
        }
    printf("%d}\n", vectorIn[largo-1]);
}