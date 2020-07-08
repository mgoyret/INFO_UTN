/*
===============================================================================
 Name        : primeraPrueba.c
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
#include "bibliotecaInfoII.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {

    // TODO: insert code here
	Inicializacion();

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
        if(GetKey() == SW1)
        	Relays(0, ON);
    }
    return 0 ;
}
