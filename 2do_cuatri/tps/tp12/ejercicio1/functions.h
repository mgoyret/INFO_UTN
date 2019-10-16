/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 16, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* 1. Declaración de la función "ok_process". También se le conoce como "prototipo" */
void ok_process();

/* 2. Declaración de la función "zombie". También se le conoce como "prototipo" */
void zombie();

/* 3. Declaración de la función "orphan". También se le conoce como "prototipo" */
void orphan();

#endif /* FUNCTIONS_H_ */