#include "functions.h"
#include <cv.h>
#include <highgui.h>

int main()
{
    IplImage *img = NULL;

    show_gray(img);
    show_negative(img);

    cvWaitKey(0);
    
    cvDestroyAllWindows();

    return 0;
}