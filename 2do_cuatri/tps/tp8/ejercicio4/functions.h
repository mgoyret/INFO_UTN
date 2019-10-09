/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 26, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <stdio.h>
#include <string.h>

#define TAM 100
typedef enum EXIT
{
    ERROR = -1,
    EXITO
}EXIT;

//int escribir_linea(FILE *fp, const char *linea);
int leer_linea(FILE *fp, char *linea);

int escribir_linea(FILE* fp, const char* line2);