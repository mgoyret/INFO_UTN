#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int* vec = NULL;
    int* aux = NULL;
    int i = 0, val = 0, cant = 0;

    printf("ingrese numero\n");
    scanf("%d", &val);

    if(val != 0)
    {
        vec = (int*)malloc((cant + 1)*sizeof(int));
        if(vec != NULL)
        {
            vec[cant] = val;
            cant++;
            while (val != 0)
            {
                printf("ingrese numero\n");
                scanf("%d", &val);
                if(val != 0)
                {
                    aux = (int*)realloc(vec, (cant + 1)*sizeof(int));
                    if(aux != NULL)
                    {
                        aux[cant] = val;
                        cant++;
                        vec = aux;
                    }
                }
                else
                {
                	printf("Se ingreso '0'\n");
                }
                
            }
        }
    }free(vec);

    printf("\n");
    for ( i = 0; i < cant; i++)
    {
        printf("%d\n", vec[i]);
    }
    printf("\n");
    
    return 0;
}
