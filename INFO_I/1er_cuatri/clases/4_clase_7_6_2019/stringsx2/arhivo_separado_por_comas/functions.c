#include "functions.h"

void dividir_palabra(char* p)
{
    char* token;

    token = strtok(p, ",");   //devuelve NULL si no encontro coma, y si la encontro, devuelve la primera palabra hasta la primera coma
    while(token != NULL)
    {
        printf("%s\n", token);        //al invocarla por segunda vez, si el primer argumento = NULL,
        token = strtok(NULL, ",");    //le asigna ahi lo que le asigne antes, osea "p", pero desde la coma    
    }
}