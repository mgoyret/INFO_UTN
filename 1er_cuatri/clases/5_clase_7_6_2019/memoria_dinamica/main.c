/**
 *  Crea un array de numeros, que lo va agrandando a medida que agregamos las notas, no se declara un tamano inicial.
 **/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int tam, i;
    int* aux = NULL;
    int* buf = NULL;
    int nota;

    printf("Cargue nota 1");
    scanf("%d", &nota);
    
    if(nota != 0)
    {
        aux = (int*)malloc(tam*sizeof(int));    //aux = &aux[0]
        if(aux != NULL)
        {
            aux[0] = nota;  //aux[o] = *aux
            while(nota != 0)
            {
                printf("Cargue nota %d:    \n", (tam + 1));
                scanf("%d", &nota);
                if(nota != 0)
                {
                    tam++;
                    buf = (int*)realloc(aux, tam*sizeof(int));  //recibe la variable a realocar, y el nuevo tamano a darle
                    if(buf != NULL)
                    {
                        buf[tam -1] = nota;
                        aux = buf;
                    }
                }
            }
            //hago algo
            free(aux);
            free(buf);
        }
    }
    return 0;
}