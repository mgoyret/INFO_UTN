/**
 * \file            mycat.c
 * \brief           Programa definido por el usuario
 * \author          Marcos Goyret
 * \date            Aug 26, 2019
 * \details         Usar MakeFile para compilar y linkear
 * \man             ./ejecutable <nombre de archivo>
 */

#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *fp;
    
    if(argc == 2)
    {
        fp = fopen(argv[1], "r");
        if (fp != NULL)   
        {
            while(!feof(fp))
            {   
                printf("%c", fgetc(fp));
            }
            fclose(fp);
        }
        else
        {
            printf("Error al abrir archivo\n");
        }
    }
    else
    {
        printf("Cantidad de argumentos erronea\n");
    }
    return 0;
}