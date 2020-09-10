/**
*	\file funciones.c
*	\brief Implementacion switch-case
*	\details Descripcion detallada del archivo
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/

#include "mde.h"


extern int presenciaActual;
extern int sonar;
extern int timerFin;
extern int timerSirenaFin;
extern int tramaFin;


/**
*	\fn void inicializar(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void inicializar()
{
	reset_general();
	reset_led();
	reset_sirena();
}


/*********************************************************************************************************************************
*** MAQUINA GENERAL
**********************************************************************************************************************************/

/**
*	\fn int ingreso(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
uint8_t ingreso( void )
{
	/* Esta primitiva segun entendi en el manual, devuelve
		true o false (valor de la entrada). En caso que no sea asi,
		declarar una variable y retornar esa con true.false dependiendo de
		lo que retorne esta primitiva*/
	return Entradas(INGRESO);
}

/**
*	\fn int egreso(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
uint8_t egreso( void )
{
	/* Idem nota en funcion ingreso() */
	return Entradas(EGRESO);
}

/**
*	\fn void iniciarTimer_10s(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void iniciarTimer_10s( void )
{
	/* Al evento lo llamo ingreso para distinguirlo del timer de evento sirena */
	TimerStart(TIMER_INGRESO, 10, timerHandler, SEG);
}

/**
*	\fn void timerHandler(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void timerHandler( void )
{
	timerFin = TRUE;
}

/**
*	\fn void detenerTimer(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void detenerTimer( void )
{
	TimerStop(TIMER_INGRESO);
}

/**
*	\fn int TECLA0(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
int TECLA0( void )
{
	int res = FALSE;
	if( GetKey() == SW1 )
		res = TRUE;
	return res;
}

/**
*	\fn void reset_general(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void reset_general( void )
{
	detenerTimer();
	presenciaActual = FALSE;
	sonar = FALSE;
	timerFin = FALSE;

}


/*********************************************************************************************************************************
*** MAQUINA LED
**********************************************************************************************************************************/

/**
*	\fn void rojoOn(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void rojoOn( void )
{
	LedsRGB(ROJO, ON);
}

/**
*	\fn void verdeOn(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void verdeOn( void )
{
	LedsRGB(VERDE, ON);
}

/**
*	\fn void rojoOff(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void rojoOff( void )
{
	LedsRGB(ROJO, OFF);
}

/**
*	\fn void verdeOff(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void verdeOff( void )
{
	LedsRGB(VERDE, OFF);
}

/**
*	\fn void reset_led(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void reset_led()
{
	verdeOn();
	rojoOff();
}

/*********************************************************************************************************************************
*** MAQUINA SIRENA
**********************************************************************************************************************************/

/**
*	\fn void iniciarTimerSirena(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void iniciarTimerSirena( void )
{
	TimerStart(TIMER_SIRENA, 5, timerSirenaHandler, DEC);
}

/**
*	\fn void timerSirenaHandler(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void timerSirenaHandler( void )
{
	timerSirenaFin = TRUE;
}


/**
*	\fn void detenerTimerSirena(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void detenerTimerSirena( void )
{
	TimerStop(TIMER_SIRENA);
}

/**
*	\fn void sirenaOn(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void sirenaOn( void )
{
	/* Es lo mas parecido a una sirena que puedo prender con la biblioteca */
	Buzzer(ON);
}

/**
*	\fn void sirenaOff(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void sirenaOff( void )
{
	Buzzer(OFF);
}

/**
*	\fn void reser_sirena(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void reset_sirena()
{
	detenerTimerSirena();
	sirenaOff();
	timerSirenaFin = FALSE;
}

/*********************************************************************************************************************************
*** MAQUINA CENTRAL_CONTROL
**********************************************************************************************************************************/

/**
*	\fn int TECLA1(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
int TECLA1( void )
{
	int res = FALSE;
	if( GetKey() == SW4 )
		res = TRUE;
	return res;
}

/**
*	\fn void envairTrama(void)
*	\brief Resumen
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void envairTrama( void )
{
	//int16_t c;
	int16_t c[5];

	c[0]=0xAA;
	c[1]='O';
	c[2]='F';
	c[3]='F';
	c[4]=0xEE;
	Transmitir(0, (const void*)c, 5);
/*
	c = 0xAA;
	Transmitir(0, (void*)&c, 1);
	c = 'O';
	Transmitir(0, (void*)&c, 1);
	c = 'F';
	Transmitir(0, (void*)&c, 1);
	c = 'F';
	Transmitir(0, (void*)&c, 1);
	c = 0xEE;
	Transmitir(0, (void*)&c, 1);
*/
}

/*********************************************************************************************************************************
*** RECIBIR_TRAMA
**********************************************************************************************************************************/

void guardoAux(int16_t aux, int16_t* buf, int16_t cant)
{
	buf[cant]=aux;
}

int tramaFinCheck(int16_t* buf)
{
	int res = FALSE;
	if( (buf[0]=M1) && (buf[1]=M2) && (buf[2]=M3) )
		res = TRUE;
	return res;
}

uint16_t Recibir (uint8_t UARTx) // no me detecta esta primitiva
{
	return 0;
}
