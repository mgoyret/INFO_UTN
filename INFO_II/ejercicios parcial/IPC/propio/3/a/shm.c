#include <sys/types.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEYFILE "key"
#define KEYNUM  0

int main (int argc, char** argv)
{
    int shmid, key, i, size=0;
    FILE* fp = NULL;
    char* shmP = NULL;
    char c;

    if(argc == 2)
    {
        /* 1. Abro archivo con texto */
        fp = fopen(argv[1], "r");
        if(fp == NULL)
        {
            printf("Error fopen()\n");
            exit(-1);
        }else printf("Archivo: %s\n", argv[1]);

        /* 2. Cuento cantidad de caracteres en el archivo, para pedir memoria y
                cargar su contenido en una variable para asi manejarlo mas facil */
        while(!feof(fp))
        {
            c = fgetc(fp);
            if(c != EOF)
                size += 1;
        }
        rewind(fp); // Llevo al fp al inicio del archivo
        printf("Size: %d\n", size);
        
        /* 3. Creo clave */
        key = ftok(KEYFILE, KEYNUM);
        if(key == -1)
        {
            printf("Error ftok()\n");
            exit(-1);
        }
        /* 4. Creo o me uno a shared memory */
        shmid = shmget(key, size, IPC_CREAT | 0777);
        if(shmid == -1)
        {
            printf("Error shmget()\n");
            exit(-1);
        }
        /* 5. Me acoplo a la memoria */
        shmP = (char*)shmat(shmid, 0, 0);
        if(shmP == (void*)-1)
        {
            printf("Error shmat()\n");
            exit(-1);
        }
        ///////// MEMORIA DISPONIBLE ////////////
        /* 6. Escribo en memoria */
        printf("\nEscribiendo memoria\n\n");
        for(i=0; i<size; i++)
        {
            shmP[i] = fgetc(fp);
            printf("%c", shmP[i]);
        }

        /* 7. Leyendo memoria */
        printf("\nLeyeno memoria\n\n");
        for(i=0; i<size; i++)
            printf("%c", shmP[i]);

        /* 8. Me desacoplo de la memoria y la borro */
        if(shmdt((char*)shmP) == -1)
        {
            printf("Error shmdt()\n");
            exit(-1);
        }
        if(shmctl(shmid, IPC_RMID, NULL) == -1)
        {
            printf("Error shmctl()\n");
            exit(-1);
        }

        printf("FIN\n");

    }else
        printf("Error - Cantidad de parametros no soportada\n");
    return 0;
}


/*
A. Realizar un programa que reciba un texto ingresado por consola y lo cargue en una
Shared Memory.
*/