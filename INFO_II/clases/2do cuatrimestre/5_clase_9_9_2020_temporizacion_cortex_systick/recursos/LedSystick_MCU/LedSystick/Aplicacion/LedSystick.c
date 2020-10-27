/**
*	\file main.c
*	\brief Resumen del contenido del archivo
*	\details Descripcion detallada del archivo
*	\author NicoCampos
*	\date 15-08-2020 16:40:27
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <PR_MdeE.h>
#include <funciones.h>
#include <cr_section_macros.h>

int main(void) {

	inicializar();

    while(1) {

    	maquina_Led();

    }
    return 0 ;
}
