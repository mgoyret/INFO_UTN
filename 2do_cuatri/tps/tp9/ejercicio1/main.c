/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 31, 2019
 * \details         Usar MakeFile para compilar, linkear y ejecutar
 */

#include "functions.h"
#include <stdio.h>
#include <math.h>

int main()
{
    /* 1. 'complejo' es un tipo de dato 'struct' definido en el header 'funciones.h' */
    complejo x, y, res1;
    double res2 = 0;

    SPACE

    /* 2. Solicito ingresar componentes del primer numero imaginario, e imprimo su conjugado, modulo y fase en grados y en radianes */
    printf("Cargando primer numero...\n\n\a");
    printf("Parte real:\t\t");
    scanf("%lf", &a);

    printf("Parte imaginaria:\t");
    scanf("%lf", &b);

    SPACE

    res1 = complejo_conjugado(x);
    printf("Conjugado:\t(%.3lf, %.3lf)\n", res1.real, res1.imag);

    res2 = complejo_modulo(x);
    printf("Modulo:\t\t%.3lf\n", res2);

    res2 = complejo_fase_grados(x);
    printf("Fase(g):\t%.3lf\n", res2);

    res2 = complejo_fase_radianes(x);
    printf("Fase(r):\t%.3lf\n", res2);
    
    SPACE

    /* 3. Solicito ingresar componentes del segundo numero imaginario, e imprimo la suma, resta multiplicacion y division del primer numero con respecto al segundo */
    printf("Cargando segundo numero...\n\n\a");
    printf("Parte real:\t\t");
    scanf("%lf", &c);
    printf("Parte imaginaria:\t");
    scanf("%lf", &d);

    SPACE

    res1 = complejo_suma(x, y);
    printf("Suma:\t\t(%.3lf, %.3lf)\n", res1.real, res1.imag);

    res1 = complejo_resta(x, y);
    printf("Resta:\t\t(%.3lf, %.3lf)\n", res1.real, res1.imag);

    res1 = complejo_multiplicacion(x, y);
    printf("Producto:\t(%.3lf, %.3lf)\n", res1.real, res1.imag);

    res1 = complejo_division(x, y);
    printf("Cociente:\t(%.3lf, %.3lf)\n", res1.real, res1.imag);

    SPACE

    return 0;
}