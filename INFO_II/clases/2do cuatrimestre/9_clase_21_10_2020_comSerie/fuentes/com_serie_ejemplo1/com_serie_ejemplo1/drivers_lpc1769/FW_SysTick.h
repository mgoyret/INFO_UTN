/*
 * FW_Timertick.h
 *
 *  Created on:
 *      Author:
 */

#ifndef FW_SYSTICK_H_
#define FW_SYSTICK_H_

#include "Regs_LPC176x.h"

#define TICKS_CENTESIMAS  	4	// Para SysTick configurado en 2,5 ms.
#define TICKS_DECIMAS		10
#define TICKS_SEGUNDOS		10

void InitSysTick(uint32_t useg);

#endif /* FW_SYSTICK_H_ */

