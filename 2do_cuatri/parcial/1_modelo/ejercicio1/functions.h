#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT     printf("\033[00m");
#define GREEN       printf("\033[32m");
#define RED         printf("\033[31m");
#define BLUE        printf("\033[94m");
#define HIGHLIGHT   printf("\033[07m\n");
#define SPACE       printf("\n\n");

typedef struct paciente { 	
	char    name[40];
	long    dni; 	
	float   time;	
}paciente_t;

int lecturaPacientes(paciente_t **inicio, char *archivo);

#endif