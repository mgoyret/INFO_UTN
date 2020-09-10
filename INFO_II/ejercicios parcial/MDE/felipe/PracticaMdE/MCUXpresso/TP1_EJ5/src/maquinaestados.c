#include "maquinaestados.h"

//global cant_autos definida en el main

uint8_t timer0_expirado = 0;
uint8_t cant_autos = 0;

void ControlAutos (void) {
	static uint8_t estado = ESPERANDO;

	switch (estado) {
		case ESPERANDO:
			if (timer0_expirado) {
				ApagarRele1();
				timer0_expirado == FALSE; //para que no se apague sucesivamente
			} else if (sensorizquierda_presencia()) {
				estado = SALIENDO;
			} else if (sensorderecha_presencia()) {
				estado = ENTRANDO;
			}
			break;
		case SALIENDO:
			if (sensorderecha_presencia() && sensorizquierda_presencia()) {
				PrenderRele1();
			} else if (!sensorderecha_presencia() && !sensorderecha_presencia()) {
				cant_autos--;
				IniciarTimer0_10S();
				estado = ESPERANDO;
			} else if (!sensorizquierda_presencia()) {
				estado = ESPERANDO;
			}
			break;
		case ENTRANDO:
			if (sensorderecha_presencia() && sensorizquierda_presencia()) {
				PrenderRele1();
			} else if (!sensorderecha_presencia() && !sensorderecha_presencia()) {
				cant_autos++;
				IniciarTimer0_10S();
				estado = ESPERANDO;
			} else if (!sensorderecha_presencia()) {
				estado = ESPERANDO;
			}
			break;
		default:
			resetControlAutos();
			break;
	}
}

void timerExpirado() {
	timer0_expirado = TRUE;
}

void IniciarTimer0_10S() {
	timer0_expirado = FALSE;
	StartTimer(EVENTO10SEG, 10, timerExpirado, SEG); //funcion de la libreria
}

uint8_t sensorderecha_presencia() {
	return Entradas(SENSOR_DERECHA);
}

uint8_t sensorizquierda_presencia() {
	return Entradas(SENSOR_IZQUIERDA);
}

void ApagarRele1() {
	Relay(RELE_1, APAGADO);
}

void PrenderRele1() {
	Relay(RELE_1, PRENDIDO);
}

void resetControlAutos(){
	cant_autos = 0;
	ApagarRele1();
	Timer_Close();
}
