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
    unsigned long res;
    /*  Solicito un número por consola */
    printf("Ingrese un entero positivo\n");
    scanf("%u", &numero);
    //if(numero >= 0)
    //{
        /*  Invoco a la función "factorial", pasándole "numero" como argumento.
            Almaceno el valor que retorna la función en la variable "res" */   
            res = factorial(numero);

        /*  Imprimo en pantalla el resultado de la suma */
            printf("El factorial de %u es %lu\n", numero, res);
    //}
    //else
    //{
    //    printf("numero negativo\n");
    //}
    


    
    
    return 0;
}