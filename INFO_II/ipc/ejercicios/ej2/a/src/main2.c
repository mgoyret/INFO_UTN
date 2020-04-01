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
                
                /* 2. El 3er parametro esta mal. no se si devo mandar los strlen de cada campo, o el espacio q tiene en la estructura. 
                    Osea si le reserve 30bytes, y le escribi "hola\0" no se si debo poner 30 o 5 */
                msgrcv (Id_Cola_Mensajes, (struct msgbuf *)&Un_Mensaje, sizeof(Un_Mensaje.legajo)+sizeof(Un_Mensaje.area)+sizeof(Un_Mensaje.nombre)+sizeof(Un_Mensaje.apellido), 0, 0);
                printf("Recibido mensaje tipo %ld\n", Un_Mensaje.type);
                if(Un_Mensaje.type != END)
                    printf("legajo [%s]\narea [%s]\nnombre [%s]\napellido [%s]\n\n", Un_Mensaje.legajo, Un_Mensaje.area, Un_Mensaje.nombre, Un_Mensaje.apellido);
            }
            printf("FIN DE LA COLA\n");
            /* 3. Se borra y cierra la cola de mensajes. 15IPC_RMID indica que se quiere borrar. El puntero del final son
                datos que se quieran pasar para otros comandos. IPC_RMID no necesita datos, así que se pasa un puntero a NULL */
            msgctl (Id_Cola_Mensajes, IPC_RMID, (struct msqid_ds *)NULL);
            printf("Cola eliminada\n");

        }
    }
    return 0;
}