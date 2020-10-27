#include "funciones.h"
#include "Oscilador.h"
#include "GPIO.h"
void Inicializar_Teclado( void )
{
	SetPINSEL ( Infotronic_KEY0 , PINSEL_GPIO);
	SetPINSEL ( Infotronic_KEY1 , PINSEL_GPIO);
	SetPINSEL ( Infotronic_KEY2 , PINSEL_GPIO);
	SetPINSEL ( Infotronic_KEY3_RC , PINSEL_GPIO);
	SetPINSEL ( Infotronic_KEY4_RC , PINSEL_GPIO);

	SetDIR ( Infotronic_KEY0 , ENTRADA);
	SetDIR ( Infotronic_KEY1 , ENTRADA);
	SetDIR ( Infotronic_KEY2 , ENTRADA);
	SetDIR ( Infotronic_KEY3_RC , ENTRADA);
	SetDIR ( Infotronic_KEY4_RC , ENTRADA);

	SetPINMODE ( Infotronic_KEY0 , PINMODE_PULLUP);
	SetPINMODE ( Infotronic_KEY1 , PINMODE_PULLUP);
	SetPINMODE ( Infotronic_KEY2 , PINMODE_PULLUP);
}

void Inicializar_RGB( void )
{
	SetPINSEL ( RGB_RED , PINSEL_GPIO);
	SetPINSEL ( RGB_GREEN , PINSEL_GPIO);
	SetPINSEL ( RGB_BLUE , PINSEL_GPIO);

	SetDIR ( RGB_RED , SALIDA);
	SetDIR ( RGB_GREEN , SALIDA);
	SetDIR ( RGB_BLUE , SALIDA);

	SetPIN(RGB_RED,OFF);
	SetPIN(RGB_GREEN,OFF);
	SetPIN(RGB_BLUE,OFF);
}

//-----------------------------------------------------------------------------
// Configuración del SysTick para 10ms
//-----------------------------------------------------------------------------
void Inicializar_Systick(void){
		STRELOAD  = STCALIB - 1 ;
		STCURR = 0;

		ENABLE = 1;
		TICKINT = 1;
		CLKSOURCE = 1;
		return;
}

//-----------------------------------------------------------------------------
// Inicialización general del Kit de acuerdo al uso que se le dará.
//-----------------------------------------------------------------------------
void Inicializar ( void )
{
	InicPLL();
	Inicializar_Teclado();
	Inicializar_RGB();
	Inicializar_TecladoMatricial();
	Inicializar_Systick();

}

