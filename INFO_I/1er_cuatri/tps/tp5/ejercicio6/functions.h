/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 6, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include <stdio.h>
#define EXITO 0
#define ERROR -1

/* 1. Declaración de la función "bubble_sort". También se le conoce como "prototipo" */
void bubble_sort(float* vector, unsigned int largo);
/* 2. Declaración de la función "estadisticas_vector". También se le conoce como "prototipo" */
int estadisticas_vector(float vector[], unsigned int largo, float* resultado, int caracteristica);
/* 3. Declaración de la función "printar". También se le conoce como "prototipo" */
void printar(float vector[], unsigned int largo);