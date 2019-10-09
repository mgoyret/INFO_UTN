#include "functions.h"
#include <cv.h>
#include <highgui.h>

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