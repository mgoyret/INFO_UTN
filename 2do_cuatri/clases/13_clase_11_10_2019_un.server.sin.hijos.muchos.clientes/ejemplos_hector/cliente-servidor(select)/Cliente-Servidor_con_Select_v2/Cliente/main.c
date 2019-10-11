/**
*	\file main.c
*	\fn int main(void)
*	\brief Función principal del cliente
*	\author Pose, Fernando Ezequiel. (Fernandoepose@gmail.com)
*	\date 2015.05.05  (última revisión: 2015.05.06)
*	\return Retorna 0
*	\version 1.3.1
*/

//--------------
//-- Includes --
//--------------

#include "conexion.h"

#define MAX_NOM 50
#define MAX_REP 50

int main(int cant, char ** param){

	int sockfd_cliente;
	int nBytes;
	char nombre[MAX_NOM];
	char respuesta[MAX_REP];
	int sigo = 1;

	system("clear"); 

	printf("*****************************************************\n");
	printf("*						    *\n");
	printf("*      .:Ejemplo - Clente/Servidor con select:.	    *\n");
	printf("*					CLIENTE	    *\n");
	printf("*****************************************************\n");

	sockfd_cliente = login();

	nBytes = recv(sockfd_cliente,respuesta,sizeof(respuesta),0);
	if(nBytes<=0){
		puts("Error en recv\r\n");
		return(-1);
	}

	printf("Respuesta del servidor: %s\r\n",respuesta);

	while(sigo) {
		printf("Ingrese una palabra a transmitir o /salir (minusculas) para cerrar la aplicacion: \r\n"); 
		gets_s(nombre,MAX_NOM);

		if(!strcmp(nombre,"/salir")){
			puts("\r\nCliente desconectado del servidor.\r\n");
			sigo = 0;
			nBytes = send(sockfd_cliente,nombre,MAX_NOM,0);
			sleep(5);
			close(sockfd_cliente);
		}
		else{
			nBytes = send(sockfd_cliente,nombre,MAX_NOM,0);
		}
    	}

	return(0);
}
