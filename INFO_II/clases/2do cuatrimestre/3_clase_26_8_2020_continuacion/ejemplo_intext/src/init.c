#include "myreg.h"

void init(void)
{
	Init_GPIOs();
	Init_IntExt();
}

void Init_GPIOs(void)
{

	SetPINSEL ( RGB_BLUE , PINSEL_GPIO);
	SetPINSEL ( RGB_RED , PINSEL_GPIO);
	SetPINSEL ( RGB_GREEN , PINSEL_GPIO);

	SetDIR ( RGB_BLUE , SALIDA);
	SetDIR ( RGB_RED, SALIDA);
	SetDIR ( RGB_GREEN , SALIDA);
}

void Init_IntExt(void)
{
	// P2.13 como EINT3
	// configuro el pin con función de interrupción externa
	SetPINSEL(P2, 13, INT_EXT);
	// P2.10 como EINT0
	// configuro el pin con función de interrupción externa
	SetPINSEL(P2, 10, INT_EXT);

	//Limpio flags como inicialización
	EXTINT |= 0x1 << 0; // Limpio el flag de la EINT0 escribiendo un UNO.
	EXTINT |= 0x1 << 3; // Limpio el flag de la EINT3 escribiendo un UNO.

	// Configuro a EINT0 por FLANCO
	EXTMODE |= 0x01 << 0;
	// Configuro a EINT3 por FLANCO
	EXTMODE |= 0x01 << 3;
	// Configuro a EINT0 sensible en flanco ASCENDENTE
	//Registro | 1 --> Pone en 1 el bit 0 dejando al resto como estaba
	EXTPOLAR |= 0x01 << 0;
	// Configuro a EINT3 sensible en flanco DESCENDENTE
	//Registro & 111...110111 --> Pone en 0 el bit 3  dejando al resto como estaba
	EXTPOLAR &= ~(0x01 << 3);

	// Habilito las int. externas
	ISER0 |= 0x01 << 18; // EINT0
	ISER0 |= 0x01 << 21; // EINT3
}
