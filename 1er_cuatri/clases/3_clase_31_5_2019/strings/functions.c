#include "functions.h"

int cuenta_letras(char*p)  //strlen //p = palabra 
{
    int cant = 0;

    while(p[cant] != '\0')   //palabra[cant] = *(palabra + cant)
    {
        cant++;
    }

    return cant;
}


int comparar_palabras(char* palabra1, char* palabra2)   //strcmp
{
    int cantp1 = 0, cantp2 = 0;
    int res = DISTINTAS;
    int aux;

    cantp1 = cuenta_letras(palabra1);  //&palabra[0]
    cantp2 = cuenta_letras(palabra2);        //&q[0]

    if(cantp1 != cantp2)
        return res;

    for (aux=0;aux<cantp1;aux++)
    {
        if(palabra1[aux] != palabra2[aux])
        return res;
    }
    res = IGUALES;

    return res;
}


void asignar_palabra(char*origen, char*destino)   //strcpy
{
    int cant, i;

    cant = cuenta_letras(origen);
    for(i=0;i<cant;i++)
    {
        destino[i] = origen[i]; //le va a faltar el "\0", porque copia solo la cantidad de letras
    }
    destino[i] = '\0';
}