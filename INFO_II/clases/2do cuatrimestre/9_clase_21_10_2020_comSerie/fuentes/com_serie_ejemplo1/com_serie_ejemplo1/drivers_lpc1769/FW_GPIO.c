/*
 * FW_GPIO.c
 *
 *  Created on:
 *  	Author:
 */

#include "FW_GPIO.h"

/********************************************************************************
	\fn  void SetDIR(registro* puerto, uint8_t pin, uint8_t direccion)
	\brief Establece si un determinado PIN de un determinado PUERTO (previamente
			configurado como GPIO) es entrada o salida.
	\author & date: M. Giura - Mar2013
 	\param [in] puerto: 	port con el que se va a trabajar
 	\param [in] pin:		pin a configurar sentido
 	\param [in] dirección:	0 = entrada - 1 = salida.
	\return void
*/
void SetDIR(registro* puerto, uint8_t pin, uint8_t direccion)
{
	(direccion == 1) ? (puerto[0] |= (0x01 << pin)) : (puerto[0] &= ~(0x01 << pin));
}		//puerto[0] == FIODIR

/********************************************************************************
	\fn  void SetPIN(registro* puerto, uint8_t pin, uint8_t estado)
	\brief Establece un ESTADO en un determinado PIN de un determinado PUERTO.
	\author & date: M. Trujillo - Feb2013
 	\param [in] puerto: port con el que se va a trabajar
 	\param [in] pin:	pin a setear estado
 	\param [in] estado:	valor a establecer en el PIN del PUERTO [0-1].
	\return void
*/
void SetPIN(registro* puerto, uint8_t pin, uint8_t estado)
{
	(estado == 1) ? (puerto[6] |= (0x01 << pin)) : (puerto[7] |= (0x01 << pin));
}		//puerto[6] == FIOSET - puerto[7] == FIOCLR

/********************************************************************************
	\fn  void GetPIN(registro* puerto, uint8_t pin)
	\brief Devuelve el ESTADO de un determinado PIN de un determinado PUERTO.
	\author & date: M. Trujillo - Feb2013
 	\param [in] puerto: port con el que se va a trabajar
 	\param [in] pin:	pin a consultar estado
	\return:	estado del pin consultado (uint_8)
*/
uint8_t GetPIN(registro* puerto, uint8_t pin)
{
	return ((puerto[5] >> pin) & 0x01);
}	//puerto[5] == FIOPIN
