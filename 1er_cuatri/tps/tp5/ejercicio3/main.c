/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 3, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */
#include "functions.h"
int main()
{
    float operadorA, operadorB;
    char operacion;
    float resultado;
    int validez;

    /* 1. Solicito operacion por consola */
    printf("Ingrese operacion\n");
    scanf("%f %c %f", &operadorA, &operacion, &operadorB);

    /* 2. Invoco a la función "calculo", pasándole "operadorA", "operadorB", "&resultado" y "operacion" como argumentos.
        Almaceno el valor que retorna la función en la variable "validez", que retornara ERROR, o EXITO segun corresponda */
    validez = calculo(operadorA, operadorB, &resultado, operacion);

    if(validez==ERROR)
    {
        printf("Dividendo no puede ser '0'\n");
        printf("\n%d\n", validez);
    }
    /* 3. Si pudo realizarce el calculo, imprimo en pantalla la operacion */
    else
    {
        printf("\n%.3f %c %.3f = %.3f\n", operadorA, operacion, operadorB, resultado);
        printf("\n%d\n", validez);
    }
    
    return 0;
}