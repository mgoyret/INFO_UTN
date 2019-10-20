/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 20, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include <cv.h>
#include <highgui.h>

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/* 1. Declaración de la función "show_gray". También se le conoce como "prototipo" */
void show_gray(IplImage *img);

/* 2. Declaración de la función "show_negative". También se le conoce como "prototipo" */
void show_negative(IplImage *img);

#endif /* FUNCTIONS_H_ */