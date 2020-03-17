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
#include <sys/ioctl.h>
#include <stdio_ext.h>
#include <dirent.h>
#include <sys/socket.h>
#include <sys/types.h>


//logfile
#define ALGO



#define DEFAULT     printf("\033[00m");
#define BLANCO      printf("\033[00m");
#define VERDE       printf("\033[32m");
#define ROJO        printf("\033[31m");
#define AZUL        printf("\033[94m");
#define INVISIBLE   printf("\033[08m");
#define RESALTAR    printf("\033[07m\n");
#define ESPACIO     printf("\n\n");

#define TAM 600
#define EXITO  0 
#define ERROR -1
#define ARRA 30
#define LOG
#define DBG 50
#define NAME_LEN 30


/*
#define DEFAULT1     "\033[00m"
#define BLANCO1      "\033[00m"
#define VERDE1       "\033[32m"
#define ROJO1        "\033[31m"
#define AZUL1        "\033[94m"
#define INVISIBLE1   "\033[08m"
#define RESALTAR1    "\033[07m\n"
#define ESPACIO1     "\n\n"
*/


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


/* Funciones principales */
int ingresar(Datos,int);
int registrarse(Datos,int);
int eliminar(Datos,int);
int salir();

/* Funciones secundarias */
void Imprimir_Arreglo(Datos *,int );
int cargar_usuario(FILE * ,Datos **);
int usuario_existe(Datos *,int ,char *,int *);
void ordenar(Datos **, int ); 
void swap(Datos **, Datos **);
void cargar_archivo(Datos *,int );
void log_msg(Nivel_Log , const char*,int,const char*);


/* Funciones en main */
void clienteIngresado(Datos,int,char *);


/* Play */
int mostrar_directorios(char* nombre_dir, int clientSocketFd);

int mostrar_archivos(char* nombre_dir, int clientSocketFd);