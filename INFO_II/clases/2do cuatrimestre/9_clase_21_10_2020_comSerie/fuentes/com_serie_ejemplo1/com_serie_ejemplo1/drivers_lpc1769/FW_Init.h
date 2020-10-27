/*
 * FW_Init.h
 *
 *  Created on:
 *  Author:
 */

#ifndef FW_INIT_H_
#define FW_INIT_H_

#include "Regs_LPC176x.h"

//Funciones de inicialización
void Init(void);
void InitPLL(void);
void InitGPIOs(void);
void InitADC(void);
void InitDAC(void);

#endif /* FW_INIT_H_ */
