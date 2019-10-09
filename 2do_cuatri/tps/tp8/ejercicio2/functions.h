/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Aug 26, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define TAM 50
#define SEP " " "." "," "_" ";" ":" "\n"

/* 1. Declaración de la función "word_cnt". */
int word_cnt(FILE*, char*);
/* 2. Declaración de la función "total_cnt". */
int total_cnt(FILE*);
