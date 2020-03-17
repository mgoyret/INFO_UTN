#include "functions.h"
int main()
{
    int a = 8, b = 3;
    float resultado;
    int aux;

    aux = division(a, b, &resultado);       //si tiene &, se modificara su contenido xq pasa 
    if(aux==BIEN)                           //direccion, en vez de la copia de contenido
    {
        printf("res = %f", resultado);
    }
    return 0;
}