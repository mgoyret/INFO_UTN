#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <time.h>
#include<math.h>

#define BLANCO      printf("\033[00m");
#define VERDE       printf("\033[32m");
#define ROJO        printf("\033[31m");
#define INVISIBLE   printf("\033[08m");
#define RESALTAR    printf("\033[07m\n");
#define ESPACIO     printf("\n\n");
#define TAM 200
#define CANT 10
#define EXITO  0 
#define ERROR -1
#define ARRA 30


//Definimos la estructura
typedef struct nombre
{
    char usuario[30];
    char contra[30];
    time_t tiempo;
}Datos;

void Imprimir_Arreglo(Datos *,int );
int cargar_usuario(FILE * ,Datos *);
int registrarse ();