/*
 * FW_GPIO.h
 *
 * Created on:
 * Author:
 */

#ifndef FW_GPIO_H_
#define FW_GPIO_H_

#include "Regs_LPC176x.h"

//Prototipos de las funciones utilitarias
void SetDIR(registro* puerto, uint8_t pin, uint8_t direccion);
void SetPIN(registro* puerto, uint8_t pin, uint8_t estado);
uint8_t GetPIN(registro* puerto, uint8_t pin);

//Dirección en FIODIR
#define 	ENTRADA			0
#define 	SALIDA			1

//Defines generales
#define		OFF			0
#define		ON			1



#endif /* FW_GPIO_H_ */
