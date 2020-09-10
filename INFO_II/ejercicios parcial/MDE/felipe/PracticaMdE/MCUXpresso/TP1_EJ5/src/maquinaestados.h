/*
 * maquinaestados.h
 *
 *  Created on: 23 jul. 2020
 *      Author: Felipe
 */

#ifndef MAQUINAESTADOS_H_
#define MAQUINAESTADOS_H_

#include "bibliotecaInfoII.h"

typedef unsigned char uint8_t;

void ControlAutos();
void timerExpirado();
void IniciarTimer0_10S();
uint8_t sensorderecha_presencia();
uint8_t sensorizquierda_presencia();
void ApagarRele1();
void PrenderRele1();
void resetControlAutos();

#endif /* MAQUINAESTADOS_H_ */
