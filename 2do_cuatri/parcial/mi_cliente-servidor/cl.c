#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

//sockets
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

#define MAXBUFFER 	100

#define SEPARATOR   printf("//////////////////////////////////////////////////////////////////////////////\n");
#define SPACE       printf("\n\n");
#define DEFAULT     printf("\033[00m");
#define SET_RED     printf("\033[31m");
#define SET_GREEN   printf("\033[32m");
#define HIGHLIGHT   printf("\033[07m");

int main()
{
    int client, port, msize = 0, client_on = 0;
    struct sockaddr_in datos_server;
    char buff[MAXBUFFER], ip[30];

    memset(buff, '\0', MAXBUFFER);

    printf("Ingrese ip y puerto\n");
    scanf("%s", ip);
    scanf("%d", &port);
    __fpurge(stdin);

    client = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    datos_server.sin_family = AF_INET;
    datos_server.sin_addr.s_addr = inet_addr(ip);
    datos_server.sin_port = htons(port);
    memset(datos_server.sin_zero, 0, 8);

    if ( connect(client, (struct sockaddr*)&datos_server, sizeof(datos_server)) != -1)
    {
        printf("Conectado a [%s] puerto [%d]\n\n", ip, port);
        client_on = 1;

        msize = recv(client, buff, MAXBUFFER, 0); //1
        if ((msize > 0) && !strcmp(buff, "Bienvenido"))
        {
            while(client_on)
            {
                printf("Escriva mensaje a enviar\n");
                fgets(buff, MAXBUFFER, stdin);
                buff[strlen(buff)-1] = '\0'; //saco el '\n'
                msize = send(client, buff, MAXBUFFER, 0); //2
                if(msize > 0)
                {
                    if(strcmp(buff, "salir") != 0)
                    {
                        printf("Mensaje enviado. [%s]\n", buff);
                    }
                    else
                    {
                        printf("Adios\n");
                        client_on = 0;
                    }
                }
                else
                {
                    printf("Error en send\n");
                }
            }
            close(client);
        }
        else
        {
            printf("Error en recv");
        }   
    }

    return 0;
}