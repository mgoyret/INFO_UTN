/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 20, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

/* 1. Definicion de la funcion "show_gray" */

/**
 * \fn      void show_gray(IplImage *img)
 * \brief   Muestra imagen en escala de grises.
 * \author  Marcos Goyret
 * \date    Oct 20, 2019
 * \param   img: Imagen a mostrar.
 */
    
void show_gray(IplImage *img)
{
    /* 1. Cargo imagen */
    img = cvLoadImage("lenna.png", CV_LOAD_IMAGE_GRAYSCALE);
    /* 2. Abro ventana */
    cvNamedWindow("gray", CV_WINDOW_AUTOSIZE);
    /* 3. Acomodo ventana */
    cvMoveWindow("gray", 100, 100);
    /* 4. Envio imagen a ventana */
    cvShowImage("gray", img);

    cvReleaseImage(&img);
}


/* 2. Definicion de la funcion "show_negative" */

/**
 * \fn      void show_negative(IplImage *img)
 * \brief   Muestra el negativo de una imagen.
 * \author  Marcos Goyret
 * \date    Oct 20, 2019
 * \param   img: Imagen a mostrar.
 */
    
void show_negative(IplImage *img)
{
    int row, column;
    CvScalar pixel;
    
    img = cvLoadImage("lenna.png", CV_LOAD_IMAGE_GRAYSCALE);

    /* Modifico los valores de cada pixel de la imagen para pasarla a negativo */
    for (row = 0; row < img->height; row++)
        for (column = 0; column < img->width; column++)
        {
            pixel = cvGet2D(img, row, column);
            pixel.val[0] = 255 - pixel.val[0];
            cvSet2D(img, row, column, pixel);        
        }
        
    cvNamedWindow("negative", CV_WINDOW_AUTOSIZE);
    cvMoveWindow("negative", 1000, 100);
    cvShowImage("negative", img);
    cvReleaseImage(&img);
}