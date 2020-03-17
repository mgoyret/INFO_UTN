#include "functions.h"

int main()
{
    int cant = 0, i = 0;
    user me;
    user all[25];
    user* p = NULL;

    p = &me;
    p = all;

    printf("Cargue cantidad de usuarios a registrar:    ");
    scanf("%d", &cant);

    if(cant > 0)
    {
        p = (user*)malloc(sizeof(user)*cant);
        if(p != NULL)
        {
            for (i=0; i<cant; i++)
            {
                printf("Ingrese nombre: ");
                scanf("%s", p[i].name); //p[i] porque es el primer dato del tipo 'user'.  P apunta a la cadena de datos del tipo 'user'
                //scanf("%s", (*(p+i)).nombre)
                //scanf("%s", (p+i)->nombre)
                printf("Ingrese clave:  ");
                scanf("%d", &(p[i].key));
                //scanf("%d", &(*(p+i).key));
                //scanf("%d", &((p+i)->key))
            }
            printf("\n");
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
        printf("Cantidad invalida\n");
    
    return 0;
}