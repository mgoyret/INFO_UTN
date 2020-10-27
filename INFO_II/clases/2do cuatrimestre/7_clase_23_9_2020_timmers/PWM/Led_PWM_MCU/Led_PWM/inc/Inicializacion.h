/*
 * Inicializacion.h
 *
 *  Created on: 28 ago. 2019
 *      Author: NicoCampos
 */

#ifndef INICIALIZACION_H_
#define INICIALIZACION_H_

#include "Regs_LPC176x.h"
#include "RegsLPC1769.h"

#define PIN_EINT0	2,10,1
//#define PIN_EINT3	2,13,1

//declaracion de la inicializacion
void Init_PWM(void);
void Init_GPIO_PWM(void);
void Init_EINT(void);
void SetDIR( uint8_t puerto , uint8_t pin , uint8_t dir );
void SetPIN( uint8_t puerto , uint8_t pin , uint8_t estado );
uint8_t GetPIN( uint8_t puerto , uint8_t pin , uint8_t actividad );
void SetPINSEL( uint8_t puerto , uint8_t pin ,uint8_t funcion );
void SetPINMODE( uint8_t port , uint8_t pin ,uint8_t modo);

#endif /* INICIALIZACION_H_ */
