/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 12, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "functions.h"

int main ()
{
    char a[40];
    char sust = 0;
    int p = 0;

    /* 1. Solicito string (palabra) por consola */
    printf("Ingrese palabra:\n");
    fgets(a, 20, stdin);

    /* 2. Invoco a la función "clean", pasándole "a" como argumento. */
    clean(&a[0]);

    printf("Ingrese letra a reemplazar:\n");
    scanf("%c", &sust);

    /* 3. Invoco a la función "reemplazar", pasándole "a" como argumento.
        Almaceno el valor que retorna la función en la variable "p" */
    p = reemplazar(&a[0], sust);

    printf("La nueva palabra es '%s', y la letra '%c' se reemplazo %d veces.\n", a, sust, p);
    
    return 0;
}