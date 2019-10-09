/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            May 6, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"

/* 1. Definicion de la funcion "estadistica_vector" */

/**
 * \fn      int estadisticas_vector(float vector[], unsigned int largo, float* resultado, int caracteristica)
 * \brief   calcula promedio, mediana, minimo, o maximo de un vector pasado como parametro
 * \author  Marcos Goyret
 * \date    Jun 6, 2019
 * \param   vector vector ingresado.
 * \param   largo largo del vector.
 * \return  validez de la funcion (ERROR/ EXITO).
 */

int estadisticas_vector(float vector[], unsigned int largo, float* resultado, int caracteristica)
//recibo vector, largo, resultado, caracteristicas, como parametros, paso el resultado por referencia y retorno la validez de la operacion realizada
{
    int i, cantidad = 0;
    float suma = 0, max = 0, min = 0;

    switch (caracteristica)
    {
        case 1:    for(i=0;i<largo;i++)
                            {
                                suma += vector[i];
                                cantidad++;
                            }
                            *resultado = ((float)suma/cantidad);
        break;
        case 2:     bubble_sort(vector, largo); //invoco funcion bubble_sort para ordenar el vector, enviandoselo como parametro
                    if((largo%2)==0)
                        {
                            *resultado = ((vector[(largo/2)-1] + vector[largo/2])/2);
                        }
                            else
                            {
                                *resultado = vector[(largo-1)/2];
                            }
        break;
        case 3:         for(i=0;i<largo;i++)
                        {
                            if(min>vector[i])   min = vector[i];
                        }
                        *resultado = min;
        break;
        case 4:         for(i=0;i<largo;i++)
                        {
                            if(max<vector[i])   max = vector[i];
                        }
                        *resultado = max;
        break;
        default:    return ERROR;
        break;
    }
    return EXITO;
}

/* 2. Definicion de la funcion "bubble_sort" */

/**
 * \fn      void bubble_sort(float* vector, unsigned int largo)
 * \brief   Ordena un vector pasado como parametro
 * \author  Marcos Goyret
 * \date    Jun 6, 2019
 * \param   vector vector ingresado.
 * \param   largo largo del vector.
 */

void bubble_sort(float* vector, unsigned int largo)
//recibo un vector, y el largo como parametros y paso el vector ordenado por referencia.
{
    int i, j, EstaOrdenado;
    float aux;

    for(i=0;i<(largo-1);i++)
    {
        EstaOrdenado = 1;

        for(j=0;j<(largo-1-i);j++)
        {
            if(vector[j]>vector[j+1])
            {
                aux  = vector[j+1];
                vector[j+1] = vector[j];
                vector[j] = aux;
                EstaOrdenado = 0;
            }
        }
        if(EstaOrdenado)               
        {
            break;
        }
    }
}

/* 3. Definicion de la funcion "printar" */

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