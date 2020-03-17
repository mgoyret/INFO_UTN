/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 17, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#ifndef functions_H_
#define functions_H_

#define TIEMPO_ALARMA 10

/* 1. Declaración de la función "handler". También se le conoce como "prototipo" */
void handler(int a);

/* 2. Declaración de la función "mi_alarma". También se le conoce como "prototipo" */
void mi_alarma(int a);

#endif /* FUNCTIONS_H_ */