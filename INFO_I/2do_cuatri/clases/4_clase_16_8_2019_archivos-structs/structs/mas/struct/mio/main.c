#include "functions.h"

int main()
{
    int op = 0, i = 0, cant = 1;
    user me;
    user all[25];
    user* p = NULL;

    p = &me;
    p = all;

    printf("Digite '1' para ingresar un nuevo usuario, u otra tecla para finalizar: ");
    scanf("%d", &op);

    if(op == 1)
    {
        p = (user*)malloc(sizeof(user)*cant);
        if(p != NULL)
        {
            printf("Ingrese nombre: ");
            scanf(" %s", p[i].name);
            printf("Ingrese clave:  ");
            scanf("%d", &(p[i].key));

            while (op == 1)
            {
                printf("Digite '1' para ingresar un nuevo usuario, u otra tecla para finalizar: ");
                scanf("%d", &op);
                if(op != 1)
                    break;

                cant++;
                i++;
                p = (user*)realloc(p, sizeof(user)*cant);
                if (p != NULL)
                {
                    printf("Ingrese nombre: ");
                    scanf("%s", p[i].name);
                    printf("Ingrese clave:  ");
                    scanf("%d", &(p[i].key));
                }
            }
            for(i=0; i<cant; i++)
            {
                printf("Usuario:\t%s\n", p[i].name);
                printf("Clave:\t\t%d\n", p[i].key);
            }

            free(p);
        }
        else
            printf("Error al pedir memoria\n");
    }
    else
        printf("FIN\n");
    
    return 0;
}
