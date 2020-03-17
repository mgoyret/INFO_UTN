#include "../inc/funciones.h"

#define SONG 10000 gitn

int mouse_flags = PLAY;


int main(int argc, char* argv[])
{
    unsigned int serverPort, conectando=1, songBytes = 0;
    int op = 0, status = EXITO, messageSize, okdata = ERROR;
    char buffer[BUFFER_MAX],cancion[BUFFER_MAX], song_buffer[SONG_BUF];
    FILE *fp=NULL;
    Cliente yo;

    // Declaro el file descriptor para el socket de la conexión
    int clientSocketFd;
    // Declaro estructura para la informacion de direccion del servidor
    struct sockaddr_in serverData;
    // Declaro un puntero a una estructura donde gethostbyname() me retornara la IP
    struct hostent* hostData;

    // Obtengo el número de IP y de puerto pasados como parámetros del main
    if (argc == 3)
    {
        hostData = gethostbyname(argv[1]);
        if (hostData == NULL) {
            RESALTAR
            ROJO
            printf("Error en gethostbyname()\n");
            BLANCO
            return -1;
        }
        serverPort = atoi(argv[2]);
        
        // Creo el socket, con configuración para IPv4 y TCP
        clientSocketFd = socket(AF_INET, SOCK_STREAM, 0);
        if (clientSocketFd != -1)
        {
            // Cargo información del servidor
            serverData.sin_family = AF_INET;
            memcpy(&(serverData.sin_addr), hostData->h_addr_list[0], hostData->h_length);
            serverData.sin_port = htons(serverPort);
            memset(&(serverData.sin_zero), 0, 8);
            
            // Conecto el socket al servidor
            status = connect(clientSocketFd, (struct sockaddr *) &serverData, sizeof(struct sockaddr));
            if (status != -1)
            {
                // Cliente conectado al servidor
                conectando=1;

                // Recibe mensaje de bienvenida y coloco el último caracter recibido como NULL, por si acaso
                messageSize = recv(clientSocketFd, buffer, BUFFER_MAX, 0);
                if (messageSize == -1) {
                    RESALTAR
                    ROJO
                    printf("Error en recv()\n");
                    BLANCO
                    return -1; 
                }
                buffer[messageSize] = '\0';

                //Muestro mensaje recibido del servidor
                RESALTAR
                printf("%s\n", buffer);
                BLANCO
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
                            do
                            {
                                /* Los espacios puestos en los printf estan calculados para q el user y clave se escriban alineados */
                                printf("Usuario:  ");
                                scanf("%s",yo.usuario);
                                send(clientSocketFd,yo.usuario,20,0);
                                printf("Clave:    ");
                                scanf("%s",yo.clave);
                                send(clientSocketFd,yo.clave,20,0);
                                
                                printf("Espero respuesta del servidor...\n");
                                messageSize = recv(clientSocketFd,buffer,BUFFER_MAX,0);
                                printf("Respuesta recibida!\n");
                                buffer[messageSize]='\0';
                                if (messageSize>0)
                                {
                                    printf("%s\n", buffer);
                                    if(strcmp(buffer, "datos incorrectos") == 0)
                                    {
                                        RESALTAR
                                        ROJO
                                        printf("Datos incorrectos\n");
                                        BLANCO
                                        okdata = ERROR;
                                    }
                                    else
                                    {
                                        okdata = EXITO;
                                    }
                                }
                            }while(okdata != EXITO);

                            if (strcmp(buffer,"Bienvenido")==0 && op==1) //usuario conectado e ingresado a su cuenta
                            {
                                RESALTAR
                                printf("\nARTISTAS\n\n");
                                BLANCO
                                
                                recv(clientSocketFd, song_buffer, SONG_BUF, 0);
                                printf("%s\n", song_buffer);

                                if (song_buffer[0] != '\0')
                                {
                                    RESALTAR
                                    printf("Elija un artista por su nombre:  ");
                                    BLANCO
                                    ESPACIO
                                    __fpurge(stdin);
                                    fgets(buffer, NAME_LEN, stdin);
                                    /* fgets toma el '\n', asique lo elimino */
                                    buffer[strlen(buffer)-1] = '\0';
                                    send(clientSocketFd, buffer, NAME_LEN, 0);  /* 2 */  //envio nombre de artista
                                    messageSize = recv(clientSocketFd, song_buffer, SONG_BUF, 0);  /* 3 */  //recibo si existe o no el artista en el directorio
                                    messageSize = recv(clientSocketFd, song_buffer, SONG_BUF, 0); /* 3 */ // no se xq pero llega al 2do send
                                    if ((messageSize>0) && (strcmp(song_buffer, "OK.") == 0))
                                    {
                                        RESALTAR
                                        printf("\nCANCIONES\n\n");
                                        BLANCO
                                        ESPACIO
                                        //en el servidor aca entra a la funcion mostrar archivos
                                        printf("Antes del recv\n");
                                        
                                        recv(clientSocketFd, song_buffer, SONG_BUF, 0); /* 4 */
                                        printf("%s\n", song_buffer);

                                        if (song_buffer[0] != '\0')
                                        {
                                            RESALTAR
                                            printf("Elija una cancion por su nombre:  ");
                                            BLANCO
                                            ESPACIO
                                            scanf("%s", cancion);
                                            strcpy(buffer,cancion);
                                            send(clientSocketFd, buffer, NAME_LEN, 0); /* 5 */ //envio nombre de cancion a reproducir

                                            messageSize = recv(clientSocketFd, buffer, NAME_LEN, 0); /* 6 */
                                            if ( (messageSize>0) && (strcmp(buffer, "FIN") != 0) )
                                            {
                                                printf("Se reproducira la cancion %s\n", cancion);

                                                //////////////////////////////////////////////////////////////////////////////////////////////////
                                                fp = fopen(cancion, "wb");
                                                if (fp != NULL)
                                                {
                                                    memset(song_buffer, '\0', SONG_BUF);
                                                    while (1)
                                                    {
                                                        messageSize = recv(clientSocketFd, song_buffer, SONG_BUF, 0);
                                                        //if capta "FIN" aunque no este el '\0'
                                                        if(((song_buffer[0] == 'F') && (song_buffer[1] == 'I') && (song_buffer[2] == 'N')) || (strcmp(song_buffer, "FIN") == 0))
                                                        {
                                                            break;
                                                        }
                                                        else if (messageSize != -1)
                                                        {
                                                            songBytes += messageSize;
                                                            fwrite(song_buffer, sizeof(char), SONG_BUF, fp);
                                                        }
                                                    }
                                                    fclose(fp);
                                                    reproducir(cancion);
                                                    sleep(1);
                                                    remove(cancion);
                                                    fclose(fp);
                                                }

                                                else
                                                {
                                                    RESALTAR
                                                    ROJO
                                                    printf("Error en funcion fopen\n");
                                                    BLANCO
                                                }
            //////////////////////////////////////////////////////////////////////////////////////////////////
                                                sleep(2);
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
                                    printf("No se encontraron artistas\n");
                                    BLANCO
                                }        
                            }
                        }
                        else
                        {
                            recv(clientSocketFd,buffer,1,0);
                            conectando=atoi(buffer);
                        }
                    }
                    else
                    {
                        ESPACIO
                        ROJO
                        printf("Opción invalida");
                        BLANCO
                        ESPACIO
                    } 
                }
                // 12. Cierro conexión
                close(clientSocketFd);
                printf("Conexion con servidor finalizada\n");
                send(clientSocketFd, NULL, 1, 0); /* END */
            }
            else
            {
                RESALTAR
                ROJO
                printf("Error en connect()\n");
                BLANCO
                ESPACIO
                return -1;
            }
        }
        else
        {
            RESALTAR
            ROJO
            printf("Error en socket()\n");
            BLANCO
            return -1;
        }
    }
    else
    {
        printf("Debe ingresar la IP y el puerto como parametros\n");
        printf("Uso: %s <IP> <PUERTO>\n", argv[0]);
        return -1;
    }

    return 0;
}

