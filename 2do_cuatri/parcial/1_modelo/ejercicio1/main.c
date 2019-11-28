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