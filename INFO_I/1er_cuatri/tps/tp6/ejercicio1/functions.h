
/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Jun 10, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <math.h>

#define MAX 40

/* 1. Declaración de la función "string_largo". También se le conoce como "prototipo" */
int string_largo(const char* string); 

/* 2. Declaración de la función "string_comparar". También se le conoce como "prototipo" */
int string_comparar(const char* string1, const char* string2); 

/* 3. Declaración de la función "string_copiar". También se le conoce como "prototipo" */
void string_copiar(char* string_destino, const char* string_origen); 

/* 4. Declaración de la función "string_concatenar". También se le conoce como "prototipo" */
void string_concatenar(char* string_destino, const char* string_origen); 

/* 5. Declaración de la función "string_mayus". También se le conoce como "prototipo" */
void string_mayus(char* string); 

/* 6. Declaración de la función "string_minus". También se le conoce como "prototipo" */
void string_minus(char* string); 

/* 7. Declaración de la función "string_a_float". También se le conoce como "prototipo" */
float string_a_float(const char* string);