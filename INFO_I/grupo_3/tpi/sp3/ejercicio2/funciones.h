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


#define DEFAULT     "\x1B[0m"
#define VERDE       "\x1B[32m"
#define AZUL        "\x1B[34m"
#define ROJO        "\x1B[31m"
#define RESALTAR    "\x1B[07m\n"
#define ESPACIO     printf("\n\n");
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

typedef enum salidas
{
    ERROR,
    EXITO
}salidas;

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