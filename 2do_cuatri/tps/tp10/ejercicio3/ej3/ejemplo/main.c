#include <stdio.h>
#include <stdlib.h>
#include <cv.h>
#include <highgui.h>

int main ()
{
	IplImage* img = NULL;
	IplImage* img_rot = NULL;
	int i,j; 		
	CvScalar pixel;
	CvPoint punto;
	CvSize size_img_rot;

	
	//Cargamos la imagen
	img = cvLoadImage("lenna.png",CV_LOAD_IMAGE_COLOR);  //En escala de grises cada pixel pesa 1 byte (0-255)
	
	size_img_rot = cvSize((*img).height,(*img).width); //Dimensiones de la nueva imagen en blanco
		
	img_rot = cvCreateImage(size_img_rot, (*img).depth, (*img).nChannels); //Se crea la nueva imagen en blanco
	
		
	//Creamos una ventana y la posicionamos en pantalla
	cvNamedWindow("Original",CV_WINDOW_AUTOSIZE);
	 cvMoveWindow("Original",100,100);
	  cvShowImage("Original",img); 
		
	for(j=0;j<(*img).height;j++)	//Recorremos el largo y ancho de la imagen, pixel por pixel.
	{
	   for(i=0;i<(*img).width;i++)               
	   {
	      pixel = cvGet2D(img,i,j);
	      	      	      	      	   	
	   	cvSet2D(img_rot,((*img).width) - j - 1,i, pixel); // Pixel a pixel la imagen se rota 90 grados a izquierda	   	
	   }
	}

	//Creamos otra ventana y la posicionamos en pantalla  	
	cvNamedWindow("Rotada",CV_WINDOW_AUTOSIZE);
	 cvMoveWindow("Rotada",700,100);
        cvShowImage("Rotada",img_rot);			
			
	//Esperamos a pulsar una tecla bloqueante
	cvWaitKey(0);
	
	//Liberamos los recursos tomados
	cvDestroyAllWindows();
	cvReleaseImage(&img);

return 0;
}

