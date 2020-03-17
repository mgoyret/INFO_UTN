/**
 * Marcos Goyret
 * Practica 2do parcial Info1 UTN 29/11/2019
 * Struckts - Files
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 30
#define LINE 100

typedef struct person
{
    char name[TAM];
    char lastname[TAM];
    long dni;
}person;

int main()
{   
    person* p;
    FILE* fp;
    char line[LINE], *token;
    int cnt = 0;

    fp = fopen("clients.csv", "r");
    if (fp != NULL)
    {
        printf("Archivo abierto\n");
        while (!feof(fp))
        {

            fgets(line, LINE, fp);
            printf("Obtuve linea '%s' y eof es %d\n", line, feof(fp));
            /* No se por que al leer la ultima linea no encuentra el eof, vuelve a leer una vez mas, solo la primera cosa de la
                ultima linea (ya leida en la vuelta anterios) hasta la primera coma. Me imagino que sera porque el fgets no esta
                tomando el ultimo '\n' entonces el fp no esta en el EOF pero no se. Si la linea es < 10 entonces no es una persona completa */
            if (strlen(line) > 10)
            {
                if (cnt == 0)
                {
                    p = (person*)malloc(sizeof(person)*(++cnt));
                }
                else
                {
                    p = (person*)realloc(p, sizeof(person)*(++cnt));
                }
                printf("%d persona/s cargadas\n", cnt);

                /* Cargando linea en estructura */
                token = strtok(line, ",");
                strcpy(p[cnt-1].name, token);
                token = strtok(NULL, ",");
                strcpy(p[cnt-1].lastname, token);
                token = strtok(NULL, "\n");
                p[cnt-1].dni = atol(token);

                /* Muestro persona cargada */

                printf("Persona %d\nName:\t'%s'\nL.Name\t'%s'\nDNI\t'%ld'\n\n", cnt, p[cnt-1].name, p[cnt-1].lastname, p[cnt-1].dni);
            }
        }
        printf("Fin de archivo\n");
    
        fclose(fp);   
    }
    else
    {
        printf("ERROR; fopen()\n");
    }
    
    return 0;
}