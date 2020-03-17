#include <stdio.h>
#include <stdlib.h>
#include </usr/include/opencv/cv.h>
#include </usr/include/opencv/highgui.h>

#define EXITO 1
#define ERROR -1

#define ESC_KEY 27

int main()
{
    IplImage *frame = NULL;
    CvCapture *video = NULL;
    double fps = 0;
    int exit = EXITO;

    video = cvCreateFileCapture("sample.flv");
    if(video != NULL)
    {
        fps = cvGetCaptureProperty(video, CV_CAP_PROP_FPS);
        if (fps == 0)
        {
            fps = 25;
        }
    	printf("Cuadros por segundo: %f\n", fps);

        cvNamedWindow("ventana", CV_WINDOW_AUTOSIZE);
            cvMoveWindow("ventana", 100, 100);

        do
        {
            frame = cvQueryFrame(video);
            cvShowImage("ventana", frame);
                                    /* wait() devuelve el valor ascii de tecla presionada. Viendo ese numero en binario, a veces se agregan numeros delante del
                                        valor real del ascii de esa tecla. 0xFF es un hexadecimal fijo (11111111) que lo utilizamos como mascara al operar bit a bit
                                        con el valor devuelto por wait(), quedandonos solo con los ultimos 8 bits de este valor, que son los bits que contienen
                                        el valor real de la tecla ingresada */
        } while ((frame != NULL) && ((cvWaitKey((int)(1000/fps)) & 0xFF) != ESC_KEY));
        
        cvDestroyAllWindows();
        cvReleaseCapture(&video);
    }
    else
    {
        printf("Error en funcion cvCreateFileCapture\n");
        exit = ERROR;
    }
    
    return exit;
}