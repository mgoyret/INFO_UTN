/**
 *	\file servidor.c
 *	\brief Servidor multiusuario - Chat grupal
 *	\author Andres Demski (andresdemski@gmail.com)
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


#define MAXCONEXIONES 30
#define MAXBUFFER 1024

int main(void) {

		int listener;
		int cliente; 
		int fdmax;
		char *IP = "127.0.0.1";  // IP DEL SERVIDOR
		int PUERTO = 1301;
		
		int addrlen=sizeof(struct sockaddr_in); 
	  	struct sockaddr_in datosServer, datosCliente; 
	  	
	  	char buffer[MAXBUFFER]; 
	  	int cantidadRec;
	  	
	  	int sizeMensaje;
	  	int on=1;
	  	
	  	int i=0,j=0;
	  	
	  	// Variables para el select
		fd_set master;                     
		fd_set readset;              
                 
		listener = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP) ;

		datosServer.sin_family = AF_INET;
		datosServer.sin_addr.s_addr = inet_addr(IP); 
		datosServer.sin_port = htons(PUERTO);
		memset(datosServer.sin_zero,0,8);

		setsockopt(listener, SOL_SOCKET,  SO_KEEPALIVE, &on, sizeof(on));

		if (bind(listener, (struct sockaddr*) &datosServer, sizeof datosServer)<0)
		{
			perror("Error en el bind:");
			return -1;
		}
		
		if (listen(listener,MAXCONEXIONES)<0)
		{
			perror("Error en el Listen:");
			return -1;
		}
		
		printf("Server conectado \n");

		FD_ZERO(&master);  
		FD_ZERO(&readset);
		FD_SET(listener,&master);  // Agrego el listener a la bolsa del select
		FD_SET(0,&master);   // Agrego el stdin a la bolsa del select
		fdmax = listener;  
                
		while(1)
		{
			readset = master;
			
			if(select(fdmax+1,&readset, NULL, NULL, NULL)== -1)
			{
				perror("Error en select");
				return(-1);
	        }
	        
	        for (i=0;i<=fdmax;i++)
	        {
	        	if(FD_ISSET(i,&readset))
	        	{
	        		if (i==0)  // Si se preciono enter
	        		{
	        			for (j=3;j<=fdmax;j++) close(j);  // Cierro files descriptors
						printf("Chau a todos y todas (?\n");
						return 0;
	        		}
	        		
			    	if (i== listener)  // Si el listener tiene algo nuevo
			    	{
			    		cliente = accept(listener, (struct sockaddr*) &datosCliente, &addrlen);  // Acepto al que se quiere conectar
						if(cliente > 0)
						{ 
							printf("Server: Se conecto un nuevo cliente. fd=%d\n",cliente);
							FD_SET(cliente , &master); // Lo agrego al select
							if(cliente > fdmax) fdmax = cliente; 
						}
						else
						{
							perror ("Error en accept:");
						}						
			    	}
			    	else  // Si se descanecto alguno o hay algun msj nuevo
			    	{
			    		cantidadRec = recvfrom(i, buffer, MAXBUFFER, 0, NULL, 0); // Intento leer
			    		if (cantidadRec<1)  // Se desconecto??
			    		{
			    			printf("Se desconecto fd=%d:\n",i);
			    			FD_CLR(i, &master);  
			    			close(i);
			    		}
			    		else if (cantidadRec>0) // MSJ NUEVO!!
			    		{
			    			buffer[cantidadRec]=0;
			    			printf ("Server: Mensaje recibido de fd %d: %s\n",i,buffer);
			    			for (j=3;j<=fdmax;j++) // Reenvio a todos!
			    			{
			    				if (j!=i && j!=listener) 
			    				{
			    					send(j, buffer, cantidadRec,0);			    					
			    				}
			    			}
			    		}
			    	}
			   	}
	        }
	    }
		return 0;



}
