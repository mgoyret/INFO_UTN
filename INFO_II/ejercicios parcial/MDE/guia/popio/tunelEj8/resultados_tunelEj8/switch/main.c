/*
===============================================================================
 Name        : tunelEj8.c
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
#include <mde.h>


// TODO: insert other definitions and declarations here
int presenciaActual;
int sonar;
int timerFin;
int timerSirenaFin;
int tramaFin;

int main(void) {

	inicializar();
	while(1)
	{
		maquina_general();
		maquina_led();
	}

    return 0 ;
}
