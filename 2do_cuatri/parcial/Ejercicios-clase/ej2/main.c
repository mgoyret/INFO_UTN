#include "functions.h"
int main(int argc, char** argv)
{    

    HIGHLIGHT BLUE printf("INICIO DESDE EL MAIN\n"); DEFAULT
    if (argc == 5)
    {
        buscar_disp(argv[1], argv[2], argv[3], atoi(argv[4]));
    }
    else
    {
        HIGHLIGHT RED printf("Error de parametros\n./<nombre del programa> <dispositivo> <campo> <nombre del archivo> <valor a ingresar>\n"); DEFAULT
    }
    HIGHLIGHT BLUE printf("FIN DESDE EL MAIN\n"); DEFAULT
    return 0;
}