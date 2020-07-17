#include "include.h"

int main()
{
    inicializacion(); //esta en la biblioteca de la catedre, inicializa el hardw.
    inicializacionMdE();
    while(1)
    {
        maquina_controlLuces();
        /*  Si hubieran maq. concurrentes estarian aca (NO las de estados compuestos
                                                        esas se codean dentro del estado)
        otra_maquina();
        otra_maquina2();
        */
    }

    return 0;
}

/* LAS CONDICIONES DEL ESTADO RESET VAN ANTES DEL WHILE, EN UNA FUNCION
    INICIALIZACION DE MDE */
void inicializacionMdE(void)
{
    /* Para la maquina de control de luces */
    ApagarLuz();
    DetenerTimer();
}