/**
 *	\file main.c
 *	\fn int main(void)
 *	\brief Función principal del servidor.
 *	\author Pose, Fernando Ezequiel. (Fernandoepose@gmail.com)
 *	\date 2015.05.05 (última revisión 2015.05.06)
 *	\version 1.0.2
 *	\return Retorna 0.
 */

//--------------
//-- Includes --
//--------------

#include <signal.h>
#include "conexion.h"

//---------------
//--  Defines  --
//---------------

#define MAX_DATOS 50

int main(void){

	int listener;                  	    	//Socket que recibe las conexiones.
	int cliente;                           //cliente que se conecta.
    	struct sockaddr_in datosServer;       //Datos del servidor.
    	struct sockaddr_in datosCliente;     //Datos del cliente.
    	fd_set master;                      //Conjunbto maestro de descriptores de fichero.
	fd_set readset;                    //Conjunto temporal de descriptores de fichero para select()
    	int fdmax;                        //Número mayor descriptor de fichero.
    	int i;                           //Para el for del select.
	int on = 1;                     //Necesario para setsockopt.
	unsigned int addrlen;          //Necesito para el accept.
	struct datos configuracion;   //IP y PUERTO del servidor.
	int nbytes;		     //Respuesta del servido
	char respuesta[MAX_DATOS];  //Respuesta del servidor como que el cliente se conecto.
	char recibido[MAX_DATOS];  //Mensaje enviado por el cliente y recibido en el servidor.


	printf("*********************************************************\n");
	printf("*						  	*\n");
	printf("*      .:Ejemplo - Cliente/Servidor con select:.	*\n");
	printf("*					SERVIDOR        *\n");
	printf("*********************************************************\n");

	//Si recibo una señal señal SIGPIPE la ignóro.
	signal(SIGPIPE, SIG_IGN);

	//Cargo ip y puerto en las variables.

	datos_server(&configuracion);

	//Creo el socket que escucha las conexiones.

	listener = socket(AF_INET,SOCK_STREAM,0);
	if(listener == -1){
		printf("Error en listener");
		return(-1);
	}

	//Lleno la estructura con la información del servidor.
	printf("Datos del server\nip:\"%s\"\npuerto:\"%d\"\n",configuracion.ip, configuracion.puerto);
	datosServer.sin_family = AF_INET;
	datosServer.sin_addr.s_addr = inet_addr(configuracion.ip);
	datosServer.sin_port = htons(configuracion.puerto);
	memset(datosServer.sin_zero,0,8);

	//Si el server se cierra bruscamente queda ocupado el puerto y se debe reiniciar el servidor, con setsockp se soluciona.
	if(setsockopt(listener, SOL_SOCKET, SO_REUSEADDR,&on, sizeof(int)) == -1){
		printf("Error en setsockopt");
		return(-1);
	}

	//Enlazo el socket a la ip:puerto contenida en la estructura datosServer.
	if(bind(listener, (struct sockaddr*) &datosServer, sizeof datosServer) == -1){ 
		printf("Error en bind");
		return(-1);
	}

	//Pongo el server a la escucha (enciendo el servidor)
	if((listen(listener,MAX_CONEXIONES)) == -1){
		printf("Error en listen");
		return(-1);
	}

	//Aviso que el servidor está conectado.
	puts("Servidor conectado");

	FD_ZERO(&master);
	FD_ZERO(&readset);

	//Añado el listener al set maestro.
	FD_SET(listener,&master); 

	//Mayor descriptor de fichero como es único es el máximo.
	fdmax = listener;

	//Bucle principal.
	while(1){

		readset = master;

		if(select(fdmax+1,&readset, NULL, NULL, NULL)== -1){
			printf("Error en select");
			return(-1);
		}

		//Exploro conexiones existentes en busca de datos que leer.

		for(i = 0; i <= fdmax; i++){
			if(FD_ISSET(i,&readset)){
				if(i == listener){     //Tengo conexión para aceptar.
					addrlen = sizeof(datosCliente);

					cliente = accept(listener, (struct sockaddr*) &datosCliente, &addrlen);  //TODO Hasta acá es el login de parte del cliente.
					if(cliente == -1){
						printf("Error en accept");
					}
					FD_SET(cliente, &master); //Añado la nueva conexion al conjunto maestro.
					if(cliente > fdmax){     //actualizo el máximo fichero.
						fdmax = cliente;
					}

					printf("La siguiente IP se ha conectado IP: %s\n",inet_ntoa((struct in_addr)datosCliente.sin_addr));
					strcpy(respuesta,"Conexion aceptada");
					send(cliente, &respuesta, sizeof(respuesta), 0);
				}
				else {
					nbytes = recibir(i,recibido, MAX_DATOS,&readset);
					if (strcmp(recibido,"/salir")) {
						printf("Me enviaron: %s (%d bytes)\n", recibido, nbytes);
					}
					else {
						FD_CLR(i, &master);
					}
				}
			}
		}
	}
	return(0);
}



