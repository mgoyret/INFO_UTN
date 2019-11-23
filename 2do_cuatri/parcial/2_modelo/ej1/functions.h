#ifndef functions_H_
#define functions_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DATOS
{
    char disp[20];
    char camp[20];
    int valor;  
}DATOS;

#define FILENAME    "test_config.ini"
#define LINE        50
#define FOUND_DISP  1
#define FOUND_CAMP  2

#define DEFAULT     printf("\033[00m");
#define GREEN       printf("\033[32m");
#define RED         printf("\033[31m");
#define BLUE        printf("\033[94m");
#define HIGHLIGHT   printf("\033[07m\n");
#define SPACE       printf("\n\n");

DATOS obtener_info(char* disp, char* camp, char* file);

DATOS obtener_campos(char* disp, char* camp, FILE* fp, int* flag);

#endif