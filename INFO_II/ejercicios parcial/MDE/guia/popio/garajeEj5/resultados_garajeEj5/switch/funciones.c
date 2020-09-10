#include "mde.h"

extern uint8_t extSensor;
extern uint8_t intSensor;
extern uint8_t cnt_autos;

////////////////////////////////// FUNCIONES DEL MAIN /////////////////////////////////////////////////////////////

void inicializarSW()
{
	reset_control_autos()
}

void inicializarHW()
{
	/* primitiva que apaga TODOS los timers */
    Timer_Close();
}

/* LeerED() es la primitiva que lee la entrada pasada como parametro */
uint8_t checkExt()
{
	uint8_t res = FALSE;
	if( LeerED(EXTERIOR) )
		res = TRUE;
	return res;
}

uint8_t checkInt()
{
	uint8_t res = FALSE;
	if( LeerED(INTERIOR) )
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

/* Buzzer() es la primitiva que prende/apaga el buzzer segun el parametro */
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
    Timer_Start(0, 10, NULL, SEG);
}

uint8_t Timer0_10S()
{
    uint8_t res = FALSE;
    if( GetTimer(0) == FIN_10S )
        res = TRUE;
    return res;
}

//////////////////////// FUNCIONES COMUNES A VARIOS /////////////////////////////////////////////////////////////
