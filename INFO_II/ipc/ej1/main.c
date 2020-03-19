#include "functions.h"

int main ()
{
    int pid, fd1[2], fd2[2], i = on;
    char msg[MSG_MAX];

    if ((pipe(fd1) != -1) && (pipe(fd2) != -1))
    {
        pid = fork();
        
        
        
        //////////////////////////////////////////////////////////////
        if (pid > 0) //PADRE
        {
            printf("PADRE: inicio con PID [%d]\n", getpid());

            close(fd1[lectura]);
            close(fd2[escritura]);

            while(i)
            {
                memset(msg, '\0', MSG_MAX);
                printf("\n\nPADRE: escriba para mandar al hijo: ");
                scanf("%s", msg);
                write(fd1[escritura], msg, MSG_MAX);
                memset(msg, '\0', MSG_MAX);

                read(fd2[lectura], msg, MSG_MAX);
                printf("\nPADRE: me llego del hijo: [%s]\n", msg);
            }

            wait(NULL);
            printf("PADRE: FIN\n");
            close(fd1[escritura]);
            close(fd2[lectura]);
        }
        //////////////////////////////////////////////////////////////


        //////////////////////////////////////////////////////////////
        else if (pid == 0) //HIJO
        {
            printf("HIJO: inicio con PID [%d], hijo de [%d]\n", getpid(), getppid());

            close(fd1[escritura]);
            close(fd2[lectura]);

            while(i)
            {
                memset(msg, '\0', MSG_MAX);
                read(fd1[lectura], msg, MSG_MAX);
                printf("HIJO: me llego del padre: [%s]\n", msg);

                memset(msg, '\0', MSG_MAX);
                printf("\n\nHIJO: escriba para mandar al padre: ");
                scanf("%s", msg);
                write(fd2[escritura], msg, MSG_MAX);
            }


            printf(" HIJO: FIN\n");
            close(fd1[lectura]);
            close(fd2[escritura]);
            exit(0);
        }
        //////////////////////////////////////////////////////////////



        else
        {
            printf("ERROR [2]\n");
        }
    }
    else
    {
        printf("ERROR [1]\n");
    }
    return 0;
}