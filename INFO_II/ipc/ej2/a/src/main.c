/**
 * \file            main.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret
 * \date            Mar 22, 2020
 * \details         Usar MakeFile para compilar y linkear
 */

/*
    Consigna
    A partir de un archivo separado por comas que contiene los siguientes campos: legajo,area,nombre,apellido	
    Leer el archivo ingresado por línea de comando y cargar la información proveniente del archivo en una cola de mensajes.
    Luego finalizar, indicando error en caso de ocurrir.
*/

#include "../inc/functions.h"

int main (int argc, char** argv)
{
    key_t qkey;
    int qid, i = 0;
    qmsg msg;
    FILE* fp;
    char line[TOTAL];

    if(argc == 2)
    {
        /* 1. Doy tiempo a arrancar prog2 */
        sleep(2);

        /* 2. Igual que en cualquier recurso compartido (memoria compartida, semaforos o colas) se obtiene una clave a partir de
            un archivo existente cualquiera y de un entero cualquiera. Todos los procesos que quieran compartir este semaforo,
            deben usar el mismo archivo y el mismo entero */
        qkey = ftok("/bin/ls", 10);
        if (qkey != (key_t)-1)
        {
            /* 3. Se crea la cola de mensajes y se obtiene un identificador para ella. El IPC_CREAT indica que cree la cola de mensajes si no lo está ya.
                El 0600 son permisos de lectura y escritura para el usuario que inicie los procesos. Es importante el 0 delante para que se interprete en octal */
            qid = msgget(qkey, 0600 | IPC_CREAT);
            if (qid != -1)
            {
                fp = fopen(argv[1], "r");
                if(fp != NULL)
                {
                    while(!feof(fp))
                    {
                        /* 4. La ultima vuelta el fgets toma 0 bytes, cuando encuentra el EOF */
                        if(fgets(line, TOTAL, fp) > 0)
                        {
                            build_msg(&msg, line);
                            memset(line, '\0', TOTAL);
                            printf("Estructura %d armada:\ntype\t\t[%ld]\nlegajo\t\t[%s]\narea\t\t[%s]\nnombre\t\t[%s]\napellido\t[%s]\n", ++i, msg.type, msg.legajo, msg.area, msg.nombre, msg.apellido);
                            msgsnd(qid, (struct msgbuf*)&msg, sizeof(msg.legajo)+sizeof(msg.area)+sizeof(msg.nombre)+sizeof(msg.apellido), IPC_NOWAIT);
                        }
                        else
                        {
                            printf("FIN DEL ARCHIVO\n");
                            clean_struct(&msg);
                            msg.type = END;

                            /* 5. Se envia el mensaje. Los parámetros son:
                                - Id de la cola de mensajes.
                                - Dirección al mensaje, convirtiéndola en puntero a (struct msgbuf*)
                                - Tamaño total de los campos de datos de nuestro mensaje, es decir de Dato_Numerico y de Mensaje
                                - Unos flags. IPC_NOWAIT indica que si el mensaje no se puede enviar (habitualmente porque la cola de mensajes esta llena),
                                    que no espere y de un error. Si no se pone este flag, el programa queda bloqueado hasta que se pueda enviar el mensaje */
                            msgsnd(qid, (struct msgbuf*)&msg, sizeof(msg.legajo)+sizeof(msg.area)+sizeof(msg.nombre)+sizeof(msg.apellido), IPC_NOWAIT);
                        }
                    }

                    printf("Cola cargada con todos los usuarios. En 5 segundos la borro...\n");
                    sleep(5);
                    /* 6. Se borra y cierra la cola de mensajes. 15IPC_RMID indica que se quiere borrar. El puntero del final son
                        datos que se quieran pasar para otros comandos. IPC_RMID no necesita datos, así que se pasa un puntero a NULL */
                    msgctl (qid, IPC_RMID, (struct msqid_ds *)NULL);
                    printf("Cola eliminada\n");
                }
                else
                    printf("ERROR [4]\n");
            }
            else
                printf("ERROR [3]\n");
        }
        else
            printf("ERROR [2]\n");
    }
    else
        printf("ERROR [1]\n./<programa> <archivo>\n\n");

    return 0;
}