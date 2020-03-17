#include "functions.h"
int main ()
{
    int cant = 1, valor = 0, i = 0;
    int *notas = NULL, *aux = NULL, *mask = NULL, *res = NULL;

    printf("Ingrese nota:\n");
    scanf("%d", &valor);

    if(valor != 0)
    {
        notas = (int*)malloc(cant*sizeof(int));
        if(notas != NULL)
        {
            notas[0] = valor;

            while(valor != 0)
            {
                printf("Ingrese nota:\n");
                scanf("%d", &valor);
                if(valor != 0)
                {
                    aux = (int*)realloc(notas, (cant + 1)*sizeof(int));
                    if(aux != NULL)
                    {
                        aux[cant] = valor;
                        cant++;
                        notas = aux;
                    }
                    else
                    {
                        free(notas);
                        if(cant > 1) free(aux);
                        return 0;
                    }
                }
            }
            mask = (int*)malloc(cant*sizeof(int));
            if(mask != NULL)
            {
                res = (int*)malloc(cant*sizeof(int));
                if(res != NULL)
                {
                    calcular_vector(notas, aux, cant, res);

                    printf("\nResultado:\n");
                    for(i=0; i<cant; i++)
                    {
                        printf("%d\n", res[i]);
                    }
                    
                    free(mask);
                    free(aux);
                    free(notas);
                    free(res);
                }
                else
                {
                    free(mask);
                    free(notas);
                    free(aux);
                }
                
            }
            else
            {
                free(notas);
                free(aux);
            }
        }
    }
    return 0;
}