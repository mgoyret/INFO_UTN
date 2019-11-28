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

#define MAXBUFFER 	100
#define MAXCLIENT   10

#define SEPARATOR   printf("//////////////////////////////////////////////////////////////////////////////\n");
#define SPACE       printf("\n\n");
#define DEFAULT     printf("\033[00m");
#define SET_RED     printf("\033[31m");
#define SET_GREEN   printf("\033[32m");
#define HIGHLIGHT   printf("\033[07m");

int main()
{
    char buff[MAXBUFFER];
    struct sockaddr_in datos_server, datos_cliente;
    int listener = 0, cliente = 0, port = 0, client_on = 0, msize = 0, size_c = 0;
  	int on = 1;//Necesario para setsockop

    printf("Ingrese puerto\n");
    scanf("%d", &port);

    listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    datos_server.sin_family = AF_INET;
    datos_server.sin_addr.s_addr = INADDR_ANY;
    datos_server.sin_port = htons(port);
    memset(datos_server.sin_zero, 0, 8);

    /*Si el server se cierra bruscamente queda ocupado el puerto hasta que
    	reinicies y es molesto, con la siguiente linea se soluciona */
    setsockopt(listener, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    bind(listener, (struct sockaddr*)&datos_server, (socklen_t)sizeof(datos_server));  

    listen(listener, MAXCLIENT);
    printf("Server conectado\n");
    
    while (1)
    {
        size_c = sizeof(datos_cliente);
        cliente = accept(listener, (struct sockaddr*)&datos_cliente, (socklen_t*)&size_c);
        client_on = 1;

        printf("Nueva conexion desde la ip: %s\n", inet_ntoa((struct in_addr)datos_cliente.sin_addr));

        strcpy(buff, "Bienvenido");
        msize = send(cliente, buff, MAXBUFFER, 0); //1
        memset(buff, '\0', MAXBUFFER);
        if (msize > 0)
        {
            while(client_on)
            {
                msize = recv(cliente, buff, MAXBUFFER, 0); //2
                if (msize > 0)
                {
                    if (!strcmp(buff, "salir"))
                    {
                        printf("Mensaje de salida recivido\n");
                        client_on = 0;
                    }
                    else
                    {
                        printf("Cliente: '%s'\n", buff);
                        memset(buff, '\0', MAXBUFFER);   
                    }
                }
                else
                {
                    printf("Error en funcion recv\n");
                    client_on = 0;
                }
            }
            printf("Cliente [%s] desconectado\n", inet_ntoa((struct in_addr)datos_cliente.sin_addr));
        }
        else
        {
            printf("Error en send\n");
            break;
        }
    	close(cliente);
    }

    return 0;
}