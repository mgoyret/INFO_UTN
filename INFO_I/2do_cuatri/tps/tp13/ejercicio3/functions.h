/**
 * \file            functions.h
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Oct 21, 2019
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

/* Defines para comodidad de indentacion */
#define FIFO_FILE1   "MIFIFO1"
#define FIFO_FILE2   "MIFIFO2"
#define MAX         100
#define set_space   printf("\n\n");
#define set_default printf("\033[00m");
#define set_blue    printf("\033[94m");
#define set_highlit printf("\033[07m\n");

/* 1. Prototipo de la función "msj_chek" */
int msj_check(char* str);

/* 2. Prototipo de la función "choose_messege" */
void choose_messege(char*, char*);

/* 3. Prototipo de la función "choose_saying" */
void choose_saying();

/* 4. Prototipo de la función "choose_song" */
void choose_song();

/* 5. Prototipo de la función "choose_movie" */
void choose_movie();

/* 6. Prototipo de la función "rand_num" */
int rand_num();

#endif  //FUNCTIONS_H_ 