/**
 * \file            escribir_linea_marcos.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Sep 01, 2019
 * \details         Usar MakeFile para compilar y linkear
 */


#include <stdio.h>
#include <string.h>

#define TAM 100
#define EXITO 0
#define ERROR -1

/* 1. prototipo de funcion escribir_linea */
int escribir_linea(FILE* fp, const char* line2);

/* 2. Definicion de la funcion "escribir_linea" */

/**
 * \fn      int esribir_linea(FILE* fp, const char* linea);
 * \brief   
 * \author  Marcos Goyret
 * \date    Aug 26, 2019
 * \param   'fp' Puntero a archivo
 * \param   'linea' String donde se almacenara 
 * \return  EXITO(0) | ERROR(-1)
 */

int escribir_linea(FILE* fp, const char* line)
{
/* 3. Recibo 'fp' y 'linea' como parámetros de la función y retorno el contenido de 'status' */
    int  status = ERROR;

    if (fputs(line, fp) != EOF)
    {
        fseek(fp, -1, SEEK_END);
        fputc('\n', fp);
        fflush(fp);
        status = EXITO;
    }
    return status;
}



/* 4. Main para probar funcion de lectura de linea */

int main(int argc, char** argv)
{
    FILE *fp;
    char line[100], line2[100];

    if(argc == 2)
    {
        fp = fopen(argv[1], "a+");
        if(fp != NULL)
        {
            while (feof(fp) == 0)
            {
                leer_linea(fp, line);
                if(feof(fp)==0)printf("Linea leida:    %s\n", line);
            }
            fclose(fp);
        }
        else
        {
            printf("error al abrir archivo\n");
        }
    }
    else
    {
        printf("Cantidad de argumentos erronea\n");
    }
    return 0;
}