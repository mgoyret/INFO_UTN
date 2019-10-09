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
    int caracteristica, i;
    float resultado;

    /* 1. Solicito vector */
    printf("Ingrese el numero de elementos del vector: \n");
    scanf("%u", &largo);
    float vector[largo];
    
    for(i=0; i<largo; i++)
    {
        printf("Ingresa el elemento numero %d del vector: ", (i+1) );
        scanf("%f", &vector[i]);
    }
    printar(vector, largo);//invoco funcion printar que imprime vector ingresado en pantalla

    printf("\nIndique caractristica a obtener\n\n1. Promedio\n2. Mediana\n3. Minimo\n4. Maximo\n"); //solicito caracteristica a calcular
    scanf("%d", &caracteristica);
    estadisticas_vector(vector, largo, &resultado, caracteristica);//invoco funcion estadisticas_vector para calcular la caracteristica pedida y la imrimo
    
    printf("El resultado es %f\n", resultado);

    return 0;
}