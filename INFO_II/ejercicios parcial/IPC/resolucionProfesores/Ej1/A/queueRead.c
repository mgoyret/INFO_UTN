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

#define TAM_MSG		280

typedef struct mymsg
{
    long mtype;
    char msg[TAM_MSG];
}mymsg;

int main()
{
	mymsg msg;
	key_t key;
    int id_queue;

    if ((key = ftok("queueSend.c",'N')) == -1)
    {
        perror ("error creating key");
        exit(1);
    }
    if ((id_queue = msgget(key , 0664 | IPC_CREAT)) == -1)
    {
        perror ("error creating message queue id");
        exit(1);
    }

    do{
    	if((msgrcv(id_queue , &msg ,sizeof(msg)-sizeof(msg.mtype),0,0)) == -1)
        {
            perror ("error reading message");
            exit(1);
        }
        printf("Mensaje recibido: %s\n",msg.msg);

    }while(strcmp(msg.msg,"FIN") != 0);

    if (msgctl(id_queue, IPC_RMID, NULL) == -1) 
    {
        perror("error deleting message queue");
        exit(1);
    }

	return 0;
}