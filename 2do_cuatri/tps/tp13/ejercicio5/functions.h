/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 23, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
/* PLAY */
#include <sys/ioctl.h>
#include <linux/soundcard.h>

/* Defines para comodidad de indentacion */
#define BITS 8 //Bits por bytes
#define MILI 1000 //Milisengundos por segundo

#define FIFO_FILE1   "MIFIFO1"
#define FIFO_FILE2   "MIFIFO2"
#define MAX         100
#define set_space   printf("\n\n");
#define set_default printf("\033[00m");
#define set_blue    printf("\033[94m");
#define set_highlit printf("\033[07m\n");
#define clr_screen  printf("\033[2J\n");
#define TEMP_FILE   "temp_file"
#define BUF_S       100000

/* 3. Estrructura con informacion del archivo de audio */
typedef struct HeaderIfw
{
    char format[9]; //Siempre vale "INFOWAVE"
    int sample_rate;
    int bits_per_sample;
    char num_channels;
}HeaderIfw;

/* 4. Declaracion de la funcion "play". Reproduce audio */
int play(char* camino_cancion, char* nombre_cancion);

/* 5. Declaracion de la funcion "set_audio_prop". Establece los parametros de configuracion de la placa de sonido */
void set_audio_prop (int sound_card_fd, HeaderIfw *audio_prop);

/* 6. Declaracion de la funcion "get_header". Copia el encabezado de un archivo "infowave" en una estructura */
int get_header(FILE** audio_file_fd, HeaderIfw* audio_prop);

/* 7. Declaracion de la funcion "calculate_size". Calcula los segundos de duracion de un archivo de audio a partir del peso y de los parametros del audio */
int calculate_size(FILE* audio_file_fd, HeaderIfw audio_prop);

int file_size(char* file_name);

#endif  //FUNCTIONS_H_ 