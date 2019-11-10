#include "../../inc/functions.h"

void show_image(char* img_name)
{
    IplImage *img = NULL;

    /* 1. Cargo imagen */
    img = cvLoadImage(img_name, CV_LOAD_IMAGE_COLOR);
    /* 2. Abro ventana */
    cvNamedWindow("gray", CV_WINDOW_AUTOSIZE);
    /* 3. Acomodo ventana */
    cvMoveWindow("gray", 100, 100);
    /* 4. Envio imagen a ventana */
    cvShowImage("gray", img);

	cvWaitKey(0);

    cvReleaseImage(&img);
	cvDestroyAllWindows();
}