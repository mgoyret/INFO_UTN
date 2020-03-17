#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <signal.h>
#include "sockets_server.h"
#include "funciones.h"

#define BUFFER_MAX 100      // Tamaño del buffer de datos en bytes
#define IP_LENGTH 16

int clientsCount = 0;

/*Declaracion de funciones*/
    void sigchld_handler();
    void child_process(int clientSocketFd, struct sockaddr_in clientData);

int main(int argc, char* argv[]) {
    int port, clientLength, pid, listenSocketFd, clientSocketFd;
    struct sockaddr_in clientData;

    // 1. Capturo la señal SIGCHLD, enviada cuando muere un proceso hijo
    signal(SIGCHLD, sigchld_handler);

    // 2. Obtengo el número de puerto pasado como parámetro del main
    if (argc < 2) {
        printf("Debe ingresar el puerto como parámetro\n");
        printf("Uso: %s <PUERTO>\n", argv[0]);
        return -1;
    } else {
        port = atoi(argv[1]);
    }

    // 3. Abro un socket tcp
    listenSocketFd = open_tcp_socket(port);
    if (listenSocketFd == -1) {
        printf("Error en open_tcp_socket()");
        return -1;
    }
    
    // 4. Server corriendo esperando conexiones
    printf("Server corriendo en el puerto: %d\n", port);

    while (1) {
        // 5. Acepto la conexión entrante
        clientLength = sizeof(struct sockaddr_in);
        clientSocketFd = accept(listenSocketFd, (struct sockaddr*) &clientData, (socklen_t*) &clientLength);
        if (clientSocketFd == -1) {
            printf("Error en accept()\n");
            continue;
        }

        // 6. Genero un proceso hijo para atender al cliente, el padre se queda atendiendo llamadas
        pid = fork();
        if (pid < 0) {
            // 7. Error! No se pudo generar el proceso hijo
            printf("Error en fork()\n");
            return -1;

        } else if (pid == 0) {
            // 8. Proceso hijo
            close(listenSocketFd);
            child_process(clientSocketFd, clientData);
            return 0;

        } else {
            // 9. Proceso padre
            close(clientSocketFd);
            clientsCount++;
            printf("Nuevo cliente! Total de clientes conectados: %d\n", clientsCount);
        }
    }

    // 10. Cierra el socket de escucha
    close(listenSocketFd);
    printf("Servidor finalizado\n");

    return 0;
}


/**
 * \fn      void child_process(int clientSocketFd, struct sockaddr_in clientData)
 * \brief   Proceso hijo se encarga de las funciones 'ingresar', 'registrarse','salir','eliminar'.
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman.
 * \date    Nov 10, 2019
 * \return  -
 */
 
void child_process(int clientSocketFd, struct sockaddr_in clientData) {
    int messageSize,conectado=1,casos,salida=ERROR;
    char clientIp[IP_LENGTH];
    char buffer[BUFFER_MAX];
    Datos dato;

    // 11. Muestra la IP del cliente
    strcpy(clientIp, inet_ntoa((struct in_addr) clientData.sin_addr));
    printf("Se obtuvo una conexion desde la IP: %s\n", clientIp);
    
    
    send(clientSocketFd,"Bienvenido al menu de inicio de Inspotify",42,0);
    
    // Vemos si ingresa un usuario.
    while (conectado)
    {   
        messageSize=recv(clientSocketFd,buffer,1,0);
        buffer[1]='\0';
        casos=atoi(buffer);
        if (messageSize>0)
        {
            switch (casos)
            {
            //Ingresar
            case 1:
                messageSize=recv(clientSocketFd,dato.usuario,20,0);
                if (messageSize>0) 
                {
                    dato.usuario[messageSize]='\0';
                    printf("Nombre de usuario recibido: '%s'\n", dato.usuario);
                }
                messageSize=recv(clientSocketFd,dato.contra,20,0);
                if (messageSize>0)
                {
                    dato.contra[messageSize]='\0';
                    printf("Contrasena recibida: '%s'\n", dato.contra);
                }
                salida=ingresar(dato,clientSocketFd);
                printf("\nYa fuera de funcion ingresar\n");
                if (salida==EXITO)
                {
                    clienteIngresado(dato, clientSocketFd, clientIp); //mando mensaje de bienvenida
                }else//La funcion debe contestar si hubo un error o fue exitosa. esto es provisorio
                {
                    send(clientSocketFd,NULL,0,0);
                }
                
                break;

            //Registrarse
            case 2:
                messageSize=recv(clientSocketFd,dato.usuario,20,0);
                if (messageSize>0)
                {
                    dato.usuario[messageSize]='\0';
                }
                messageSize=recv(clientSocketFd,dato.contra,20,0);
                if (messageSize>0)
                {
                    dato.contra[messageSize]='\0';
                }
                salida=registrarse(dato,clientSocketFd);
                if (salida==EXITO)
                {
                    send(clientSocketFd,"Bienvenido a la comunidad",26,0);
                }else//La funcion debe contestar si hubo un error o fue exitosa. esto es provisorio
                {
                    send(clientSocketFd,"Usuario o contraseña incorrectos",33,0);
                }
                
                break; 
            
            //Eliminar
            case 3:
                messageSize=recv(clientSocketFd,dato.usuario,20,0);
                if (messageSize>0)
                {
                    /*Agregamos un \0 al final del nombre del usuario para poder imprimirlo sin basura*/
                    dato.usuario[messageSize]='\0';
                }
                messageSize=recv(clientSocketFd,dato.contra,20,0);
                if (messageSize>0)
                {
                    dato.contra[messageSize]='\0';
                }
                salida=eliminar(dato,clientSocketFd);
                if (salida==EXITO)
                {
                    send(clientSocketFd,"Espero que vuelvas pronto",26,0);
                }else//La funcion debe contestar si hubo un error o fue exitosa. esto es provisorio
                {
                    send(clientSocketFd,"Usuario o contraseña incorrectos",33,0);
                }
                break;
            
            //Salir
            case 4:
                printf("El usuario con  IP: %s se desconecto.\n",clientIp);
                conectado=0;
                buffer[0]='0';
                send(clientSocketFd,buffer,1,0);
                break;
            default:
                buffer[0]='1';
                send(clientSocketFd,buffer,1,0);
                break;
            }
        }
        
    }
    close(clientSocketFd);
}    


/**
 * \fn     void clienteIngresado(Datos dato,int clientSocketFd,char *clientIp)
 * \brief   Muestra por pantalla que usuario ha ingresado, le da la bienvenida y muestra el usuario que cerro sesion
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman.
 * \date    Nov 10, 2019
 * \return  -
 */
void clienteIngresado(Datos dato,int clientSocketFd,char *clientIp)
{
    printf("%s acaba de iniciar sesión\n",dato.usuario);
    send(clientSocketFd,"Bienvenido",11, 0);
    
    mostrar_directorios("MEDIA", clientSocketFd);

    // 15. Cierra sesión el cliente
    printf("%s acaba de cerra sesión\n",dato.usuario);
}


/**
 * \fn    void sigchld_handler()
 * \brief   Sepulta al hijo y muestra la cantidad total de clientes conectados.
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman.
 * \date    Nov 10, 2019
 * \return  -
 */
 
void sigchld_handler() {
    // 16. "Sepulto" al hijo
    while (waitpid((pid_t)(-1), 0, WNOHANG) > 0);
    clientsCount--;
    printf("Cliente desconectado! Total de clientes conectados: %d\n", clientsCount);
}
