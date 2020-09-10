/*
===============================================================================
 Name        : TP1_EJ6.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>
#include "maquinaestados.h"

void InicializarHW();
void InicializarSW();

int main(void) {

	InicializarHW();
	InicializarSW();

    while(1) {

    	ControlAcceso();

    }
    return 0 ;
}

void InicializarSW() {
	resetControlAcceso();
}
