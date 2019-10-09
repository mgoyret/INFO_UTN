/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 31, 2019
 * \details         Usar MakeFile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <math.h>

typedef struct complejo
{
    double real;
    double imag;
} complejo;

#define a x.real
#define b x.imag
#define c y.real
#define d y.imag

#define SPACE printf("\n\n");

/* 1. Declaración de la función "complejo_suma". */
complejo complejo_suma(const complejo x, const complejo y);

/* 2. Declaración de la función "complejo_resta". */
complejo complejo_resta(const complejo x, const complejo y);

/* 3. Declaración de la función "complejo_multiplicacion". */
complejo complejo_multiplicacion(const complejo x, const complejo y);

/* 4. Declaración de la función "complejo_division". */
complejo complejo_division(const complejo x, const complejo y);

/* 5. Declaración de la función "complejo_conjugado". */
complejo complejo_conjugado(const complejo x);

/* 6. Declaración de la función "complejo_modulo". */
double complejo_modulo(const complejo x);

/* 7. Declaración de la función "complejo_fase_grados". */
double complejo_fase_grados(const complejo x);

/* 8. Declaración de la función "complejo_fase_radianes". */
double complejo_fase_radianes(const complejo x);