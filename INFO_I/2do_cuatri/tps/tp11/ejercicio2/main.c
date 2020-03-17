#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int op = 0, status = ERROR, len = 0;
    NODE temp_node, *pile = NULL;

    printf("Bienvenido!\n");

    do
    {
        printf("Seleccione a continuación la operación que desea realizar:\n1 - Insertar\n2 - Eliminar\n3 - Ver ultimo en la pila\n4 - Mostrar\n5 - Fin");
        SPACE
        scanf(" %d", &op);
        
        /* . Decremento 'op' en uno para que su valor concuerde con la posicion de la opcion deseada en el array de funciones */
        op--;

        switch (op)
        {
            case PUSH:      set_temp(&temp_node);
                            status = push(&pile, &len, temp_node);
                break;

            case POP:       status = pop(&pile, &len, &temp_node);

                break;
                
            case OBTAIN:    status = obtain(pile, len, &temp_node);
                break;
                                
            case SHOW:      status = show(pile, len);
                break;

            case END:       SPACE
                            HIGHLIGHT 
                            printf("Fin del programa\n"); 
                            DEFAULT
                            SPACE
                break;
            
            default:        SPACE
                            HIGHLIGHT
                            SET_RED
                            printf("Opcion invalida\n");
                            DEFAULT
                            SPACE
                break;
        }

    /* . El bucle continuara hasta que se ingrese la opcion de finalizacion */
    } while (op != END);

    return status;
}