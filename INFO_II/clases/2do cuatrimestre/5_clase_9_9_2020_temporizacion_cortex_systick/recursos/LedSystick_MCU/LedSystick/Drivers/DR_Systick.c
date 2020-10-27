/*
 * DR_Systick.c
 *
 *  Created on: 15 ago. 2020
 *      Author: nicoc
 */

#include <DR_Systick.h>

#define N	10	// con N = 1 -> tick de 10ms

int tiempo = 0;

void Init_Systick( void )
{
	STRELOAD = (STCALIB/N) - 1; // 1 miliseg con PLL a 100 MHZ.
	STCTRL = 0x07;				// Clock sistema, interrupción habilitada, systick habilitado.
}

void SysTick_Handler(void)
{
	tiempo--;
}
