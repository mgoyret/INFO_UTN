/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar 22, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 1. Defines para comodidad de indentacion */
#define TOTAL   98
#define MAX     30

/* 2. Prototipo de funcion area_check(). Chequea si la linea actual coincide con el area deseada */
int area_check(char *line, char *area);

/* 3. Prototipo de funcion set_line. Escribe una nueva linea en el nuevo arhcivo */
void set_line(char *line, FILE* fp2);

#endif /* FUNCTIONS_H_ */