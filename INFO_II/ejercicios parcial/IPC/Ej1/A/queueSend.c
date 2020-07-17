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
	char text[TAM_MSG];
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

    // Como solo se envian datos, fijo un solo tipo de mensaje
    msg.mtype = 1;

    do{
    	printf("Mensaje a enviar: ");
    	fgets(text, TAM_MSG,stdin);
    	// Recordar que fgets() guarda el caracter de nueva linea \n al final
    	// para eliminarlo podes usar strtok(), aunque no funcionara si solo
    	// mandamos cadenas vacias, es decir, presionamos enter
    	strtok(text, "\n");	// Elimino el \n 
    	strcpy(msg.msg, text);
    	if((msgsnd(id_queue , &msg ,sizeof(msg)-sizeof(msg.mtype),0)) == -1)
        {
            perror ("error sending message");
            exit(1);
        }

    }while(strcmp(text,"FIN") != 0);

	return 0;
}