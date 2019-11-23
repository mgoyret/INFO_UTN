#include "functions.h"

int main()
{
    float error = 0;

    printf("Hola desde el main\n");

    error = calcular("patron", "medida");

    printf("Promedio de error absoluto: '%f'\n", error);

    return 0;
}