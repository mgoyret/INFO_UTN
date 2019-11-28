/**
 *	\file servidor.c
 *	\brief funcion main del servidor. Diapositivas de clase.
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

#define MAXCONEXIONES 	10
#define MAXBUFFER		10000

#define SEPARATOR   printf("//////////////////////////////////////////////////////////////////////////////\n");
#define SPACE       printf("\n\n");
#define DEFAULT     printf("\033[00m");
#define SET_RED     printf("\033[31m");
#define SET_GREEN   printf("\033[32m");
#define HIGHLIGHT   printf("\033[07m");	

void send_image(int cliente);

int main(int argc, char** argv)
{

	int listener; //Socket que recibe las conexiones
	int cliente; //Socket que se me conecto
	unsigned int addrlen = sizeof(struct sockaddr_in); //Tamano necesario para accept()
	struct sockaddr_in datosServer, datosCliente; //Datos del cliente y servidor
	char buffer[MAXBUFFER]; //Buffer para recibir mensajes
  	int clienteConectado; //Flag 
  	int sizeMensaje; //Tamano del mensaje recibido
  	int on = 1;//Necesario para setsockop
	char puerto[10], auxIp[25];
	int port;


	if	(argc == 2)
	{
		strcpy(puerto, argv[1]);
		port = atoi(puerto);

		// Creo el socket
		listener = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP) ;

		// Lleno la estructura con la info del server
		datosServer.sin_family = AF_INET;
		datosServer.sin_addr.s_addr = INADDR_ANY; //Localhost
		datosServer.sin_port = htons(port);
		memset(datosServer.sin_zero, 0, 8);

		/*Si el server se cierra bruscamente queda ocupado el puerto hasta que
			reinicies y es molesto, con la siguiente linea se soluciona */
		setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

		// Enlazo el socket a la ip:puerto (contenida en la estructura que llene)
		bind(listener, (struct sockaddr*)&datosServer, (socklen_t)sizeof(datosServer));

		// Pongo el socket a la escucha ("enciendo" el server)
		listen(listener,MAXCONEXIONES);

		SPACE
		SEPARATOR
		HIGHLIGHT
		printf("Server conectado\n\n");
		DEFAULT
		printf("Puerto:\t%d\nIp:\t\t%s\n", port, auxIp);
		SPACE
		SEPARATOR
		SPACE

		while(1)
		{
			printf("Esperando conexiones\n\n");

			//Acepto una conexion
			cliente = accept(listener, (struct sockaddr *)&datosCliente, &addrlen);
			clienteConectado = 1;

			//Muestro la IP del cliente, la obtengo de datosCliente
			strcpy(auxIp, inet_ntoa((struct in_addr)datosCliente.sin_addr));
			HIGHLIGHT
			SET_GREEN
			printf("Nueva conexion desde la IP: %s\n", auxIp);
			DEFAULT

			//Envio saludo al cliente
			strcpy(buffer, "Bienvenido!!");
			send(cliente, buffer, strlen(buffer), 0);
			memset(buffer, '\0', MAXBUFFER);

			while(clienteConectado)
			{
				printf("Esperando mensaje\n");

				//Recibo mensaje del cliente
				sizeMensaje = recv(cliente, buffer, MAXBUFFER, 0);

				if(sizeMensaje > 0)
				{
					if (strcmp(buffer, "/imagen") == 0)
					{
						printf("%s: Imagen solicitada\n", auxIp);							
						send_image(cliente);
					}
					else
					{
						//imprimo mensaje
						buffer[sizeMensaje] = '\0'; //Por las dudas pongo el \0, no me acuerdo si ven�a ya
						printf("%s: '%s'\n", auxIp, buffer);	
					}
				}
				else
				{
					clienteConectado = 0;
				}
			}
			HIGHLIGHT
			printf("Se desconecto el cliente\n");
			DEFAULT

			//Cierro el socket del cliente
			close(cliente);
		}
	}
	else
	{
		SET_RED
		printf("Error de parametros.\n./<ejecutable> <numero de puerto TCP>\n");
		DEFAULT
	}

	return 0;
}




void send_image(int cliente)
{
	char buffer[MAXBUFFER];
	FILE* fp;

	fp = fopen("lenna.png", "r");
	if (fp != NULL)
	{	
		while (!feof(fp))
		{
			fread(buffer, sizeof(char), MAXBUFFER, fp);
			send(cliente, buffer, MAXBUFFER, 0);
		}
		send(cliente, "FIN", sizeof("FIN"), 0);
		printf("Imagen enviada\n");
		fclose(fp);
	}
	else
	{
		HIGHLIGHT
		SET_RED
		printf("Error al cargar imagen");
		DEFAULT
	}
}
