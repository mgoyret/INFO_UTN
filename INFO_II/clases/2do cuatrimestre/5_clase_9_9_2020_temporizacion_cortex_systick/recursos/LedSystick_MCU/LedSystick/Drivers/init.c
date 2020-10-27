/*
 * init.c
 *
 *  Created on: 15 ago. 2020
 *      Author: nicoc
 */

#include <PR_FuncionesMdeE.h>
#include <DR_PLL.h>
#include <funciones.h>
#include <DR_Systick.h>
#include <DR_GPIO.h>
#include <DR_PINSEL.h>

void inicializar( void )
{
	// Inicializo el clock en 100MHz
	Init_PLL();

	// Inicializo el timer Systick
	Init_Systick();

	// Inicializo el pin como salida
	Init_GPIO();
}

void Init_GPIO( void )
{
	SetPINSEL(LED, PINSEL_GPIO);
	SetDIR(LED, SALIDA);
	SetPIN(LED,OFF);
}
