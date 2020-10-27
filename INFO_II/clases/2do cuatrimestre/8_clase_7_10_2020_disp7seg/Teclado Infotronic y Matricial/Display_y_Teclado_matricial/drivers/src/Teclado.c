/**
*	\file Teclado.c
*	\brief Todas las funciones necesarias para el teclado del Infotronic
*	\details
*	\author FedericoBua
*	\date 08-09-2018 22:58:22
*/
#include "Teclado.h"
#include "GPIO.h"
#include "funciones.h"
#include "FW_DISPLAY-Expansion3.h"
void DriverTeclado(void)
{
	uint8_t CodigoActual ;
	CodigoActual = barridoTeclado( );
	tecladoSW( CodigoActual );
}


uint8_t TecladoHW (void)
{
	uint8_t Codigo = NO_KEY;

	if (KEY0_ACTIVO_BAJO) return 0;
	if (KEY1_ACTIVO_BAJO) return 1;
	if (KEY2_ACTIVO_BAJO) return 2;
	if (KEY3_ACTIVO_BAJO) return 3;
	if (KEY4_ACTIVO_BAJO) return 4;
    return Codigo;
}


uint8_t barridoTeclado()
{	SetPIN(COLUMNA0,0);
	SetPIN(COLUMNA1,1);
	if(GetPIN(FILA0,ACTIVO_BAJO))
		return 0;
	if(GetPIN(FILA1,ACTIVO_BAJO))
		return 1;
	if(GetPIN(FILA2,ACTIVO_BAJO))
		return 2;
	if(GetPIN(FILA3,ACTIVO_BAJO))
		return 3;

	SetPIN(COLUMNA0,1);
	SetPIN(COLUMNA1,0);

	if(GetPIN(FILA0,ACTIVO_BAJO))
		return 4;
	if(GetPIN(FILA1,ACTIVO_BAJO))
		return 5;
	if(GetPIN(FILA2,ACTIVO_BAJO))
		return 6;
	if(GetPIN(FILA3,ACTIVO_BAJO))
		return 7;

	else
		return NO_KEY;


}


//Implementacion Switch-Case

/**
*	\fn tecladoSW()
*	\brief Implementacion Switch-Case
*	\details
*	\author FedericoBua
*	\date 08-09-2018 22:58:22
*/
extern uint8_t buffKey;

void tecladoSW(uint8_t codigoActual)
{

		static uint8_t codigoAnterior=NO_KEY;
		static uint8_t contador=0; //Máximo 50
		static int estado = IDLE;

		switch(estado)
		{
			case IDLE:

				if(codigoActual!=NO_KEY)
				{
					codigoAnterior=codigoActual;
					estado = DETECCION;

				}
				if(codigoActual==NO_KEY)
				{

					estado = IDLE;

				}

				break;

			case DETECCION:

				if(codigoActual!=codigoAnterior)
				{

					estado = IDLE;

				}
				if(codigoActual==codigoAnterior)
				{
					contador=MAX_REBOTES;
					estado = CHEQUEO;

				}

				break;

			case CHEQUEO:

				if(codigoActual!=codigoAnterior)
				{
					codigoActual=codigoAnterior;
					estado = DETECCION;

				}
				if(codigoActual==codigoAnterior)
				{
					contador--;
					estado = CHEQUEO;

				}
				if(contador==0)
				{
					buffKey=codigoActual;
					estado = IDLE;
				}
				break;
			default: estado = IDLE;
		}
}

