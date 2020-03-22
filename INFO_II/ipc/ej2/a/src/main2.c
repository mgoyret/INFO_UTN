/**
 * \file            main2.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar 22, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

#include "../inc/functions.h"

int main()
{
    key_t Clave1;
    int Id_Cola_Mensajes;
    qmsg Un_Mensaje;
    
    Clave1 = ftok("/bin/ls", 10);
    if (Clave1 != (key_t)-1)
    {
        Id_Cola_Mensajes = msgget(Clave1, 0600 | IPC_CREAT);
        if (Id_Cola_Mensajes != -1)
        {
            clean_struct(&Un_Mensaje);
            while(Un_Mensaje.type != END)
            {

                /* 1. Se recibe un mensaje del otro proceso. Los parámetros son:
                    - Id de la cola de mensajes.
                    - Dirección del sitio en el que queremos recibir el mensaje, convirtiéndolo en puntero a (struct msgbuf *).
                    - Tamaño máximo de nuestros campos de datos.
                    - Identificador del tipo de mensaje que queremos recibir. En este caso se quiere un mensaje de tipo 1, que es el que envia el proceso cola1.c
                    - flags. En este caso se quiere que el programa quede bloqueado hasta que llegue un mensaje de tipo 1. Si se pone 17IPC_NOWAIT, se devolvería
                        un error en caso de que no haya mensaje de tipo 1 y el programa continuaría ejecutándose. */
                msgrcv (Id_Cola_Mensajes, (struct msgbuf *)&Un_Mensaje, sizeof(Un_Mensaje.legajo)+sizeof(Un_Mensaje.area)+sizeof(Un_Mensaje.nombre)+sizeof(Un_Mensaje.apellido), 0, 0);
                printf("Recibido mensaje tipo %ld\n", Un_Mensaje.type);
                if(Un_Mensaje.type != END)
                    printf("legajo [%s]\narea [%s]\nnombre [%s]\napellido [%s]\n\n", Un_Mensaje.legajo, Un_Mensaje.area, Un_Mensaje.nombre, Un_Mensaje.apellido);
            }
            printf("FIN DE LA COLA\n");
        }
    }
    return 0;
}