/*
===============================================================================
 Name        : huellaej6.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <mde.h>

extern int lector;
extern uint8_t timer10Fin;
extern uint8_t timer5Fin;


// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {

    // TODO: insert code here
	inicializar();

	while(1)
	{
		sensorHuella(); // Actualiza los valores de "acceso" y de "lector"
		maquina_puerta();
		maquina_display();
	}
    return 0 ;
}
