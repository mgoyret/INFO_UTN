#include "functions.h"

int main(int argc, char* argv[])
{
    key_t key;
    msg miMsg;
    int qid;

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

    while(msgrcv(qid, (struct msgbuf*)&miMsg, sizeof(msg)-sizeof(miMsg.type), PRESION, IPC_NOWAIT) != -1)
        printf("recivi: tipo [%ld] - data [%ld]\n", miMsg.type, miMsg.data);   


    printf("FIN\n"); 

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