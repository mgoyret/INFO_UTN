/**
*	\file broadcast_client.c
*	\brief Cliente
*	\author Andres Demski (andresdemski@gmail.com
*	\date 2015.10.12
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

#define MAXBUFFER 1024

int main(void) 
{

	char buffer[MAXBUFFER];
	int socketCliente;
	struct sockaddr_in datosServer;
	int enviados;
	int fdmax =0, cant = 0;
	char *IP = "127.0.0.1";  // IP del servidor
	int PUERTO = 1301;		// Puerto

	// Variables para el select 
	fd_set master;                     
	fd_set readset;                 

	// Creo el socket
	socketCliente = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP) ;


	// Lleno la estructura con la info del server
	datosServer.sin_family = AF_INET;
	datosServer.sin_addr.s_addr = inet_addr(IP);
	datosServer.sin_port = htons(PUERTO);
	memset(datosServer.sin_zero,0,8);

	// Me conecto al server
	
	if (connect(socketCliente, (struct sockaddr *) &datosServer , sizeof(struct sockaddr)) != 0)
	{
		perror ("Error en el connect");
		return 0;
	}

	printf("Conectado\nPara desconectarse escriba \"-salir\"\n");

	// Inicializo el select
	FD_ZERO(&master);  
	FD_ZERO(&readset);
	FD_SET(socketCliente,&master); 
	FD_SET(0,&master);

	fdmax = socketCliente;

	do
	{
		readset = master;
		if(select(fdmax+1,&readset, NULL, NULL, NULL)== -1)
		{
			perror("Error en select");
			return(-1);
		}
		if (FD_ISSET(0,&readset))  // Si se escribio algo
		{
			gets(buffer);  // Obtengo linea
			if (!strcmp(buffer,"-salir")) // Escibio salir?
			{
				close(socketCliente);
				return 0;
			}
			enviados = send(socketCliente, buffer, strlen(buffer),MSG_CONFIRM); // Envio lo escrito
			if (enviados<0)
			{
				perror("Error servidor");
				break;
			}
		}
		if (FD_ISSET(socketCliente,&readset))  // Recibi algo?
		{
			cant = recvfrom(socketCliente, buffer, MAXBUFFER, 0, NULL, 0);
			if (cant < 1)
			{
				perror("Error servidor");
				break;
			}
			buffer[cant] = 0;
			printf ("Recibido: %s\n",buffer);
		}

	}while(1);
	close(socketCliente);
	printf("Desconectado\n");
	return 0;
}
