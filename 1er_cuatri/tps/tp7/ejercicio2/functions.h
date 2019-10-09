/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 21, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define ES_LETRA (((letra >= 'A') && (letra <= 'Z')) || ((letra >= 'a') && (letra <= 'z')))

/* 1. Declaración de la función "printstr". También se le conoce como "prototipo" */
void printstr(char* pal, int largo);