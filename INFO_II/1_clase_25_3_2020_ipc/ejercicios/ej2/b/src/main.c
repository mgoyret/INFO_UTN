/**
 * \file            main2.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar 22, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

#include "../inc/functions.h"

int main(int argc, char** argv)
{
    key_t Clave1;
    int Id_Cola_Mensajes, op = -1;
    qmsg Un_Mensaje;
    FILE* fp;
    
    if(argc == 2)
    {
        Clave1 = ftok("../key.txt", 10);
        if (Clave1 != (key_t)-1)
        {
            Id_Cola_Mensajes = msgget(Clave1, 0600 | IPC_CREAT);
            if (Id_Cola_Mensajes != -1)
            {
                if ((fp = fopen("output.cvs", "w")) != NULL)
                {
                    clean_struct(&Un_Mensaje);
                    do
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
                        msgrcv (Id_Cola_Mensajes, (struct msgbuf *)&Un_Mensaje, sizeof(Un_Mensaje.legajo)+sizeof(Un_Mensaje.area)+sizeof(Un_Mensaje.nombre)+sizeof(Un_Mensaje.apellido),(long)atoi(argv[1]), IPC_NOWAIT);
                        if (errno != ENOMSG)
                        {
                            Un_Mensaje.apellido[0] = toupper(Un_Mensaje.apellido[0]);
                            Un_Mensaje.nombre[0] = toupper(Un_Mensaje.nombre[0]);
                            fprintf(stdout, "Escribiendo linea [%s-%s-%s]\n", Un_Mensaje.apellido, Un_Mensaje.nombre, Un_Mensaje.legajo);
                            fprintf(fp, "%s-%s-%s\n", Un_Mensaje.apellido, Un_Mensaje.nombre, Un_Mensaje.legajo);
                        }
                    }while(errno != ENOMSG);
                    printf("FIN DE LA COLA\n");
                    /* 3. Se borra y cierra la cola de mensajes. 15IPC_RMID indica que se quiere borrar. El puntero del final son
                        datos que se quieran pasar para otros comandos. IPC_RMID no necesita datos, así que se pasa un puntero a NULL */
                    printf("Desea borrar la cola?\n1 - si\n2 - no");
                    do
                    {
                        printf("\nopcion: ");
                        scanf("%d", &op);
                    } while ((op != 1) && (op != 2));
                    if (op == 1)
                    {
                        if((msgctl(Id_Cola_Mensajes, IPC_RMID, (struct msqid_ds *)NULL)) != -1)
                        {
                            printf("Cola eliminada\n");
                        }
                        else
                        {
                            printf("ERROR msgctl() errno = [%d]\n", errno);
                        }
                    }
                    else
                    {
                        printf("Continuando sin eliminar\n");
                    }
                    
                }
                else
                {
                    printf("ERROR fopen\n");
                } 
            }
        }
    }
    else
    {
        printf("ERROR [1]: ./<programa> <codigo de area>\n");
    }
    
    return 0;
}