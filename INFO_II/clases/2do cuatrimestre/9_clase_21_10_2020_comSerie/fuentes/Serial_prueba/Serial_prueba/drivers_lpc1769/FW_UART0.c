/*
 * FW_UART.c
 *
 *  Created on: 14/10/2013
 *      Author: marcelo
 */

#include "FW_UART.h"
#include "FW_GPIO.h"
#include "RegsLPC1769.h"


uint8_t buffer_rx[BUFFER_SIZE];
uint8_t index_out;
uint8_t index_in;
uint8_t flag_enviando;

void UART0_IRQHandler (void)
{
	uint8_t iir, aux;

	do
	{
		//el registro IIR es reset por HW, una vez que lo leí se resetea.
		iir = U0IIR;

		if ( iir & 0x04 ) // Data ready (chequeo bit que indica dato recibido)
		{
			buffer_rx[index_in++] = (uint8_t) U0RBR;   	//guardo el dato en el buffer e incremento índice
			index_in %= BUFFER_SIZE;					//garantizo el buffer_rx circular
			if (!flag_enviando) 		//si no estoy enviando....fuerzo la Tx.
				iir |= 0x02;	//simulando a la fuerza la existencia de b1 de IIR = 1.
		}

		if ( iir & 0x02 ) // THRE (chequeo bit que indica dato enviado)
		{
			if (index_in != index_out)		//Cada vez que envía un dato, vuelve a interrumpir.
			{//Cuando saque el último...y los índices queden empatados...hay que cortar la Tx
				flag_enviando = 1;	 		//aviso que estoy enviando

				aux = buffer_rx[index_out];		//leo un nuevo dato del buffer y lo proceso
				index_out++;
				index_out %= BUFFER_SIZE; 		//garantizo el buffer_rx circular

				if ( (aux>' ' && aux<'A') | (aux>'Z' && aux<'a') | (aux>'z') )
				{
					U0THR = (uint8_t)'@';	//verifico que el dato enviado es imprimible, sino envio '@'
				}
				else if ( aux >= 'a' && aux <= 'z')
				{
					aux = aux - 'a' + 'A';
					U0THR = aux;	// envío el mismo caracter en mayúscula
				}
				else if ( aux >= 'A' && aux <= 'Z')
				{
					aux = aux - 'A' + 'a';
					U0THR = aux;	// envío el mismo caracter en minúscula
				}
			}
			else
				flag_enviando = 0;  //aviso que terminé de transmitir.
		}
	}
	while( ! ( iir & 0x01 ) ); /* me fijo si cuando entre a la ISR había otra
						     	int. pendiente de atencion: b0=1 (ocurre únicamente si dentro del mismo
								espacio temporal lleguan dos interrupciones a la vez) */
}

void InitUART0 (void)
{
	//1.- Registro PCONP (0x400FC0C4) - bit 3 en 1 prende la UART:
	PCONP |= 0x01<<3;
	//2.- Registro PCLKSEL0 (0x400FC1A8) - bits 6 y 7 en 0 seleccionan que el clk de la UART0 sea CCLK/4:
	PCLKSEL0 &= ~(0x03<<6);	//con un CCLOK=100Mhz, nos queda PCLOCK=25Mhz
	//3.- Registro U1LCR (0x4001000C) - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
	U0LCR = 0x00000083;
	//4.- Registros U1DLL (0x40010000) y U1DLM (0x40010004) - 9600 baudios:
	U0DLM = 0;
	U0DLL = 0xA3; //0xA3 para 9600
	//5.- Registros PINSEL0 (0x4002C000) y PINSEL1 (0x4002C004) - habilitan las funciones especiales de los pines:
	//TX0D : PIN ??	-> 		P0[2]	-> PINSEL0: 04:05
	SetPINSEL(PORT0, 2 ,PINSEL_FUNC1);
	//RX0D : PIN ??	-> 		P0[3]	-> PINSEL1: 06:07
	SetPINSEL(PORT0, 3, PINSEL_FUNC1);
	//6.- Registro U1LCR, pongo DLAB en 0:
	U0LCR = 0x03;
	//7. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)
	U0IER = 0x03;
	ISER0 |= (1<<5);

	index_out = index_in = 0;
	flag_enviando = 0;
}