/*  Definicion de la funcion "reproducir" */

/**
 * \fn      void reproducir(char *cancion)
 * \brief   
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Nov 15, 2019
 * \param	cancion: Archivo donde se encuentra la cancion a reproducir	
 *          Recibido por referencia para que la función que la llamó sepa en cuanto se configuró.
 */
void reproducir(char *cancion)
{
    int buff_size = 0, sound_card_fd = 0,exit=0,status=0, rec_time = 0;
    //long int i_time = 0, f_time = 0, faux1_time = 0, faux2_time = 0;
 	unsigned char* buf = NULL;
    HeaderIfw audio_prop;
    FILE *fp = NULL;
    IplImage *img;
    char char_flag = 0;

    fp= fopen(cancion, "r");
    if(fp != NULL)
    {
        /* 5. Invoco a la funcion "get_header", que carga el encabezado del archivo apuntado por "audio_file_fp" en la estructura "audio_prop" */
        get_header(&fp, &audio_prop);
        /* 6. Invoco a la funcion "calculate_size", que calcula la duracion del audio en base a la informacion del encabezado del archivo */
        rec_time = calculate_size(fp, audio_prop);
        printf("HOLA\n");
        /* 7. Calculamos dinámicamente el tamaño del buffer de audio */
        buff_size = rec_time*audio_prop.sample_rate*audio_prop.bits_per_sample*atoi(&(audio_prop.num_channels))/BITS/MILI;
        buf = (unsigned char *) malloc(buff_size);
        if(buf != NULL)
        {
            sound_card_fd = open("/dev/dsp", O_RDWR);
            if(sound_card_fd != -1)
            {
                /* 8. Seteamos parámetros de audio */
                set_audio_prop(sound_card_fd, &audio_prop);


                ///* 5. Inicializamos la variable de tiempo y limpiamos la pantalla */
                //i_time = time(NULL);
                //printf("\033[2J\n");


                img = cvLoadImage(BOTON0, CV_LOAD_IMAGE_COLOR);
                if(img==NULL)
                {
                    printf("No se pudo cargar la interfaz frafica\n");
                }
                else
                {
                    cvNamedWindow("ventana", CV_WINDOW_AUTOSIZE);
                    cvSetMouseCallback("ventana", myCallback, (void *) img);
                    cvShowImage("ventana", img);
                }

                do
                {
                    char_flag = (char)cvWaitKey(1); //espera por 1 milisegundo en teoria, no se percibe en el audio
                    status= fread(buf,1,buff_size,fp);
                    if (status>=0)
                    {
                        //f_time = time(NULL);

                        if (mouse_flags == PAUSE)
                        {
                            //faux1_time = time(NULL);
                            do
                            {
                                char_flag = (char)cvWaitKey(1);
                            }while (mouse_flags == PAUSE);
                            //faux2_time = time(NULL);
                        }
                        
                        //printf("\033[1;1HReproduciendo: \033[33m%s\n\t\t\033[0m(%02ld:%02ld)\n", cancion, (f_time-i_time)/60, (f_time-i_time)%60); // - (faux2_time - faux1_time)
                        //printf("Frec: %d\t Tam: %d\tCan: %d\n", audio_prop.sample_rate, audio_prop.bits_per_sample, atoi(&(audio_prop.num_channels)));


                        write(sound_card_fd, buf, buff_size);  //MOMENTO DE REPRODUCCION
                    }
                }while ((!feof(fp)) && (mouse_flags != STOP) && (char_flag != 27));
                close(sound_card_fd);
                cvReleaseImage(&img);
                cvDestroyAllWindows();
            }
            else
            {   
                RESALTAR
                ROJO
                printf("Error en funcion open\n");
                BLANCO
                exit=4;
            }
        }
        else
        {
            RESALTAR
            ROJO
            printf("Error en funcion malloc\n");
            BLANCO
            exit=3;
        } 

    }
    else
    {   
        RESALTAR
        ROJO
        printf("Error en funcion fopen\n");  
        BLANCO
        exit=2;
    }
    if(exit > 2)    fclose(fp);
    if(exit > 3)    free(buf);
}


