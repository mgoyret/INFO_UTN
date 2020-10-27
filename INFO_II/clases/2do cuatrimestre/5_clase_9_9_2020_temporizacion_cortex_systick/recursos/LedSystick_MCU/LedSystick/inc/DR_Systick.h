/*
 * DR_Systick.h
 *
 *  Created on: 15 ago. 2020
 *      Author: nicoc
 */

#ifndef DR_SYSTICK_H_
#define DR_SYSTICK_H_

#include <DR_tipos.h>

#define	 SysTick 		( (__RW uint32_t * )  0xE000E010UL  )
#define  STCTRL			SysTick[0]
#define  STRELOAD		SysTick[1]
#define  STCURR			SysTick[2]
#define  STCALIB		SysTick[3]

void Init_Systick( void );

#endif /* DR_SYSTICK_H_ */
