/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            May 29, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"
int main()
{
    int random, min, max;
    
    /* Solicito minimo y maximo por consola */
    printf("ingrese un minimo\n");
    scanf("%d", &min);
    printf("ingrese maximo\n");
    scanf("%d",&max);

    /* Invoco a la función "generar_numero_aleatorio", pasándole "min" y "max" como argumentos.
       Almaceno el valor que retorna la función en la variable "random" */
    random = generar_numero_aleatorio(min, max);

    /* Imprimo en pantalla el numero generado  */
    printf("\nEl numero es %d\n", random);

    return 0;
}