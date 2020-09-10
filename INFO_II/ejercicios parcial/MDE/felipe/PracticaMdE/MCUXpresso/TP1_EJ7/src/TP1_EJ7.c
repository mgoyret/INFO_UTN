/*
===============================================================================
 Name        : TP1_EJ7.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <cr_section_macros.h>

void InicializarHW();
void InicializarSW();

int main(void) {

	InicializarHW();
	InicializarSW();

    while(1) {
    	ControlCinta();
    }

    return 0 ;
}

void InicializarSW() {
	resetControlCinta();
}