#include "functions.h"

int main()
{
    key_t key;
    int qid;
    char text[MSGTAM];
    msg miMsg;

    key = ftok(KEYPATH, KEYNUM);
    if (key == (key_t)-1)
    {
        printf("Error al obtener clave para cola mensajes\n");
        exit(-1);
    }
    qid = msgget(key, 0666 | IPC_CREAT);
    if (qid == -1)
    {
        printf("Error al obtener identificador para cola mensajes\n");
        exit (-1);
    }

    //hardcodeo el tipo de mensaje ya que no lo usare para nada
    miMsg.type = 1;

    do
    {
        printf("mensaje: ");
        fgets(text, MSGTAM, stdin);
        strtok(text, "\n");
        strcpy(miMsg.msg, text);
        if((msgsnd(qid, (struct msgbuf*)&miMsg, sizeof(msg)-sizeof(miMsg.type), 0)) == -1)
        {
            perror ("error sending message");
            exit(1);
        }
    } while (strcmp(miMsg.msg, "fin"));

    printf("FIN\n");

    return 0;
}

/*
A. Generar 2 programas que accedan a la misma Message Queue (y la creen en caso
de que la misma no exista). Uno de los programas deberá pedir un texto por teclado
y se lo enviará al otro, que lo imprimirá por pantalla. Los programas finalizan cuando
se recibe el texto FIN. Cuando el programa que escribe en la Message Queue
finalice su ejecución, se debe liberar el recurso.
*/