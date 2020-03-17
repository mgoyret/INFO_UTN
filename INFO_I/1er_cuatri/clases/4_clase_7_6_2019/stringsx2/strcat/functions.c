#include "functions.h"

//esta funcion equivale a la funcion strcat(char*, const char*)

void unir_palabras(char* p, char* q)  // p = destino // q = destino
{
    int aux;
    int aux_destino;
    int i;

    aux = strlen(q);  //strlen recibe un CONST CHAR*
    aux_destino = strlen(p);

    for(i=aux_destino; i<(aux+aux_destino); i++ )
    {
        //trabajo a p y q como vectores.
        p[i] = q[i-aux_destino];   //en el for 'i' empieza con 'aux_destino' como primera posicion, 
                                   //en 'q' esa debe ser la posicion '0', asique le resto el mismo valor
    }                              //De esta manera, la posicion '5' del destino sera la '1' del origen
    p[i] = '\0';
}