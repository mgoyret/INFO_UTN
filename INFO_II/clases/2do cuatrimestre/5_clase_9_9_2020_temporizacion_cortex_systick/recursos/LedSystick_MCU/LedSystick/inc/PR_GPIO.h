/*
 * PR_GPIO.h
 *
 *  Created on: 15 ago. 2020
 *      Author: nicoc
 */

#ifndef PR_GPIO_H_
#define PR_GPIO_H_

#include <DR_tipos.h>

void Init_GPIO( void );
void SetDIR(uint8_t puerto,uint8_t pin,uint8_t direccion);
void SetPIN(uint8_t puerto,uint8_t pin,uint8_t estado);
uint8_t GetPIN(uint8_t puerto,uint8_t pin);

#endif /* PR_GPIO_H_ */
