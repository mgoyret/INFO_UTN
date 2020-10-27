#include "funciones.h"
#include "Teclado.h"
#include "RegsLPC1769.h"
extern uint8_t buffKey;
uint8_t Teclado( void )
{
	uint8_t tecla = NO_KEY;

	if (buffKey != NO_KEY )
	{
		tecla = buffKey;
		buffKey = NO_KEY;
	}
	return tecla;
}
