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

#define MAXBUFFER 	1024
#define PUERTO		1299

int main(int argc, int* argv)
{	
	char buffer[MAXBUFFER];
	int socketCliente;
	struct sockaddr_in datosServer;
	int enviados;

	if (argc == 2)
	{
		// Creo el socket
		socketCliente = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);


		// Lleno la estructura con la info del server
		datosServer.sin_family = AF_INET;
		datosServer.sin_addr.s_addr = INADDR_ANY;
		datosServer.sin_port = htons(PUERTO);
		memset(datosServer.sin_zero,0,8);

		//Me conecto al server
		connect(socketCliente, (struct sockaddr*)&datosServer , sizeof(struct sockaddr));

		printf("Conectado\nPara desconectarse escriba \"salir\"\n");


		while(1)
		{	
			printf("Escriba mensaje a enviar: ");
			fgets(buffer,MAXBUFFER,stdin);
			buffer[strlen(buffer)-1] = '\0'; //fgets almacena el "\n"

			if(strcmp(buffer, "salir") == 0) break;
			
			enviados = send(socketCliente, buffer, strlen(buffer), 0);
			
			if(enviados > 0)
			{
				printf("Enviado\n");
			}
			else
			{
				printf("Error servidor\n");
				break;
			}

		}
		
		close(socketCliente);
		printf("Desconectado\n");
	}
	else
	{
		printf("Error de parametros.\n./<ejecutable> <numero de puerto TCP>\n");
	}

	return 0;
}
