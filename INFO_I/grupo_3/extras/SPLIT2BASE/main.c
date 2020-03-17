#include"funciones.h"

int main ()  
{
//    int op=0,funciones[4]={registrarse};
Datos *p;
int largo=0;
int operacion;

    ESPACIO
    RESALTAR
    printf("Bienvenido!");
    BLANCO
    ESPACIO

printf("Registrarse(0)\nIngresar(1)\nImprimir usuarios(2)");
printf("Ingrese la operacion a utilizar:"); 
scanf("%d",&operacion);

switch(operacion)
{
   case 0:  registrarse (); 
   break;
   case 1: Imprimir_Arreglo(p,largo);
}
    printf("\n\n");    
    printf("\nFin del programa\n");

    return 0;
}