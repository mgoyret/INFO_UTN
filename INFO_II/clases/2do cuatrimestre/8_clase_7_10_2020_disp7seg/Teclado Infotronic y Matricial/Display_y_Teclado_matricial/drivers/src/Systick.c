#include "funciones.h"
#include "Teclado.h"
#include "GPIO.h"
void SysTick_Handler (void)
{
	uint8_t CodigoActual ;
	CodigoActual = barridoTeclado( );
	tecladoSW( CodigoActual );
}
