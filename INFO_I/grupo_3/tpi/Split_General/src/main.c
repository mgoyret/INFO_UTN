#include "funciones/funciones.h"

int main ()  
{
    int (*funciones[4])() = {ingresar, registrarse,eliminar ,salir};
    int op = 0, status = EXITO, salida=ERROR;

    ESPACIO
    RESALTAR
    printf("Bienvenido!");
    BLANCO
    ESPACIO
    do
    {
        printf("\nSeleccione a continuación la operación que desea realizar:\n1 - Ingresar\n2 - Registrarse\n3 - Eliminar\n4 - Salir\n");
        scanf("%d", &op);
        if (0<op && op<5)
        {
            /* 1. Al ejecutarce funciones[op -1], esa subposicion corresponde con el punto de entrada de
            una determinada funcion, y al nombrarla, esta se ejecuta */
            status = funciones[op - 1]();
        
            if (op==1 && status==EXITO)
            {
                status = mostrar_directorios("MEDIA");
            }
            if (op==4)
            {
                salida=EXITO;
            }
            
        } 
    } while (salida == ERROR);
    RESALTAR 
    AZUL
    printf("Fin del programa");
    BLANCO
    return 0;
}
