/*
 * PR_Serie.h
 *
 *  Created on:
 *      Author:
 */

#ifndef PR_SERIE_H_
#define PR_SERIE_H_

#include "Regs_LPC176x.h"
#include "FW_UART.h"

#define BUFFER_TX_SIZE	32
#define BUFFER_RX_SIZE	32

void PushTx(uint8_t dato);
uint32_t PopRx(void);

//NOTA: Falta completar con PopTx() y PushRX()!!!

#endif /* PR_SERIE_H_ */
