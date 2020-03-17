/**
 * \file            leer_linea_marcos.c
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

/* 1. prototipo de funcion leer_linea */
int leer_linea(FILE *fp, char *linea);

/* 2. Definicion de la funcion "leer_linea" */

/**
 * \fn      int leer_linea(FILE* fp, char* linea);
 * \brief   Lee linea actual de un archivo pasado como parametro
 * \author  Marcos Goyret
 * \date    Aug 26, 2019
 * \param   'fp' Puntero a archivo
 * \param   'linea' String donde se almacenara la linea leida
 * \return  EXITO(0) | ERROR(-1)
 */
    
int leer_linea(FILE* fp, char* line)
/* 3. Recibo 'fp' y 'linea' como parámetros de la función y retorno el contenido de 'status' */
{
    int i = 0, status = ERROR;

    if (fgets(line, TAM, fp) != NULL)
    {
        for(i=0; i<TAM; i++)
        {
            if(line[i] == '\n')
                line[i] = '\0';
        }
        status = EXITO;
    }
    return status;
}


/* 3. Main para probar funcion de lectura de linea */

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