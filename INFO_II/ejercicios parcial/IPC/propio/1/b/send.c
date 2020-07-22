#include "functions.h"

int main(int argc, char** argv)
{
    key_t key;
    int qid;
    msg miMsg;
    struct datos data;
    FILE* fp;

    if(argc == 2)
    {
        fp = fopen(argv[1], "rb");
        if(fp == NULL)
        {
            printf("Error al abrir archivo con mediciones\n");
            exit(-1);
        }

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
            fread(&data, sizeof(struct datos), 1, fp);
            miMsg.type = (long)data.tipo_sensor;
            miMsg.data = data.data;
            if((msgsnd(qid, (struct msgbuf*)&miMsg, sizeof(msg)-sizeof(miMsg.type), 0)) == -1)
            {
                perror ("error msgsnd\n");
                exit(1);
            }else
                printf("Envie: tipo [%ld] - data [%ld]\n", miMsg.type, miMsg.data);

        }while(!feof(fp));
        fclose(fp);

        printf("Presione una tecla para terminar. La cola la elimina el receptor");
        getchar();
        printf("FIN\n");
    }else
        printf("Error de argumentos\n");

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
