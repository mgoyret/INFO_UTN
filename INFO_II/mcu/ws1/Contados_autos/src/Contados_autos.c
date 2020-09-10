/*
===============================================================================
 Name        : Contados_autos.c
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
#include <bibliotecaInfoII.h>
#include "AP_MdeE.h"
#include "AP_FuncionesMdeE.h"

// TODO: insert other include files here

// TODO: insert other definitions and declarations here



int main(void) {

    // TODO: insert code here

	//declaracion de variables

	//inicializacion de perifericos

	Inicializacion();
	ApagoSirena();



	while(1)
		{

				maquina_MdE1();

				maquina_MdESirena();
		}

    return 0 ;
}
