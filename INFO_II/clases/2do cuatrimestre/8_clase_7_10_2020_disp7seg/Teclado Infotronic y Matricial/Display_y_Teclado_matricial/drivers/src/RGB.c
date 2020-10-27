/*
 * RGB.c
 *
 *  Created on: 9 sep. 2018
 *      Author: fedeb
 */

#include "funciones.h"
#include "GPIO.h"
void apagarRGB()
{
	SetPIN(RGB_BLUE,OFF);
	SetPIN(RGB_RED,OFF);
	SetPIN(RGB_GREEN,OFF);
}
