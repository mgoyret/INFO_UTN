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
    int numero;
    int res;
    /* Solicito 1 número por consola */
    printf("ingrese un numero entero\n");
    scanf("%u", &numero);
    if(numero<0)
    {
        numero = numero*(-1);
    }
    /* Invoco a la función "verificar_primo", pasándole "numbero" como argumento.
       Almaceno el valor que retorna la función en la variable "res" */
    res = verificar_primo(numero);
    /* Imprimo en pantalla el resultado de la suma */
    printf("\n%d\n", res);

    return 0;
}