/**
 * \file            servidor.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Nov 30, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

/*  
    Consigna
	Modificar el ejercicio 1 para que cada instancia de conexión se maneje mediante un proceso hijo,
	mientras que el proceso padre se encargará de recibir las conexiones entrantes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/wait.h>

//sockets
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define MAXCONEXIONES 	10
#define MAXBUFFER		10000

#define SEPARATOR   printf("//////////////////////////////////////////////////////////////////////////////\n");
#define SPACE       printf("\n\n");
#define DEFAULT     printf("\033[00m");
#define SET_RED     printf("\033[31m");
#define SET_GREEN   printf("\033[32m");
#define HIGHLIGHT   printf("\033[07m");	

int online_clients = 0;

void send_image(int client_socket_fd);

int child_process(int client_socket_fd, struct sockaddr_in datos_cliente);

void sc_handler();

int main(int argc, char** argv)
{

	int listener_socket_fd; //Socket que recibe las conexiones
	int client_socket_fd; //Socket que se me conecto
	unsigned int addrlen = sizeof(struct sockaddr_in); //Tamano necesario para accept()
	struct sockaddr_in datos_server, datos_cliente; //Datos del cliente y servidor
  	int on = 1;//Necesario para setsockop
	char puerto[10];
	int port, pid = 0;

	if	(argc == 2)
	{
	    /* 1.1. Al captar senal 'SIGCHLD' (enviada automaticamente al morir un hijo) se ejecuta la funcion sc_handler */
	    signal(SIGCHLD, sc_handler);

		strcpy(puerto, argv[1]);
		port = atoi(puerto);

		// Creo el socket
		listener_socket_fd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP) ;

		// Lleno la estructura con la info del server
		datos_server.sin_family = AF_INET;
		datos_server.sin_addr.s_addr = INADDR_ANY; //Localhost
		datos_server.sin_port = htons(port);
		memset(datos_server.sin_zero, 0, 8);

		/*Si el server se cierra bruscamente queda ocupado el puerto hasta que
			reinicies y es molesto, con la siguiente linea se soluciona */
		setsockopt(listener_socket_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

		// Enlazo el socket a la ip:puerto (contenida en la estructura que llene)
		bind(listener_socket_fd, (struct sockaddr*)&datos_server, (socklen_t)sizeof(datos_server));

		// Pongo el socket a la escucha ("enciendo" el server)
		listen(listener_socket_fd,MAXCONEXIONES);


		SPACE
		SEPARATOR
		HIGHLIGHT
		SET_GREEN
		printf("Server conectado\n\n");
		DEFAULT
		printf("Puerto:\t%d\n", port);
		SPACE
		SEPARATOR
		SPACE

		while(1)
		{
			printf("Esperando conexiones\n\n");

			//Acepto una conexion
			client_socket_fd = accept(listener_socket_fd, (struct sockaddr *)&datos_cliente, &addrlen);
			online_clients++;

			pid = fork();
			if(pid < 0) //ERROR
			{
				printf("Error en fork\n");
				break;
			}
			else if (pid > 0) //PADRE
			{
				HIGHLIGHT
				SET_GREEN
				printf("Nueva conexion desde la IP: %s\n", inet_ntoa((struct in_addr)datos_cliente.sin_addr));
				DEFAULT
				close(client_socket_fd);
			}
			else //HIJO
			{
				close(listener_socket_fd);
				child_process(client_socket_fd, datos_cliente);
			}
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

void send_image(int client_socket_fd)
{
	char buffer[MAXBUFFER];
	FILE* fp;

	HIGHLIGHT
	printf("Comenzando proceso de envio de imagen\n");
	DEFAULT

	fp = fopen("lenna.png", "r");
	if (fp != NULL)
	{	
		while (!feof(fp))
		{
			fread(buffer, sizeof(char), MAXBUFFER, fp);
			send(client_socket_fd, buffer, MAXBUFFER, 0);

		}
		/* Me aseguro de mandar "FIN" con '\0' al final */
		memset(buffer, '\0', MAXBUFFER);
		strcpy(buffer, "FIN");

		send(client_socket_fd, buffer, MAXBUFFER, 0);
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


void sc_handler()
{
    /* 2.1. Aunque la funcion se ejecuta cada vez que muere un hijo, para no pasar por alto ninguno (al morir tantos casi a la vez, puede pasar),
        al ejecutarce la funcion, esta loopea hasta que la cantidad de hijos vivos (online_clients) llegue finalmente a 0.  */
    while((waitpid(-1, NULL, WNOHANG) != 0) && (online_clients > 0))
    {
        online_clients--;
		printf("Proceso hijo finalizado, fin de conexion\n");
    }
}


int child_process(int client_socket_fd, struct sockaddr_in datos_cliente)
{
	char buffer[MAXBUFFER]; //Buffer para recibir mensajes
  	int clienteConectado; //Flag 
  	int sizeMensaje; //Tamano del mensaje recibido
	char auxIp[25];

	clienteConectado = 1;

	//Muestro la IP del cliente, la obtengo de datos_cliente
	strcpy(auxIp, inet_ntoa((struct in_addr)datos_cliente.sin_addr));

	//Envio saludo al cliente
	strcpy(buffer, "Bienvenido!!");
	send(client_socket_fd, buffer, strlen(buffer), 0);
	memset(buffer, '\0', MAXBUFFER);

	while(clienteConectado)
	{
		printf("Esperando mensaje\n");

		//Recibo mensaje del cliente
		memset(buffer, '\0', MAXBUFFER);
		sizeMensaje = recv(client_socket_fd, buffer, MAXBUFFER, 0);
		SET_GREEN
		printf("EL MENSAJE ES [%s]\n", buffer);
		DEFAULT

		if(sizeMensaje > 0)
		{
			if (!strcmp(buffer, "/imagen"))
			{
				printf("%s: Imagen solicitada\n", auxIp);							
				send_image(client_socket_fd);
			}
			else if(!strcmp(buffer, "salir"))
			{
				printf("[%s]: Desea desconectarce\n", auxIp);
				clienteConectado = 0;
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
			printf("Recivi size < 0\n");
		}
	}
	HIGHLIGHT
	printf("[%s] fue desconectado\n", auxIp);
	DEFAULT

	//Cierro el socket del cliente
	close(client_socket_fd);

	exit(0);
	
}