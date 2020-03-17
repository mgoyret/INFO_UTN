#include <opencv2/core/core_c.h>
#include <opencv2/core/types_c.h>
#include <opencv2/highgui/highgui_c.h>

#include <string.h>
#include <stdio.h>

#define BOTON0  "data/BOTON0.png"
#define BOTON1  "data/BOTON1.png"
#define BOTON2  "data/BOTON2.png"
#define BOTON3  "data/BOTON3.png"

#define PLAY 1
#define PAUSA 2
#define STOP 3

int tecla = 0;

void myCallback(int event, int x, int y, int flags, void *data);

int main()
{
	IplImage *img = NULL;
	char flag = PAUSA;


	img = cvLoadImage(BOTON0, CV_LOAD_IMAGE_COLOR);
	if(img==NULL)
	{
		printf("No se pudo cargar la interfaz frafica\n");
	}
	else
	{
		printf("Imagen cargada\n");
		cvNamedWindow("ventana", CV_WINDOW_AUTOSIZE);
		cvSetMouseCallback("ventana", myCallback, (void *) img);
		cvShowImage("ventana", img);
	}
		do {
			flag = (char)cvWaitKey(2);
			if (flag == PLAY) 
			{
				img = cvLoadImage(BOTON0, CV_LOAD_IMAGE_COLOR);
				cvShowImage("ventana", img);
			}
			if (tecla == PLAY)
				printf("TECLA: PLAY\n");
				else if (tecla == PAUSA)
					printf("TECLA: PAUSA\n");
					else if(tecla == STOP)
					printf("TECLA: STOP\n");

		}
		while(tecla != STOP);
		printf("Chau\n");

	cvReleaseImage(&img);
	cvDestroyAllWindows();

    return 0;
}

void myCallback(int event, int x, int y, int flags, void *data)
{
	char nombre[512];

	printf("Posición x del mouse: %d, de y: %d\n", x, y);

	switch(event)
	{
		case CV_EVENT_LBUTTONUP:
			if ((x>70) && (x<175))
			{
				if ((y>90)&&(y<171)){  
					strcpy(nombre,BOTON1);
					tecla = PLAY;
				}
				else if ((y>245)&&(y<339)){ 
					 strcpy(nombre,BOTON2);
					 tecla = PAUSA;
				}
				else if( (y>405)&&(y<505)){
					 strcpy(nombre,BOTON3);
					 tecla = STOP;
				}
				
			}
			data = cvLoadImage(nombre, CV_LOAD_IMAGE_COLOR);
			cvShowImage("ventana", data);
		break;
	}
}
