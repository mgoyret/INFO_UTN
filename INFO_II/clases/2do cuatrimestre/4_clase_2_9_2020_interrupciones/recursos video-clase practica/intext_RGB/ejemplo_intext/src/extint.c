#include "myreg.h"

void EINT0_IRQHandler(void)
{
	EXTINT |= 0x1 << 0; // Limpio el flag de la EINT0 escribiendo un UNO.

	SetPIN(RGB_RED, 1); // Prendo el led rojo
	SetPIN(RGB_GREEN, 0); // Apago el led verde
}

void EINT3_IRQHandler(void)
{
	EXTINT |= 0x1 << 3; // Limpio el flag de la EINT3 escribiendo un UNO.

	SetPIN(RGB_RED, 0); // Apago el led rojo
	SetPIN(RGB_GREEN, 1); // Prendo el led verde
}

