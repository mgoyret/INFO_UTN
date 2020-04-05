#include "../inc/functions.h"

int msr_tot(FILE* fp)
{
    int tot = 0;
    char line[LINE];

    while(!feof(fp))
    {
        if(fgets(line, LINE, fp) != NULL)
            tot += 1;
    }
    /* 1. Llevo el fp nuevamente al inicoi del archivo
            No se por que al hacer printf de la posicion del fp antes y despues me marca la misma,
            pero no es la misma ya el el fp fue movido por fgets, ademas si no hago el rewind al volver
            al main, el proceso "while" siguiente no es llevado a cabo porque se encuentra el EOF, osea
            que el fp si que esta al final del archivo... */
    rewind(fp);    
    return tot;
}

void ln_st(FILE* fp, meassure* msr, int cnt)
{
    char *token, line[LINE];
    int i = 0;

    for (i = 0; i < cnt; i++)
    {
        fgets(line, LINE, fp);
        //printf("Linea [%s]\n", line);
        token = strtok(line, ",");
        msr[i].id = atoi(token);
        token = strtok(NULL, "\n");
        msr[i].value = atoi(token);
    }

}

void show(meassure* msr, int cnt)
{
    int i;

    for (i = 0; i < cnt; i++)
    {
        printf("msr[%d].id = %d\nmsr[%d].value = %d\n", i, msr[i].id, i, msr[i].value);
    }
}