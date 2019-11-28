/**
 *	\file cliente.c
 *	\brief funcion main del cliente. Diapositivas de clase.
 *	\author Fernando Pose (fernandoepose@gmail.com)
 *	\date 2014.11.24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sockets
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

//opencv
#include </usr/include/opencv/cv.h>
#include </usr/include/opencv/highgui.h>

#define MAXBUFFER 	10000
#define TEMP_IMG	"temp_img"

#define SEPARATOR   printf("//////////////////////////////////////////////////////////////////////////////\n");
#define SPACE       printf("\n\n");
#define DEFAULT     printf("\033[00m");
#define SET_RED     printf("\033[31m");
#define SET_GREEN   printf("\033[32m");
#define HIGHLIGHT   printf("\033[07m");

void show_image(char* img_name);

int main(int argc, char** argv)
{	
	char buffer[MAXBUFFER];
	int socketCliente;
	struct sockaddr_in datosServer;
	int enviados;
	char puerto[10];
	int ip, port;
	FILE* fp;
	int i = 0;

	if (argc == 3)
	{
		// Creo el socket
		socketCliente = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

		ip = inet_addr(argv[1]);
		strcpy(puerto, argv[2]);
		port = atoi(puerto);

		// Lleno la estructura con la info del server
		datosServer.sin_family = AF_INET;
		datosServer.sin_addr.s_addr = ip;
		datosServer.sin_port = htons(port);
		memset(datosServer.sin_zero,0,8);


		if (connect(socketCliente, (struct sockaddr*)&datosServer , sizeof(struct sockaddr)) != -1)
		{
			//Me conecto al server
			SEPARATOR
			SPACE
			HIGHLIGHT
			SET_GREEN
			printf("Conexion establecida\n");
			DEFAULT
			printf("Server\nip:\t%s\nPuerto:\t%d\n\n", argv[1], port);
			printf("Para desconectarse escriba \"salir\"\n");
			SEPARATOR
			SPACE

			//Recibo mensaje del server
			memset(buffer, '\0', MAXBUFFER);
			recv(socketCliente, buffer, MAXBUFFER, 0);
			printf("Server dice: '%s'\n", buffer);
			memset(buffer, '\0', MAXBUFFER);

			while(1)
			{	
				printf("Escriba mensaje a enviar: ");
				fgets(buffer, MAXBUFFER, stdin);
				buffer[strlen(buffer)-1] = '\0'; //fgets almacena el "\n"

				if(strcmp(buffer, "salir") == 0) break;
				
				if (strcmp(buffer, "/imagen") == 0)
				{
					send(socketCliente, buffer, strlen(buffer), 0);
					memset(buffer, '\0', MAXBUFFER);
					printf("Imagen solicitada\n");

					fp = fopen(TEMP_IMG, "w");
					if (fp != NULL)
					{
						printf("Creando imagen temporal\n");
						while (1)
						{
							/* Antes de cada recv vacio el buffer para que luego solo tenga lo recivido, y no haya basura */
							memset(buffer, '\0', MAXBUFFER);
							recv(socketCliente, buffer, MAXBUFFER, 0);
							if (strcmp(buffer, "FIN") != 0) //no esta recibiendo el ultimo recv
							{
								fwrite(buffer, sizeof(char), MAXBUFFER, fp);
							}
							else
							{
								printf("Imagen recibida\n");
								break;
							}
						}
						show_image(TEMP_IMG);
						remove(TEMP_IMG);
						fclose(fp);
					}
					else
					{
						printf("Error en funcion fopen\n");
					}
				}
				else
				{
					enviados = send(socketCliente, buffer, strlen(buffer), 0);
					
					if(enviados > 0)
					{
						printf("Enviado\n");
					}
					else
					{
						SET_RED
						printf("Error servidor\n");
						DEFAULT
						break;
					}	
				}
			}
			
			close(socketCliente);
			printf("Desconectado\n");
		}
		else
		{
			HIGHLIGHT
			SET_RED
			printf("Error al conectar con el servidor\n");
			DEFAULT
		}
	}
	else
	{
		SET_RED
		printf("Error de parametros.\n./<ejecutable> <direccion ip del servidor> <numero de puerto TCP>\n");
		DEFAULT
	}

	return 0;
}

void show_image(char* img_name)
{
    IplImage *img = NULL;

	printf("Se mostrara la imagen en breve\n");

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
