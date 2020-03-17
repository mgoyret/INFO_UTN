/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            May 30, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"
int main()
{
    float x;
    int y;
    float res;
    /* Solicito 2 números por consola */
    printf("ingrese base\n");
    scanf("%f", &x);
    printf("ingrese exponente\n");
    scanf("%d", &y);
    /* Invoco a la función "my_pow", pasándole "x" e "y" como argumentos.
       Almaceno el valor que retorna la función en la variable "res" */
    res = my_pow(x, y);
    
    /* Imprimo en pantalla el resultado de la suma */
    printf("%.3f ^ %d = %.4f\n", x, y, res);

    return 0;
}