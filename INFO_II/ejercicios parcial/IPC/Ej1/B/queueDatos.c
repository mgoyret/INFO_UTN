#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct datos
{
    char tipo_sensor;
    long data;
}datos;

typedef struct sensor
{
    long sensor;
    long datos;
}sensor;

int main(int argc, char *argv[])
{
    FILE *f;
	sensor m_sensor;
    datos m_datos;
	key_t key;
    int id_queue;

    if(argc != 2)
    {
        perror("No hay archivo de datos");
        exit(1);
    }

    if ((key = ftok("queueDatos.c",'N')) == -1)
    {
        perror ("error creating key");
        exit(1);
    }
    if ((id_queue = msgget(key , 0664 | IPC_CREAT)) == -1)
    {
        perror ("error creating message queue id");
        exit(1);
    }

    if((f = fopen(argv[1], "rb")) == NULL)
    {
        perror("errro al abrir el archivo");
        exit(1);
    }

    fread(&m_datos, sizeof(m_datos), 1, f);
    while(!feof(f))
    {
        m_sensor.sensor = (long)m_datos.tipo_sensor;
        m_sensor.datos  = m_datos.data;

        printf("Se envio sensor: %ld con valor: %ld\n",m_sensor.sensor, m_sensor.datos);
        
        if((msgsnd(id_queue , &m_sensor ,sizeof(m_sensor)-sizeof(m_sensor.sensor),0)) == -1)
        {
            perror ("error sending message");
            exit(1);
        }
        fread(&m_datos, sizeof(m_datos), 1, f);
    }
    fclose(f);

    printf("Presione una tecla para eliminar la cola luego de ser leida");
    getchar();

    if (msgctl(id_queue, IPC_RMID, NULL) == -1) 
    {
        perror("error deleting message queue");
        exit(1);
    }

	return 0;
}