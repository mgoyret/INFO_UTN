#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
//van mas includes para que funque, esta subido al aula virtual

int main()
{
    char buf[20] = "                   "; //le deje espacios para q lo q no escribo sea espacio y no basura en binario
    int fd;
    printf("Carga palabra:\n");
    scanf("%s", buf);

    fd = open("prueba", O_WRONLY | O_CREAT);   //para read seria   fd = open("prueba", O_RONLY)
    if(fd != -1)
    {
        write(fd, buf, 20*sizeof(char));        //para read seria write(fd, buf, 20*sizeof(char))
        close(fd);
    }
    else
    {
        printf("Error al abrir/n");
    }
    
    return 0;
}
