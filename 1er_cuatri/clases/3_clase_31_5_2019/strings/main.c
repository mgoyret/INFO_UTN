
//un string es un array de letras (char)

#include "functions.h"

int main ()
{
    char palabra1 [20];
    char palabra2 [20];
    int cant, igualdad;

    printf("Cargar palabra: ");
    scanf("%s", palabra1);   // &palabra[0] = palabra, xq el nombre solo dice "direccion de comienzo de este vector"
    cant = cuenta_letras(palabra1);

    printf("La palabra ingresada es  '%s'\n", palabra1);
    printf("Tiene %d letras\n", cant);

    printf("Cargar nueva palabra:   ");
    scanf("%s", palabra2);

    printf("La palabra ingresada es  '%s'\n", palabra2);

    igualdad = comparar_palabras(palabra1, palabra2);

    if(igualdad == IGUALES) printf("Son iguales.\n");
        else printf("Son distintas.\n");

    return 0;
}