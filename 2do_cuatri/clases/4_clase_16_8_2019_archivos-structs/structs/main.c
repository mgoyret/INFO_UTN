#include <stdio.h>
#include <string.h>

typedef struct ALUMNO   //iria en el header
{
    int edad;
    char nombre[20];
    char apellido[20];
    long legajo;
    char email[40];
    unsigned char nacionalidad;
} ESTUDIANTE;

int main()
{
    ESTUDIANTE alumno_1;
    FILE *fp;

    /* Cargo estructura */
    alumno_1.edad = 20;
    strcpy(alumno_1.nombre, "Marcos");
    strcpy(alumno_1.apellido, "Goyret");
    alumno_1.legajo = 1716384;
    strcpy(alumno_1.email, "marcosgoyret@gmail.com");
    alumno_1.nacionalidad = 54; //se refiere al codigo de area del pais

    /* Escrivo estructura en archivo */
    fp = fopen("lista_alumnos", "wb");
    if(fp != NULL)
    {
        fwrite(&alumno_1, sizeof(ESTUDIANTE), 1, fp); //averiguar por que el '&alumno_1' va con '&'
        fclose(fp);
    }
    return 0;
}