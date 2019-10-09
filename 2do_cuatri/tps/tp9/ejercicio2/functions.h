/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 31, 2019
 * \details         Usar MakeFile para compilar, linkear y ejecutar
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct string
{
    char spal[26];
}string;

#define TAM 26
#define LETRA       ((64<aux[i] && aux[i]<91) || (96<aux[i] && aux[i]<123)/* || aux[i] == 32 //espacio */)

#define HIGHLIGHT    printf("\033[07m\n");
#define DEFAULT      printf("\033[00m\n");
#define SPACE        printf("\n\n");

/* 1. Declaración de la función "letra". */
int letra(char* aux);

/* 2. Declaración de la función "fin". */
int fin(const char*);

/* 3. Declaración de la función "stolower". */
void stolower(char*);

/* 4. Declaración de la función "ordenar". */
void ordenar(string*, int);