#include "mde.h"

extern uint8_t extSensor;
extern uint8_t intSensor;
extern uint8_t cnt_autos;
extern uint8_t timerFin;

////////////////////////////////// FUNCIONES DEL MAIN /////////////////////////////////////////////////////////////

void inicializar()
{
	reset_control_autos();
	reset_alarma();
}

/* LeerED() es la primitiva que lee la entrada pasada como parametro */
uint8_t checkExt()
{
	uint8_t res = FALSE;
	if( Entradas(EXTERIOR) )
		res = TRUE;
	return res;
}

uint8_t checkInt()
{
	uint8_t res = FALSE;
	if( Entradas(INTERIOR) )
		res = TRUE;
	return res;
}


//////////////////////////////////////// FUNCIONES DE CONTROLAUTOS /////////////////////////////////////////////////

/* aunque esta tambien en el main, mas prolijo ponerla aca */
void reset_control_autos()
{
	cnt_autos = 0;
	extSensor = FALSE;
	intSensor = FALSE;
}


//////////////////////// FUNCIONES DE ALARMA ////////////////////////////////////////////////////////////////////

/* Buzzer() es la primitiva que prende/apaga el buzzer segun el parametro. Seria mi alarma */
void prenderAlarma()
{
    Buzzer(ON);
}

void apagarAlarma()
{
    Buzzer(OFF);
}

void IniciarTimer0_10S()
{
	timerFin = FALSE;
    TimerStart(0, 10,timerHandler, SEG);
}

void timerHandler()
{
	timerFin == TRUE;
}

void reset_alarma()
{
	TimerClose();
	timerFin == FALSE;
}
//////////////////////// FUNCIONES COMUNES A VARIOS /////////////////////////////////////////////////////////////
