#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int pid;
    
    if (argc == 3)
    {
        pid = fork();
        if(pid > 0)
        {
            printf("PADRE (pid %d). Mi hijo es %d\n\n%d + %d = %d\n\n", getpid(), pid, atoi(argv[1]), atoi(argv[2]), atoi(argv[1]) + atoi(argv[2]));
        }
        else if (pid == 0)
        {
            printf("HIJO (pid %d). Mi padre es %d\n\n%d * %d = %d\n\n", getpid(), getppid(), atoi(argv[1]), atoi(argv[2]), atoi(argv[1]) * atoi(argv[2]));
        }
        else
            printf("ERROR\n");
    }
    else
        printf("Error de argumentos.\n./<programa> <operando 1> <operando 2>\n");
    
    return 0;
}