/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 4, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdio_ext.h>  //header utilizado para habilitar el uso de la funcion fpurge

#define EXITO 0
#define ERROR -1
#define LARGO 10

/* 1. Declaración de la función "calculo_vector". También se le conoce como "prototipo" */
int calculo_vector(float vector[], unsigned int largo, float num, char op);

/* 2. Declaración de la función "printar". También se le conoce como "prototipo" */
void printar(float vector[], unsigned int largo);