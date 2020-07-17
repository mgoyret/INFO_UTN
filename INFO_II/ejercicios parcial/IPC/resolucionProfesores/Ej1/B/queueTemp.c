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

#define TIPO_SENSOR		1

typedef struct sensor
{
    long sensor;
    long datos;
}sensor;

int main(void)
{
	sensor m_sensor;
	key_t key;
    int id_queue;

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

    while((msgrcv(id_queue , &m_sensor ,sizeof(m_sensor)-sizeof(m_sensor.sensor), TIPO_SENSOR, IPC_NOWAIT)) != -1)
    {
    	printf("Sensor Temperatura: %ld\n",m_sensor.datos);
    }

	return 0;
}