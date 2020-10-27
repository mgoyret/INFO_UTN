/*
 * FW_UART.h
 *
 *  Created on:
 *      Author:
 */

#ifndef FW_UART_H_
#define FW_UART_H_

#include "Regs_LPC176x.h"

#define START_TX()	(PopTx((uint8_t*)&U0THR))

void InitUART0(void);
void UART0_StartTx(void);

extern uint8_t txEnCurso;

#endif /* FW_UART_H_ */