/**
        \fn     void myCallback(int event, int x, int y, int flags, void *data)
        \brief  Función que se ejecuta al producirse un evento con el mouse.
		De los eventos que se producen, se evaluan el punto donde se ubica el mouse y la presión del boton
		izquierdo.
        \author Marcos Goyret, Felipe Galli, Matias Schvartzman
        \date   Nov 15, 2019.s
        \param  event: evento que llamó a la función
        \param  x: posición x del mouse al momento llamar a la función.
        \param  y: posición y del mouse al momento llamar a la función.
        \param  flags: flags activos al momento llamar a la función (por ejemplo tecla ctrl presionada).
        \param  *data: puntero a la estructura de la imagen 
*/

void myCallback(int event, int x, int y, int flags, void *data)
{
	char nombre[512];

	switch(event)
	{
		case CV_EVENT_LBUTTONUP:
			if ((x>70) && (x<175))
			{
				if ((y>90)&&(y<171)){  
					strcpy(nombre,BOTON1);
                    mouse_flags = PLAY;
				}
				else if ((y>245)&&(y<339)){ 
					 strcpy(nombre,BOTON2);
                     mouse_flags = PAUSE;
				}
				else if( (y>405)&&(y<505)){
					 strcpy(nombre,BOTON3);
                     mouse_flags = STOP;
				}
				
			}
			data = cvLoadImage(nombre, CV_LOAD_IMAGE_COLOR);
			cvShowImage("ventana", data);
		break;
	}
}