#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#define     TAM     20
#define     ERROR   -1
#define     HIGHLIGHT   printf("\033[07m");
#define     DEFAULT     printf("\033[00m");

float calcular(char* patron, char* medir);

void obtener_valores(char* linea, int *x, int*y,int *valor);