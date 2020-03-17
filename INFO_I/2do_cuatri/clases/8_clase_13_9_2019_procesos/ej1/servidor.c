#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    
    char aux[100];
    int condicion = 1;
    FILE *fp = NULL;

    mknod("MiNPipe", S_IFIFO | 0644, 0);

    while (condicion == 1)
    {
        fp = fopen("MiNPipe", "w+");
        if(fp != NULL) {
            fgets(aux, sizeof(char)*100, fp);
            printf("%s", aux);
            sleep(2);
            fprintf(fp, "Hola!\n");
            fclose(fp);
        }
    }

    return 0;
}