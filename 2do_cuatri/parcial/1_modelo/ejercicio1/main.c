/**
 * Marcos Goyret
 * Modelo 2do parcial Info1 UTN a rendir el 29/11/2019
*/

/*
    Se desea realizar un sistema para gestión de turnos médicos. Para ello se cuentan con archivos por día y por médico con
    los turnos correspondientes a ser atendidos ese día. Dentro de cada archivo se dispone la información de los pacientes
    que deben ser atendidos con el siguiente formato:
	
    typedef struct paciente
    { 	
	    char 	nomApe[40];
	    long 	dni; 	
	    float   horaTurno;	
    }paciente_t;
	
    Se pide implementar una función que genere una array dinámico a partir de la lectura del archivo con los turnos insertando
    de forma ordenada los pacientes por horario. El nombre del archivo con el formato correcto se recibe como parámetro de la función,
    el prototipo es el siguiente:

    int lecturaPacientes(paciente_t **inicio, char *archivo);
    
    La función deberá devolver:
        • -1 si hubo algún error en la lectura del archivo
        • -2 si hubo algún error en la asignación de memoria dinámica
        • 0 si la lectura se realizó con éxito.



*/

#include "functions.h"

int main(int argc, char** argv)
{
    int status = 0;
    paciente_t *inicio;

    SPACE BLUE HIGHLIGHT
    printf("INICIO DESDE EL MAIN");
    SPACE DEFAULT
    if (argc == 2)
    {
        status = lecturaPacientes(&inicio, argv[1]);
    }
    else
    {
        RED SPACE
        printf("Error de parametros\n\n./<programa> <nombre de archivo>");
        SPACE DEFAULT
    }

    SPACE BLUE HIGHLIGHT
    printf("FIN DESDE EL MAIN");
    SPACE DEFAULT

    return status;
}