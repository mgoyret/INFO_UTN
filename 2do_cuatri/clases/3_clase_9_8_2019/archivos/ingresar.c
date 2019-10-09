/**
 * escribir palabra,palabra\n 
 **/


#include <stdio.h>

int main(int argc, char **argv)
{
    char nombre[20];
    char clave[20];
    char linea[100];
    FILE *fp;

    if(argc == 2)
    {
        fp = fopen(argv[1], "a+");
        if(fp != NULL)
        {
            printf("Cargar usuario: ");
            scanf("%s", nombre);
            printf("Cargar clave:   ");
            scanf("%s", clave);
            while(feof(fp) == 0)    //feof devuelve 0 si el archivo no termino, y distinto de 0 si se llego al final del arhcivo
            {
                fgets(linea, 100, fp);
                if(strstr(linea, nombre) != NULL)
                {
                    printf("Nombre de usuario ya utilizado\n");
                }
                else
                {
                    fprintf(fp, "%s, %s\n", nombre, clave); //lo escribe en un flujo. Si hago sprintf lo esribe en un string
                    fclose(fp);
                    //no se si aca va un break
                }
            }
        }
        else
        {
            printf("Error al abrir el archivo\n");
        }
        
    }
    else
    {
        printf("Cantidad de argumentos invalida\n");
    }

    return 0;
}