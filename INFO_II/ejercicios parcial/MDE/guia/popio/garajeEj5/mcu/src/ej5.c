/*
===============================================================================
 Name        : ej5.c
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

// TODO: insert other include files here

// TODO: insert other definitions and declarations here
#include "mde.h"

uint8_t extSensor;
uint8_t intSensor;
uint8_t cnt_autos;
uint8_t timerFin;


int main(void) {

	inicializar();

	while(1)
	{
		extSensor = checkExt();
		intSensor = checkInt();
		maquina_control_autos();
		maquina_alarma();
	}
    return 0 ;
}
