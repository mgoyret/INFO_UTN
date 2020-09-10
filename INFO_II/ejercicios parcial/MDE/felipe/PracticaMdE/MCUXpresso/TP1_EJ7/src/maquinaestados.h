/*
 * maquinaestados.h
 *
 *  Created on: 23 jul. 2020
 *      Author: Felipe
 */

#ifndef MAQUINAESTADOS_H_
#define MAQUINAESTADOS_H_

#include "bibliotecaInfoII.h"
#include <stdio.h>

#define PULSOS_POR_CM 10

typedef unsigned char uint8_t;

//MdE principal

void ControlCinta();
void MotorVel1();
void MotorVel2();
void ApagarMotor();
void MostrarEmergencia();
void LimpiarMensaje();
void resetControlCinta();
uint8_t Tecla0();
uint8_t Tecla1();
uint8_t Tecla2();

//estado compuesto para el control de velocidad

void Velocidad();
void leerPinEncoder();
void IniciarTimer0_1S();
void Expiro_T0_1S();

#endif /*MAQUINAESTADOS_H_*/
