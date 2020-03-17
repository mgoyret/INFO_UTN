/**
 * \file            main.c
 * \brief           39. Imágenes - Ejemplo 1 - OpenCV - Abrir imagen
 * \author          Javier Balloffet
 * \date            Aug 24, 2019
 * \details         Usar makefile para compilar, linkear y ejecutar
 */

#include <cv.h>
#include <highgui.h>

int main() {
	/* 1. Declaro el descriptor para la imágen */
    IplImage* img = NULL;

    /* 2. Abro la imágen en modo color */
    img = cvLoadImage("lenna.png");

    printf("Ancho:\t%d\nAlto:\t%d\n", img->width, img->height);

    /* . Libero los recursos (memoria) */
    cvReleaseImage(&img);

    return 0;
}
