/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 17, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#ifndef functions_H_
#define functions_H_

#define ERROR -1
#define EXITO 1

/* 1. Declaración de la función "sc_handler". También se le conoce como "prototipo" */
void sc_handler();

/* 2. Declaración de la función "son_creator". También se le conoce como "prototipo" */
int son_creator(int hijos_pedidos);

#endif /* FUNCTIONS_H_ */