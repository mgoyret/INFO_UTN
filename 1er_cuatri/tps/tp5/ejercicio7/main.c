/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 6, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"
int main()
{
    unsigned int largo;
    int i;
    printf("Ingrese el numero de elementos del vector: \n");
    scanf("%u", &largo);
    int vectorIn[largo], vectorOut[largo];
    //solicito vector
    for(i=0; i<largo; i++)
    {
        printf("Ingresa el elemento numero %d del vector: ", (i+1) );
        scanf("%d", &vectorIn[i]);
    }

    printf("\nVector inicial:   ");
    printar(vectorIn, largo);   //imprimo vector ingresado
    
    calcular_derivada_discreta(vectorIn, vectorOut, largo);

    printf("La derivada discreta por diferencias finitas del vector ingresado es:   ");
    printar(vectorOut, largo);  //imprimo vector resultado

    return 0;
}