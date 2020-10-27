/*
 * Teclado.h
 *
 *  Created on: 8 sep. 2018
 *      Author: fedeb
 */
#include "RegsLPC1769.h"


//declaracion de la maquina
void tecladoSW(uint8_t);


//Declaracion de estados
#define 	IDLE	0
#define 	DETECCION	1
#define 	CHEQUEO	2


#define MAX_REBOTES 200 //Con systick de 10ms, espera 10ms. Con systick 1ms lo subo a 200

void InicializarKit ( void );
void Check_tecla(void);

void DriverTeclado(void);
void TecladoSW (uint8_t);
uint8_t TecladoHW (void);
