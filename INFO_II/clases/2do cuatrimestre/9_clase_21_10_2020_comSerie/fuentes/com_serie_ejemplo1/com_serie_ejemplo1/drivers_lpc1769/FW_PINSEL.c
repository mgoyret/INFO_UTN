/*
 * FW_PINSEL.c
 *
 *  Created on:
 *      Author:
 */

#include "FW_PINSEL.h"

/*********************************************************************//**
	\fn  		void SetPINSEL(uint8_t puerto, uint8_t pin, uint8_t modo)
	\brief 		Selección de modo de los puertos (4 modos)
	\param[in] 	puerto: port a configurar
	\param[in] 	pin:	pin del port a configurar
	\param[in] 	modo:	elección del modo [0 - 3]
				-		PINSEL_GPIO			0
				-		PINSEL_FUNC1		1
				-		PINSEL_FUNC2		2
				-		PINSEL_FUNC3		3
	\return 	void
 **********************************************************************/
void SetPINSEL(uint8_t puerto, uint8_t pin, uint8_t modo)
{
	uint32_t pinsel_idx = 2 * puerto;

	if (pin >= 16) {
		pin -= 16;
		pinsel_idx++;
	}
	*(uint32_t *)(PINSEL + pinsel_idx) &= ~(0x03 << (pin * 2));
	*(uint32_t *)(PINSEL + pinsel_idx) |= ((uint32_t)modo) << (pin * 2);
}

/*********************************************************************//**
	\fn			void SetPINMODE(uint8_t puerto, uint8_t pin, uint8_t modo)
	\brief 		Setup resistor mode for each pin
	\param[in]	puerto: port a configurar
	\param[in]	pin:	pin del port a configurar
	\param[in] 	modo:	elección del modo
				-		PINMODE_PULLUP 		0
				-		PINMODE_REPEAT 		1
				-		PINMODE_TRISTATE	2
				-		PINMODE_PULLDOWN 	3
	\return 	void
 **********************************************************************/
void SetPINMODE(uint8_t puerto, uint8_t pin, uint8_t modo)
{
	uint32_t pinmode_idx = 2 * puerto;

	if (pin >= 16) {
		pin -= 16;
		pinmode_idx++;
	}
	*(uint32_t *)(PINMODE + pinmode_idx) &= ~(0x03 << (pin * 2));
	*(uint32_t *)(PINMODE + pinmode_idx) |= ((uint32_t)modo) << (pin * 2);
}

/*********************************************************************//**
	\fn  		void SetOpenDrainMode(uint8_t puerto, uint8_t pin, uint8_t modo)
	\brief 		Setup Open drain mode for each pin
	\param[in] 	puerto: port a configurar
	\param[in]	pin:	pin del port a configurar
	\param[in]	modo:  	Open drain mode number (normal o open-drain)
	\return 	void
 **********************************************************************/
void SetOpenDrainMode(uint8_t puerto, uint8_t pin, uint8_t modo)
{

	if(modo == PINMODE_OPENDRAIN) {
		*(uint32_t *)(PINMODE_OD0 + puerto) |= (0x01 << pin);
	} else {
		*(uint32_t *)(PINMODE_OD0 + puerto) &= ~(0x01 << pin);
	}
}
