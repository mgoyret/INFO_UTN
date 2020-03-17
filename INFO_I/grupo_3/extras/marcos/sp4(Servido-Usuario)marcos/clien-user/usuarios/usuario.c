#include "funciones.h"


int main(int argc, char* argv[]) {
    int serverPort, messageSize, clientOnline, sentBytes,conectando=1, i = 0;
    char buffer[BUFFER_MAX];
    int op = 0, status = EXITO;// salida=ERROR;
    Cliente yo;

    // 1. Declaro el file descriptor para el socket de la conexión
    int clientSocketFd;
    // 2. Declaro estructura para la informacion de direccion del servidor
    struct sockaddr_in serverData;
    // 3. Declaro un puntero a una estructura donde gethostbyname() me retornara la IP
    struct hostent* hostData;

    // 4. Obtengo el número de IP y de puerto pasados como parámetros del main
    if (argc < 3) {
        printf("Debe ingresar la IP y el puerto como parametros\n");
        printf("Uso: %s <IP> <PUERTO>\n", argv[0]);
        return -1;
    } else {
        hostData = gethostbyname(argv[1]);
        if (hostData == NULL) {
            printf("Error en gethostbyname()\n");
            return -1;
        }

        serverPort = atoi(argv[2]);
    }

    // 5. Creo el socket, con configuración para IPv4 y TCP
    clientSocketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocketFd == -1) {
        printf("Error en socket()\n");
        return -1;
    }

    // 6. Cargo información del servidor
    serverData.sin_family = AF_INET;
    memcpy(&(serverData.sin_addr), hostData->h_addr_list[0], hostData->h_length);
    serverData.sin_port = htons(serverPort);
    memset(&(serverData.sin_zero), 0, 8);
    
    // 7. Conecto el socket al servidor
    status = connect(clientSocketFd, (struct sockaddr *) &serverData, sizeof(struct sockaddr));
    if (status == -1) {
        printf("Error en connect()\n");
        return -1;
    }

    // 8. Cliente conectado al servidor
    //printf("Cliente conectado al servidor\n");
    clientOnline = 1;
    conectando=1;

    // 9. Recibe mensaje de bienvenida y coloco el último caracter recibido como NULL, por si acaso
    messageSize = recv(clientSocketFd, buffer, BUFFER_MAX, 0);
    if (messageSize == -1) {
        printf("Error en recv()\n");
        return -1; 
    }
    buffer[messageSize] = '\0';

    // 10. Muestro mensaje recibido del servidor
    printf("%s\n", buffer);
    while (conectando)
    {
        printf("\nSeleccione a continuación la operación que desea realizar:\n1 - Ingresar\n2 - Registrarse\n3 - Eliminar\n4 - Salir\n");
        scanf("%s", buffer);
        op=atoi(buffer);
        if (op<6)
        {
            send(clientSocketFd,buffer,1,0);
            if (op>0 && op<4)
            {
                printf("Usuario:");
                scanf("%s",yo.usuario);
                send(clientSocketFd,yo.usuario,20,0);
                printf("contraseña:");
                scanf("%s",yo.clave);
                send(clientSocketFd,yo.clave,20,0);

                messageSize = recv(clientSocketFd,buffer,BUFFER_MAX,0);
                if (messageSize>0)
                {
                    buffer[messageSize]='\0';
                }

                if (strcmp(buffer,"Bienvenido")==0 && op==1) //usuario conectado e ingresado a su cuenta
                {
                    printf("%s %s",buffer,yo.usuario);
                    
                    i = 0;
                    do // Recibo nombres de directorios
                    {
                        i++;
                        messageSize = recv(clientSocketFd, buffer, NAME_LEN, 0); /* 1 */
                        if (strcmp(buffer, "FIN") != 0)
                        {
                            AZUL
                            printf("%d - %s\n", i, buffer);
                            BLANCO
                        }
                    } while ( (messageSize>0) && (strcmp(buffer, "FIN") != 0) );
                    if (i > 0)
                    {
                        ESPACIO
                        __fpurge(stdin);
                        printf("Elija un artista:  ");
                        fgets(buffer, NAME_LEN, stdin);
                        /* fgets toma el '\n', asique lo elimino */
                        buffer[strlen(buffer)-1] = '\0';
                        send(clientSocketFd, buffer, NAME_LEN, 0);  /* 2 */  //envio nombre de artista
                        messageSize = recv(clientSocketFd, buffer, 5, 0);  /* 3 */  //recibo si existe o no el artista en el directorio
                        if ( (messageSize>0) && (strcmp(buffer, "FIN") != 0) )
                        {
                            //en el servidor aca entra a la funcion mostrar archivos

                            i = 0;
                            do // Recibo nombres de canciones
                            {
                                i++;
                                messageSize = recv(clientSocketFd, buffer, NAME_LEN, 0); /* 4 */
                                if (strcmp(buffer, "FIN") != 0)
                                {
                                    AZUL
                                    printf("%d - %s\n", i, buffer);
                                    BLANCO
                                }
                            } while ( (messageSize>0) && (strcmp(buffer, "FIN") != 0) );
                            if (i > 0)
                            {
                                ESPACIO
                                printf("Elija una cancion:  ");
                                scanf("%s", buffer);
                                send(clientSocketFd, buffer, NAME_LEN, 0); /* 5 */ //envio nombre de cancion a reproducir

                                messageSize = recv(clientSocketFd, buffer, NAME_LEN, 0); /* 6 */
                                if ( (messageSize>0) && (strcmp(buffer, "FIN") != 0) )
                                {
                                    printf("Se reproducira la cancion seleccionada \n");

                                    /* Aca tengo que recibir el archivo de la cancion (lo recibo con un buffer y creo archivo temporal)
                                        y reproduzco con play desde aca. Luego borro el archivo temporal */

                                }
                                else
                                {
                                    printf("Cancion no encontrada\n");
                                }
                            }
                            else
                            {
                                RESALTAR
                                ROJO
                                printf("No se encontraron canciones\n");
                                BLANCO
                            }
                        }
                        else
                        {
                            printf("No se encontro el artista\n");
                        }                    
                    }
                    else
                    {
                        ROJO
                        printf("No se encontraron directorios\n");
                        BLANCO
                    }            
                    //ESPACIO
                    //printf("Bien ya entraste todavia no se hace nada:\n1-Cerrar Cesión\n2-Cerrar Cesión\nopción: ");
                    //scanf("%d",&op);
                    //if (op<1 || op>2)
                    //{
                    //    printf("Por gracioso cierro cesión igual");
                    //}else
                    //{
                    //    printf("vuelva pronto");
                    //}
                    //ESPACIO
                }
                
            }else
            {
                recv(clientSocketFd,buffer,1,0);
                conectando=atoi(buffer);
            }
        }else
        {
            ESPACIO
            ROJO
            printf("Opción invalida");
            BLANCO
            ESPACIO
        }
        
    }
    

    while (clientOnline) {
        // 11. Envia mensajes al servidor hasta recibir "exit"
        printf("Escriba mensaje a enviar (o \"exit\" para salir): ");
        fgets(buffer, BUFFER_MAX, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        if (!strcmp(buffer, "exit")) {
            clientOnline = 0;
        } else {
            sentBytes = send(clientSocketFd, buffer, strlen(buffer), 0);

            if (sentBytes <= 0) {
                printf("Error en send()");
                clientOnline = 0;
            }
        }
    }

    // 12. Cierro conexión
    close(clientSocketFd);
    printf("Conexion con servidor finalizada\n");

    return 0;
}
