/*
 * FW_PINSEL.h
 *
 *  Created on:
 *      Author:
 */

#ifndef FW_PINSEL_H_
#define FW_PINSEL_H_

#include "Regs_LPC176x.h"

void SetPINSEL(uint8_t puerto, uint8_t pin, uint8_t modo);
void SetPINMODE(uint8_t puerto, uint8_t pin, uint8_t modo);
void SetOpenDrainMode(uint8_t puerto, uint8_t pin, uint8_t modo);

//Identificadores de los puertos
#define 	P0			0
#define 	P1			1
#define 	P2			2
#define 	P3			3
#define 	P4			4

#endif /* FW_PINSEL_H_ */
