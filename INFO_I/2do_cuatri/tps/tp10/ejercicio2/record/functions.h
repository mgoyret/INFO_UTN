/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 03, 2019
 * \details         Usar MakeFile para compilar y linkear
 */

#ifndef FUNCIONES_AU_H
#define FUNCIONES_AU_H


#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <linux/soundcard.h>

/* 1. Bits por bytes*/
#define BITS 8
/* 2. Milisengundos por segundo */
#define MILI 1000

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

/* 5. Declaracion de la funcion "load_header". Copia el contenido de una estructura en el encabezado de un archivo "infowave" */
int load_header(FILE* audio_file_fd, HeaderIfw audio_prop);

#endif