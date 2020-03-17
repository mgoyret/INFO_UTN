/*
    escribe archivo en binario, segun el valor ascii del numero ingresado
*/

#include <stdio.h>
#define TAM 5

int main (int argc, char** argv)
{
    FILE* fp;
    int vec[TAM], i = 0;

    if(argc == 2)
    {
        for(i=0; i<TAM; i++)
        {
            printf("Carga dato\n");
            scanf("%d", &vec[i]);
        }

        fp = fopen(argv[1], "wb"); //'wb' es para abrir archivo en binario. Si archivo no existe, lo crea
        if(fp != NULL)
        {
            fwrite(vec, sizeof(int), TAM, fp); //1- origen /2- tamano de cada elemento /3- cantidad de elementos /4- destino
            fclose(fp);                         //devuelve cantidad de bloques escritos
        }
    }
    else
    {
        printf("Error al usar el programa\n");
    }

    return 0;
}