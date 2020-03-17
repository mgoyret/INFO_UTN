/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 20 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#include "functions.h"

int main()
{
    IplImage *img = NULL;

    show_gray(img);
    show_negative(img);

    cvWaitKey(0);
    
    cvDestroyAllWindows();

    return 0;
}