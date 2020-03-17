
#include<stdio.h>
#include<string.h>
#include <ctype.h>
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


//Definimos la estructura
typedef struct nombre
{
    char usuario[30];
    char contra[30];
}Datos;

void Imprimir_Arreglo(Datos *p,int largo)
{
    int i;  
    for(i=1;i<=largo;i++)
    {
        printf("\nvector[%d]=Usuario: %s\n",i,p[i].usuario);
        printf("\nvector[%d]=Contraseña %s\n\n",i,p[i].contra);
    }
}
/*Cerrar_Archivo()
{

}
Agregar_a_Arreglo()
{

}
EliminarDeArreglo()
{

}
*/