#include "functions.h"

int main ()
{
    char origen[20];  //tener en cuenta en el tamano del vector, que el '\0' ocupa un lugar
    char destino[100];

    printf("Cargar palabra 1:  \n");
    scanf("%s", origen);        //%s es el unico que escanea y asigna todo de una

    printf("Cargar palabra 2:   \n");
    scanf("%s", destino);

    unir_palabras(destino, origen);

    printf("%s\n", destino);

    return 0;
}