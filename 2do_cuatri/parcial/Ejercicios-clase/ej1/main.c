#include "functions.h"
int main(int argc, char** argv)
{    

    HIGHLIGHT BLUE printf("INICIO DESDE EL MAIN\n"); DEFAULT
    if (argc == 4)
    {
        obtener_info(argv[1], argv[2], argv[3]);
    }
    else
    {
        HIGHLIGHT RED printf("Error de parametros\n./<nombre del programa> <dispositivo> <campo> <nombre del archivo>\n"); DEFAULT
    }
    HIGHLIGHT BLUE printf("FIN DESDE EL MAIN\n"); DEFAULT
    return 0;
}