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

#define PUERTO 1299
#define MAXCONEXIONES 10
#define MAXBUFFER 1024

int main(void) {

		int listener; //Socket que recibe las conexiones
		int cliente; //Socket que se me conect�
		int addrlen=sizeof(struct sockaddr_in); //Tama�o necesario para accept()
	  	struct sockaddr_in datosServer, datosCliente; //Datos del cliente y servidor
	  	char buffer[MAXBUFFER]; //Buffer para recibir mensajes
	  	int clienteConectado; //Flag 
	  	int sizeMensaje; //Tama�o del mensaje recibido
	  	int on=1;//Necesario para setsockop

	  	// Creo el socket
		listener = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP) ;

		// Lleno la estructura con la info del server
		datosServer.sin_family = AF_INET;
		datosServer.sin_addr.s_addr = INADDR_ANY; //Localhost
		datosServer.sin_port = htons(PUERTO);
		memset(datosServer.sin_zero,0,8);

		/*Si el server se cierra bruscamente queda ocupado el puerto hasta que
		reinicies y es molesto, con la siguiente linea se soluciona */
		setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

		// Enlazo el socket a la ip:puerto (contenida en la estructura que llen�)
		bind(listener, (struct sockaddr*) &datosServer, sizeof datosServer);

		// Pongo el socket a la escucha ("enciendo" el server)
		listen(listener,MAXCONEXIONES);

		printf("Server conectado \n");


		while(1){

			printf("Esperando conexiones\n");

			//Acepto una conexion
			cliente = accept(listener, &datosCliente, &addrlen);
			clienteConectado = 1;

			//Muestro la IP del cliente, la obtengo de datosCliente
			printf("Se conecto alguien desde la ip: %s\n", inet_ntoa((struct in_addr)datosCliente.sin_addr));

			while(clienteConectado){

				printf("Esperando mensaje\n");

				//Recibo mensaje del cliente
				sizeMensaje = recv(cliente, buffer, MAXBUFFER, 0);

				if(sizeMensaje>0){

					//imprimo mensaje
					buffer[sizeMensaje]='\0'; //Por las dudas pongo el \0, no me acuerdo si ven�a ya
					printf("Mensaje recibido: \"%s\"\n",buffer);

				}else clienteConectado = 0;


			}
			printf("Se desconecto el cliente\n");
			
			//Cierro el socket del cliente
			close(cliente);
		}

		return 0;



}