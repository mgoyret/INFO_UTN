#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <dirent.h>
#include <linux/soundcard.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdio_ext.h>
#include <dirent.h>


#define DEFAULT     printf("\033[00m");
#define BLANCO      printf("\033[00m");
#define VERDE       printf("\033[32m");
#define ROJO        printf("\033[31m");
#define AZUL        printf("\033[94m");
#define INVISIBLE   printf("\033[08m");
#define RESALTAR    printf("\033[07m\n");
#define ESPACIO     printf("\n\n");
#define TAM 600
//#define CANT 50
#define EXITO  0 
#define ERROR -1
#define ARRA 30
#define LOG
//#define ALGO
#define DBG 50

typedef enum NivelLog
{
    DEBUG,
    INFO,
    WARN,
    error,
    FATAL,
}Nivel_Log;

//Definimos la estructura
typedef struct nombre
{
    char usuario[30];
    char contra[30];
    long int tiempo;
}Datos;

void Imprimir_Arreglo(Datos *,int );
int cargar_usuario(FILE * ,Datos **);
int registrarse ();
int usuario_existe(Datos *,int ,char *,int *);
void ordenar(Datos **, int ); 
int ingresar();
void swap(Datos **, Datos **);
void cargar_archivo(Datos *,int );
void log_msg(Nivel_Log , const char*,int,const char*);
int salir();
int eliminar();



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



/* 1. Bits por bytes*/
#define BITS 8
/* 2. Milisengundos por segundo */
#define MILI 1000
#define VALID_OP   ( (op == 1) || (op == 2) || (op == 3) )

/*
    #define VERDE       printf("\033[32m");
    #define INVISIBLE   printf("\033[08m");
    #define RESALTAR    printf("\x1B[07m\n");
*/

/* 3. Estrructura con informacion del archivo de audio */
typedef struct HeaderIfw
{
    char format[9]; //Siempre vale "INFOWAVE"
    int sample_rate;
    int bits_per_sample;
    char num_channels;
}HeaderIfw;

/* 4. Declaracion de la funcion "set_audio_prop". Establece los parametros de configuracion de la placa de sonido */
void set_audio_prop (int sound_card_fd, HeaderIfw *audio_prop);

/* 5. Declaracion de la funcion "get_header". Copia el encabezado de un archivo "infowave" en una estructura */
int get_header(FILE** audio_file_fd, HeaderIfw* audio_prop);

/* 6. Declaracion de la funcion "calculate_size". Calcula los segundos de duracion de un archivo de audio a partir del peso y de los parametros del audio */
int calculate_size(FILE* audio_file_fd, HeaderIfw audio_prop);

int mostrar_directorios(char* nombre_dir);

int mostrar_archivos(char* nombre_dir);

int play(char* camino_cancion, char* nombre_cancion);