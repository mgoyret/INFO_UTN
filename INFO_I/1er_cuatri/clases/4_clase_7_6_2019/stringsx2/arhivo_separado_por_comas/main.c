#include "functions.h"

int main ()
    {
        char palabra[30];

        printf("Ingrese el registro:    \n");
        scanf("%s", palabra);  //no me importan los espacios asique no unso fgets()

        dividir_palabra(palabra);

        return 0;
    }