/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 17, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#ifndef functions_H_
#define functions_H_

/* 1. Declaración de la función "recive_hijo". También se le conoce como "prototipo" */
void recive_hijo(int a);

/* 2. Declaración de la función "recive_padre". También se le conoce como "prototipo" */
void recive_padre(int a);

#endif /* FUNCTIONS_H_ */