/**
 * funcion cat
**/


#include <stdio.h>

int main (int argc, char **argv)  //recibe (cantidad de argumentos, valor de los argumentos)
{
    char aux;
    FILE *fp;

    if(argc == 2)
    {
        fp = fopen("argv[1]", "r"); /* fopen abre archivo, y realiza operacion dada (r = read; w = write; etc). Devuelve puntero al archivo, o NULL */
    }

    if (fp != NULL)
    {
        while (feof(fp) == 0)  //cuando devuelve cero es que hay caracteres. Si no encuentra caracter devuelve != 0
        {
            aux = fgetc(fp);    //fgetc imprime un caracter del archivo flujo pasado como parametro
            fprintf(stdout, "%c", aux);
        }

        fclose(fp);
    }
    else
    {
        printf("\nError al abrir el archivo\n");
    }

    return 0;
}