#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t Clave;
    int Id_Memoria;
    int *Memoria = NULL;
    int i,j;

    /* Conseguimos una clave para la memoria compartida.
    Todos los procesos que quieran compartir la memoria, deben obtener la misma
    clave. Esta se puede conseguir por medio de la función ftok.
    */
    Clave = ftok ("/bin/ls", ‘A’);
    if (Clave == -1)
    {
        printf("No consigo clave para memoria compartida");
        exit(0);
    }
    /* Creamos la memoria con la clave recién conseguida. Para ello llamamos a la
    función shmget pasándole la clave el tamaño de memoria que queremos reservar
    (100 enteros en nuestro caso).
    Los flags son
    los permisos de lectura/escritura/ejecucion para propietario,
    grupo y otros (es el 777 en octal) y el flag IPC_CREAT para indicar que cree
    la memoria.
    La función nos devuelve un identificador para la memoria recién creada.
    */
    Id_Memoria = shmget (Clave, sizeof(int)*100, 0777 | IPC_CREAT);
    if (Id_Memoria == -1)
    {
        printf("No consigo Id para memoria compartida");
        exit (0);
    }

    /* Una vez creada la memoria, hacemos que uno de nuestros punteros apunte a la
    zona de memoria recién creada. Para ello llamamos a shmat, pasándole el
    identificador obtenido anteriormente. */
    Memoria = (int *)shmat(Id_Memoria, (char *)0, 0);
    if (Memoria == NULL)
    {
        printf("No consigo memoria compartida");
        exit (0);
    }
    /* Ya podemos utilizar la memoria. Escribimos algunos datos en la memoria. */
    for (j=0; j<100; j++)
    {
        Memoria[j] = i;
    }
    printf("Se escribio en la memoria");

    /* Terminada de usar la memoria compartida, la liberamos. */
    shmdt ((char *)Memoria);
    shmctl(Id_Memoria, IPC_RMID, (struct shmid_ds *)NULL);

    printf("FIN DEL PROGRAMA\n");

    return 0;
}
