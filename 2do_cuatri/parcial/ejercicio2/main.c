#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#define     TAM     20
#define     ERROR   -1
#define     HIGHLIGHT   printf("\033[07m");
#define     DEFAULT     printf("\033[00m");

float calcular(char* patron, char* medir);
void obtener_valores(char* linea, int *x, int*y,int *valor);

int main()
{
    float error = 0;

    printf("Hola desde el main\n");

    error = calcular("patron", "medida");

    printf("Promedio de error absoluto: '%f'\n", error);

    return 0;
}

float calcular(char* patron, char* medida)
{
    float error = 0, status = ERROR, diferencia = 0;
    FILE *fp_p = NULL, *fp_m = NULL;
    char line_p[TAM], line_m[TAM];
    int cntp = 0, cntm = 0, totm = 0, xp = 0, xm = 0, yp = 0, ym = 0, vp = 0, vm = 0;

    fp_p = fopen(patron, "r");
    fp_m = fopen(medida, "r");

    if ((fp_p != NULL) && (fp_m != NULL))
    {
        while (fgets(line_p, TAM, fp_p) != NULL)
        {
            cntp++;
            obtener_valores(line_p, &xp, &yp, &vp);

            HIGHLIGHT
            //printf("Vuelta %d de patron\n", cntp);
            DEFAULT
            while (fgets(line_m, TAM, fp_m) != NULL)
            {
                cntm++;
                obtener_valores(line_m, &xm, &ym, &vm);
                //printf("Vuelta %d de medida\n", cntm);

                if ((xp == xm) && (yp == ym))
                { 
                    diferencia = vp - vm;
                    if (diferencia < 0)
                    {
                        diferencia = diferencia*(-1);
                    }
                    error += diferencia;
                    //printf("Error: %f\n", error);
                }
            }
            totm = cntm;
            cntm = 0;
            rewind(fp_m);
        }
        status = error/totm;
    }
    else
    {
        printf("Error al abrir archivos\n");
    }

    return status;
}


void obtener_valores(char* linea, int *x, int*y,int *valor)
{
    char *token = NULL;
    
    token = strtok(linea, ",");
    *valor = atoi(token);
    token = strtok(NULL, ",");
    *x = atoi(token);
    token = strtok(NULL, ",");
    *y = atoi(token);
}