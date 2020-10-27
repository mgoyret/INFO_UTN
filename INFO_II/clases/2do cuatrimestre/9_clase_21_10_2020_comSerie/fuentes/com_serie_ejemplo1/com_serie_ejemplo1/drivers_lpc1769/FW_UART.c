/**
 	\file FW_UART.c
 	\brief Driver de la UART (Comunicación Serie)
 	\details
 	\author
 	\date
*/

#include "Regs_LPC176x.h"
#include "FW_PINSEL.h"
#include "FW_UART.h"
#include "PR_Serie.h"

// Flag de TX en curso
uint8_t txEnCurso;
// NOTA -------------------------------------------------
// Estas variables corresponden a las funciones Primitivas de la com. Serie
// Luego de implementar PopTx() y PushRx() corresponde removerlas de este módulo

// Índices de Transmisión
extern uint8_t tx_in, tx_out;
// Índices de Recepción
extern uint8_t rx_in, rx_out;
// Buffer de Transmisión
extern uint8_t bufferTx[BUFFER_TX_SIZE];
// Buffer de Recepción
extern uint8_t bufferRx[BUFFER_RX_SIZE];
// --------------------------------------------------------


void UART0_IRQHandler (void)
{
	uint8_t iir, dato;

	do {
		//Para limpiar los flags de IIR hay que leerlo, una vez que lo leí se resetea.
		iir = U0IIR;
		//THRE (Interrupción por TX)
		if (iir & 0x02) {
			if(tx_out != tx_in) {
				// hay un dato en el bufferTx para enviar <- reemplazar por PopTx()!!!
				dato = bufferTx[tx_out];
				tx_out++;
				tx_out %= BUFFER_TX_SIZE;
				// transmito el dato
				U0THR = dato;
			}
			else {
				// si no hay más datos a enviar, limpio el flag
				txEnCurso = 0;
			}
		}
		//Data Ready (Interrupción por RX)
		if ( iir & 0x04 ) {
			// guardo el dato recibido en el bufferRx <- reemplazar por PushRx()!!!
			dato = U0RBR;
			bufferRx[rx_in] = dato;
			rx_in++;
			rx_in %= BUFFER_RX_SIZE;
		}
	} while(!(iir & 0x01));	/* me fijo si cuando entre a la ISR habia otra
						    int. pendiente de atencion: b0=0 */
}

void UART0_StartTx(void)
{
	uint8_t dato;

	dato = bufferTx[tx_out];
	tx_out++;
	tx_out %= BUFFER_TX_SIZE;
	// transmito el dato
	U0THR = dato;
}

void InitUART0 (void)
{
	//1.- Registro PCONP - bit 3 en 1 habilita la UART0
	PCONP |= 0x01<<3;
	//2.- Registro PCLKSEL0 - bits 6 y 7 en 0 seleccionan que el clk de la UART0 sea 25MHz
	PCLKSEL0 &= ~(0x03<<6);
	//3.- Registro U1LCR - trama 8 bits, 1 bit stop, sin paridad, sin break cond. (bit DLAB = 1)
	U0LCR = 0x00000083;
	//4.- Registros U1DLL (0x40010000) y U1DLM (0x40010004) - 9600 baudios
	U0DLM = 0;
	U0DLL = 0xA3;
	//5.- Habilito las funciones especiales de los pines TX y RX
	//TX0D : PIN ??	-> 	P0[2]
	SetPINSEL(P0, 2, PINSEL_FUNC1);
	//RX0D : PIN ??	-> 	P0[3]
	SetPINSEL(P0, 3, PINSEL_FUNC1);
	//6.- Registro U1LCR, pongo DLAB en 0
	U0LCR = 0x03;
	//7. Habilito las interrupciones de RX y TX en la UART0 (Registro U0IER)
	U0IER = 0x03;
	//8. Habilito la interrupción de la UART0 en el NVIC (Registro ISER0)
	ISER0 |= (1<<5);
}

