/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 3, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include <stdio.h>
#define EXITO 0
#define ERROR -1

/* 1. Declaración de la función "calculo". También se le conoce como "prototipo" */
int calculo(float operadorA, float operadorB, float* resultado, char operacion);