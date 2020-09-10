#include "maquinaestados.h"

uint8_t t0_flag10s = FALSE;
uint8_t t0_flag5s = FALSE;
uint8_t t1_flag10s = FALSE;
int huella = NO_HUELLA;

void ControlAcceso() {
	static uint8_t estado = ESPERANDO;

	switch(estado) {
		case ESPERANDO:
			if (huella == NO_HUELLA) {
				leerSensorHuella();
			} else if (Tecla0()) {
				AbrirPuerta();
				IniciarTimer0_10S();
				estado = VALIDA;
			} else if (huella != NO_HUELLA && huella != HUELLA_INVALIDA) {
				IniciarTimer1_10S();
				AbrirPuerta();
				EnviarTrama();
				estado = VALIDA;
			} else if (huella == HUELLA_INVALIDA) {
				PrenderLedRed();
				escribirNoHabilitado();
				IniciarTimer0_5S();
				estado = INVALIDA;
			}
			break;

		case INVALIDA:

			if (t0_flag5s) {
				escribirEsperando();
				t0_flag5s = FALSE;
				ApagarLedRed();
				estado = ESPERANDO;
			}

			break;

		case VALIDA:

			if (t1_flag10s) {
				CerrarPuerta();
				t1_flag10s = FALSE;
			} else if (Tecla0()) {
				IniciarTimer0_10S();
				AbrirPuerta();
			} else if (t0_flag10s) {
				escribirEsperando();
				CerrarPuerta();
				estado = ESPERANDO;
			}

			break;

		default:

			CerrarPuerta();
			escribirEsperando();
			huella = NO_HUELLA;
			ApagarLedRed();
			estado = ESPERANDO;

			break;
	}
}

uint8_t Tecla0() {
	return (GetTecla() == TECLA_0);
}

void IniciarTimer0_5S() {
	TimerStart(EV_T0_10S, 10, ExpiroT0_10S, SEG);
}

void ExpiroT0_10S() {
	t0_flag10s = TRUE;
}

void ExpiroT0_5S() {
	t0_flag5s = TRUE;
}

void ExpiroT1_10S() {
	t1_flag10s = TRUE;
}

void IniciarTimer1_10S() {
	TimerStart(EV_T1_10S, 10, ExpiroT0_10S, SEG);
}

void IniciarTimer0_10S() {
	TimerStart(EV_T0_5S, 5, ExpiroT0_10S, SEG);
}

void escribirEsperando() {
	Display("ESPERANDO");
}

void escribirNoHabilitado() {
	Display("NO HABILITADO");
}

void AbrirPuerta() {
	Relays(RELAY_PUERTA, PRENDIDO);
}

void CerrarPuerta() {
	Relays(RELAY_PUERTA, PRENDIDO);
}

void EnviarTrama() {
	char str[32];
	sprintf(str, "%d", huella);
	Transmitir(str);
}

void PrenderLedRed() {
	Leds_RGB(LED_ROJO, PRENDIDO);
}

void ApagarLedRed() {
	Leds_RGB(LED_ROJO, APAGADO);
}

void resetControlAcceso() {
	t0_flag10s = FALSE;
	t1_flag10s = FALSE;
	t0_flag5s = FALSE;
	ApagarLedRed();
	CerrarPuerta();
	escribirEsperando();
	huella = NO_HUELLA;
	Timer_Stop(EV_T0_5S);
	Timer_Stop(EV_T0_10S);
	Timer_Stop(EV_T1_10S);
}
