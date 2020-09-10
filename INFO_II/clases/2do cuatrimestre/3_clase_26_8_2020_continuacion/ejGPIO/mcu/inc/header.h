/*
 * header.h
 *
 *  Created on: Sep 2, 2020
 *      Author: marco
 */

#ifndef HEADER_H_
#define HEADER_H_

#include <Regs_LPC176x.h>

#define ON  1
#define OFF 0

#define DOWN 0
#define UP 1

//para PINSEL
#define TECLA1 2,10
#define TECLA2 0,18

#define LED_STICK 0,22

#define FUNCION_GPIO 0
#define FUNCION_1	 2
#define FUNCION_2	 3
#define FUNCION_3	 4

//para FIODIR
#define ENTRADA 0
#define SALIDA  1

//para PINMODE
#define PULLUP_INTERNO		0
#define REPEATER			1
#define NONE				2
#define PULLDOWN_INTERNO	3

//para PINMODE_OD
#define NORMAL_EXIT 	0
#define OPENDRAIN_EXIT	1


void setPinSel (uint8_t port,uint8_t pin, uint8_t function);
void setPinMode (uint8_t port,uint8_t pin, uint8_t mode);
void setPinModeOD (uint8_t port,uint8_t pin, uint8_t mode);
void setDir (uint8_t port,uint8_t pin,uint8_t status);
uint8_t getPin (uint8_t port,uint8_t pin);
void setPin (uint8_t port,uint8_t pin,uint8_t status);



#endif /* HEADER_H_ */
