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

typedef unsigned char uint8_t;

void ControlAcceso();
void resetControlAcceso();
void escribirEsperando();
void escribirNoHabilitado();
void IniciarTimer0_5S();
void IniciarTimer0_10S();
void IniciarTimer1_10S();
void ExpiroT0_10S();
void ExpiroT0_5S();
void ExpiroT1_10S();
void AbrirPuerta();
void CerrarPuerta();
void EnviarTrama();
uint8_t Tecla0();
void PrenderLedRed();
void ApagarLedRed();

//PRIMITIVAS DEL TP
void Display(char *);
void Transmitir(char*);
void leerSensorHuella(); //supongo que esta primitiva modifica la global "huella"

#endif /*MAQUINAESTADOS_H_*/
