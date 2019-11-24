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