//logfile
#define ALGO
 
///SOCKETS///
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

///PLAY///

#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <time.h>
#include <linux/soundcard.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio_ext.h>

///OPENCV///
#include </usr/include/opencv/cv.h>
#include <opencv2/core/core_c.h>
#include <opencv2/core/types_c.h>
#include <opencv2/highgui/highgui_c.h>



#define DEFAULT     printf("\033[00m");
#define BLANCO      printf("\033[00m");
#define VERDE       printf("\033[32m");
#define ROJO        printf("\033[31m");
#define AZUL        printf("\033[94m");
#define INVISIBLE   printf("\033[08m");
#define RESALTAR    printf("\033[07m\n");
#define ESPACIO     printf("\n\n");

#define EXITO       0 
#define ERROR       -1

#define TAM         600
#define ARRA        30
#define LOG
#define DBG         50
#define BUF_S       100000

/*Defines para la interfaz grafica */
#define PLAY    1
#define PAUSE   2
#define STOP    3

#define BOTON0  "../data/BOTON0.png"
#define BOTON1  "../data/BOTON1.png"
#define BOTON2  "../data/BOTON2.png"
#define BOTON3  "../data/BOTON3.png"


#define BUFFER_MAX  100     // Tamaño del buffer de datos en bytes
#define SONG_BUF    100000
#define NAME_LEN    30      // Calculo este tamano para nombres de directorios y canciones, mismo tamano que en el servidor

// 1. Bits por bytes
#define BITS        8
// 2. Milisengundos por segundo
#define MILI        1000
#define VALID_OP    ( (op == 1) || (op == 2) || (op == 3) )



typedef enum NivelLog
{
    DEBUG,
    INFO,
    WARN,
    error,
    FATAL,
}Nivel_Log;

typedef struct nombre
{
    char usuario[20];
    char contra[20];
    long int tiempo;
}Datos;

typedef struct Cliente
{
    char usuario[20];
    char clave[20];
}Cliente;


/* Estrructura con informacion del archivo de audio */
typedef struct HeaderIfw
{
    char format[9]; //Siempre vale "INFOWAVE"
    int sample_rate;
    int bits_per_sample;
    char num_channels;
}HeaderIfw;

//Funciones en funcionesplay/funciones.c

/* Declaracion de la funcion "set_audio_prop". Establece los parametros de configuracion de la placa de sonido */
void set_audio_prop (int sound_card_fd, HeaderIfw *audio_prop);

/* Declaracion de la funcion "get_header". Copia el encabezado de un archivo "infowave" en una estructura */
int get_header(FILE** , HeaderIfw* );

/* Declaracion de la funcion "calculate_size". Calcula los segundos de duracion de un archivo de audio a partir del peso y de los parametros del audio */
int calculate_size(FILE* , HeaderIfw );

int play(char* , char* );

void log_msg(Nivel_Log , const char*,int,const char*);

void reproducir(char *);
void myCallback(int , int , int , int , void *);
