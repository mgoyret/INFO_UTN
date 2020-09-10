/**
*	\file funciones.c
*	\brief Implementacion switch-case
*	\details Descripcion detallada del archivo
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/

#include "mde.h" 


extern int lector;
extern uint8_t timer10Fin;
extern uint8_t timer5Fin;



void inicializar()
{
	timer10Fin = FALSE;
	timer5Fin = FALSE;
	TimerClose();
	reset_maquina_led();

}

/* Tendria que haber echo una maquina general para que haya un solo reset para variables y timers globales */
void reset_maquina_led()
{
	LedsRGB(ROJO, OFF);
	timer5Fin = FALSE;
	timer10Fin = FALSE;
	TimerClose();	
}

void reset_maquina_puerta()
{
	timer5Fin = FALSE;
	timer10Fin = FALSE;
	TimerClose();
}

void reset_maquina_display()
{
	displayEsperando();
	timer10Fin = FALSE;
	timer5Fin = FALSE;
	TimerClose();
}

////////////////////////////////////////////// FUNCIONES MAQUINA LED ////////////////////////////////////////////////////////////

void prenderLed( void )
{
	LedsRGB(ROJO, ON);
}

void apagarLed( void )
{
	LedsRGB(ROJO, OFF);
}


////////////////////////////////////////////// FUNCIONES MAQUINA PUERTA  /////////////////////////////////////////////////////////////


////////////////////////////////////////////// FUNCIONES COMUNES A VARIAS MAQUINAS  ///////////////////////////////////////////////////



////////////////////////////////////////////// FUNCIONES MAQUINA DISPLAY ////////////////////////////////////////////////////////////

/**
*	\fn void displayXXXXXXX(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/
void displayNoHabilitado( void )
{
	Display("No Habilitado"); //primitiva que imprime en LCD
}

void displayEsperando( void )
{
	Display("Esperando");
}

void displayPuertaHabilitada( void )
{
	Display("Puerta Habilitada");
}

void displayPersonalDentro( void )
{
	Display("Personal Dentro");
}

void Display(char* str)
{
	LCD_Display(str, DSP0, 0); // puse primitiva real para que compile en mcu
}


/**
*	\fn void sensorHuella( void )
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/
void sensorHuella( void )
{
	lector = (int)leerSensorHuella(); // primitiva dada
}


/**
*	\fn uint8_t accesoPermitido(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/
uint8_t accesoPermitido( void )
{
	uint8_t res = 0 ;

	//!< Codigo propio de la funcion

	return res;
}

/**
*	\fn uint8_t cerroPuerta(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/
uint8_t cerroPuerta( void )
{
	uint8_t res = FALSE;
	if(GetKey() == KEY_PUERTA_CERRO) //La puerta al cerrarce presiona esta tecla
		res == TRUE;
	return res;
}


/**
*	\fn uint8_t botonSalir()
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/
uint8_t botonSalir()
{
	uint8_t res = FALSE;
	if( GetKey() == KEY_SALIR ) // KEY_SALIR = codigo de tecla para salir
		res = TRUE;
	return res;
}

//!< Funciones asociadas a las acciones

/**
*	\fn void IniciarTimer_0_10S(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/
void IniciarTimer_0_10S( void )
{
	TimerStart(0, 10, Timer_0_10S_Handler, SEG);
}

void Timer_0_10S_Handler()
{
	timer10Fin = TRUE;
}

/**
*	\fn void IniciarTimer_0_5S(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/
void IniciarTimer_0_5S( void )
{
	TimerStart(0, 10, Timer_0_5S_Handler, SEG);
}

void Timer_0_5S_Handler()
{
	timer5Fin = TRUE;
}


/**
*	\fn void resetTimer(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/
void resetTimer( void )
{
	TimerClose();
}



/**
*	\fn void guardarCodigoHuella(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 14:30:31
*/
void enviarCodigoHuella( void )
{
	char codigo[10]; // presupongo que alcanzara con esta cantidad de digitos
	Strcpy(codigo, Itoa(lector));
	Transmitir(codigo);
}

