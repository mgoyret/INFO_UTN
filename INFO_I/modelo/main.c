/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            May 17, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <stdio.h>
#include "functions.h"

int main() {
    int number1, number2, sum;

    /* 1. Solicito 2 números por consola */
    printf("Ingrese un numero: ");
    scanf("%d", &number1);
    printf("Ingrese otro numero: ");
    scanf("%d", &number2);

    /* 2. Invoco a la función "add", pasándole "number1" y "number2" como argumentos.
        Almaceno el valor que retorna la función en la variable "sum" */
    sum = add(number1, number2);

    /* 3. Imprimo en pantalla el resultado de la suma */
    printf("Sumatoria = %d\n", sum);

	return 0;
}
