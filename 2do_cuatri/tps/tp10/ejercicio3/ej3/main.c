#include <stdio.h>
#include <stdlib.h>
#include </usr/include/opencv/cv.h>
#include </usr/include/opencv/highgui.h>

int main()
{
    IplImage *img1 = NULL, *img2 = NULL;
    int i = 0, j = 0;
	CvSize size;
    CvScalar pixel;

    img1 =  cvLoadImage("lenna.png", CV_LOAD_IMAGE_COLOR);
    /* Tamano imvertido porque estara rotada */

	size = cvSize((*img1).height, (*img1).width);

    img2 = cvCreateImage(size, (*img1).depth, (*img1).nChannels);

    cvNamedWindow("original", CV_WINDOW_AUTOSIZE);
        cvMoveWindow("original", 100, 100);
            cvShowImage("original", img1);

    for(i = 0; i < (*img1).height; i++)
    {
        for(j = 0; j < (*img1).width; j++)
        {
            pixel = cvGet2D(img1, i, j);
            cvSet2D(img2, (*img1).width - 1 - j, i, pixel);
        }
    }

    cvNamedWindow("rotada", CV_WINDOW_AUTOSIZE);
        cvMoveWindow("rotada", 700, 100);
            cvShowImage("rotada", img2);

    cvWaitKey(0);

    cvDestroyAllWindows();
    cvReleaseImage(&img1);
    
     
    return 0;
}