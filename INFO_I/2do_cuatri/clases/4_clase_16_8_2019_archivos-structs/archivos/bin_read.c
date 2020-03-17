/*
    lee archivo binario
*/

#include <stdio.h>
#define TAM 100

int main (int argc, char** argv)
{
    FILE* fp;
    char vec[TAM], i = 0;
    int devolucion;

    if(argc == 2)
    {
        fp = fopen(argv[1], "rb");
        if(fp != NULL)
        {
            devolucion = fread(vec, sizeof(char), TAM, fp);   //devuelve cantidad de bloques leidos
            for(i=0; i<TAM; i++)
            {
                printf("%c\n", vec[i]);
            }
            fclose(fp);
        }
    }
    else
    {
        printf("Error al usar el programa\n");
    }

    return 0;
}