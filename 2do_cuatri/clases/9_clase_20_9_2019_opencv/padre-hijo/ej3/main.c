#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void padre_hijo(int);
void hijo_padre(int);

int main() {

    int pid = 0;

    signal(SIGUSR1, padre_hijo);
    signal(SIGUSR2, hijo_padre);

    pid = fork();

    if(pid > 0) {
        printf("P: Soy el padre con PID: %d\n", getpid());
        printf("P: Envio SIGUSR1 a %d\n", pid);
        kill(pid, SIGUSR1);
        wait(NULL);
    }

    if(pid == 0) {
        printf("H: Soy el hijo nº %d\n", getpid());
    }
    return 0;
}

void padre_hijo(int a) {
    printf("SYS: En SIGUSR1 y soy %d\n", getpid());
    printf("SYS: Envio SIGUSR2 hacia %d\n", getppid());
    kill(getppid(), SIGUSR2);
}

void hijo_padre(int a) {
    printf("SYS: Recibi SIGUSR2 y soy %d\n", getpid());
}