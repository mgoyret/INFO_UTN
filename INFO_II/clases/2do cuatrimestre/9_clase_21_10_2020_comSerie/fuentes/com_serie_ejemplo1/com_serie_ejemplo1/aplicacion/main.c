/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>
#include "Regs_LPC176x.h"
#include "FW_Init.h"
#include "PR_Serie.h"

int main(void)
{
	uint32_t datoRecibido; 	// es de tipo uint32_t porque PopRx() devuelve -1 si no hay dato

	Init();

    while(1) {
    	// espero la llegada de un msje
    	datoRecibido = PopRx();
    	if (datoRecibido != -1) {
    		// devuelvo el caracter recibido, pero armando una trama de ejemplo
    		PushTx('#');
    		PushTx((uint8_t)datoRecibido);
    		PushTx('$');
		} else {
			// por ahora no hago nada...
		}
    }
    return 0;
}
