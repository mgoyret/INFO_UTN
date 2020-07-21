#include "functions.h"

int main(int argc, char* argv[])
{
    key_t key;
    int qid;
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

    do
    {
        if((msgrcv(qid, (struct msgbuf*)&miMsg, sizeof(msg)-sizeof(miMsg.type), 0, 0)) > 0)
        printf("recivi: %s\n", miMsg.msg);   
    } while (strcmp(miMsg.msg, "fin"));
    if(msgctl(qid, IPC_RMID, NULL)==-1)
    {
        perror("error deleting message queue\n");
        exit(1);
    }else
        printf("FIN - cola eliminada\n"); 

    return 0;
}

/*
B. Realizar un programa que lea de un archivo (cuyo path se recibe por línea de
comandos) los valores de 3 sensores. Los mismos se encuentran grabados en el
archivo con el siguiente formato:
struct datos {
    char tipo_sensor;
    long data;
}
En donde los tipos de sensor pueden ser:
    a. Tipo 1: Sensor de temperatura
    b. Tipo 2: Sensor de presión
    c. Tipo 3: Sensor de humedad
Por cada dato leído, se deberá mandar por una Message Queue el dato del sensor,
con el campo mtype que se corresponda con el tipo de sensor al cual se hace
referencia.
Realizar luego 3 programas similares (LectorTemperatura, LectorPresion,
LectorHumedad) que lean los datos de la Message Queue que les correspondan
(solo los que tengan el campo mtype igual al tipo de sensor del programa) y los
impriman por pantalla.
*/