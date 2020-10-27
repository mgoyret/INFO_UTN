/*
===============================================================================
 Name        : Led_PWM.c
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
#include "AP_MdeE.h"



extern int key_rgb;

int main(void) {

	inicializar();
	int i = 0;
    while(1) {
    	maquina_maquina_RGB();
    }
    return 0 ;
}
