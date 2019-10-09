#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {

    FILE *fp = NULL;
    char buf[100];

    printf("Cargue un valor: ");
    scanf("%s", buf);

    fp = fopen("MiNPipe", "w");
    if(fp != NULL) {
        fprintf(fp, "%s\n", buf);
        fclose(fp);
    }
    return 0;
}