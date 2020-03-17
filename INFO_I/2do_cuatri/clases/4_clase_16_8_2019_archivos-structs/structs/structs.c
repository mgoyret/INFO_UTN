//ESTRUCTURA.  Debemos declararla en el header

typedef struct ALUMNO
{
    int edad;
    char nombre[20];
    char apellido[20];
    long legajo;
    char email[40];
    unsigned char nacionalidad;
} ESTUDIANTE;   //ESTUDIANTE es el typedef de 'struct alumno'. Decir 'struct alumno alumno_1' equivale a 'ESTUDIANTE alumno_1'

struct ALUMNO alumno_1;
ESTUDIANTE alumno_2;

alumno_1.edad = 20;             //El '.' me deja acceder a ese campo de la estructura
strcpy(alumno_1, "marcos");     //equivaldria a 'alumno_1.nombre = "marcos";' pero no podemos asignar un string igualando

sizeof(ESTUDIANTE);             //me devuelve la suma de el tamano de los tipos de datos que contiene.