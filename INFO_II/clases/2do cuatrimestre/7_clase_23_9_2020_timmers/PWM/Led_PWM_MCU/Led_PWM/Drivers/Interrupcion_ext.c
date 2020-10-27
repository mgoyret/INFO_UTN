/*
 * Interrupcion_ext.c
 *
 *  Created on: 28 ago. 2019
 *      Author: NicoCampos
 */
#include "RegsLPC1769.h"
#include "AP_MdeE.h"

extern int key_rgb;

void EINT0_IRQHandler(void)
{
	EXTINT |= 1<<0;		// Atiendo la interrupcion 0
	key_rgb = TRUE;
}

