#include "maquinaestados.h"

uint8_t emergencia = FALSE, t0_flag1s = FALSE, pinEncoder = FALSE;
unsigned short velocidad = 0; //en cm/seg

void ControlCinta() {
	static uint8_t estado = PARADA;

	switch(estado) {
		case PARADA:

			if (Tecla0()) {
				PrenderMotor();
				MotorVel1();
				estado = VEL1;
			}

			break;

		case VEL1:

			if (emergencia) {
				ApagarMotor();
				MostrarEmergencia();
				estado = EMERGENCIA;
			} else if (Tecla1()) {
				MotorVel2();
				estado = VEL2;
			} else if (Tecla0()) {
				ApagarMotor();
				estado = PARADA;
			}

			Velocidad();

			break;

		case VEL2:

			if (emergencia) {
				ApagarMotor();
				MostrarEmergencia();
				estado = EMERGENCIA;
			} else if (Tecla2()) {
				MotorVel1();
				estado = VEL1;
			} else if (Tecla0()) {
				ApagarMotor();
				estado = PARADA;
			}

			Velocidad();

			break;

		case EMERGENCIA:

			if (Tecla0()) {
				emergencia = FALSE;
				LimpiarMensaje();
				estado = PARADA;
			}

			break;

		default:

			estado = EMERGENCIA;

			break;
	}
}

void MotorVel1() {
	Salida(MOTOR_VEL1, PRENDIDO);
	Salida(MOTOR_VEL2, APAGADO);
}

void MotorVel2() {
	Salida(MOTOR_VEL2, PRENDIDO);
	Salida(MOTOR_VEL1, APAGADO);
}

void ApagarMotor() {
	Salida(MOTOR_VEL1, APAGADO);
	Salida(MOTOR_VEL2, APAGADO);
}

void MostrarEmergencia() {
	Display("EMERGENCIA"); //asumo la primitiva
}

void LimpiarMensaje() {
	Display("");
}

uint8_t Tecla0() {
	return (GetTecla() == TECLA_0) ? TRUE : FALSE;
}

uint8_t Tecla1() {
	return (GetTecla() == TECLA_1) ? TRUE : FALSE;
}

uint8_t Tecla2() {
	return (GetTecla() == TECLA_2) ? TRUE : FALSE;
}

void resetControlCinta() {
	ApagarMotor();
	Timer_Stop(EV_T0_1S);
}

void Velocidad() {
	static uint8_t estado = BAJO;
	static uint8_t mostrarvel = FALSE;
	static short pulsos = 0;

	switch(estado) {
		case BAJO:

			if (t0_flag1s) {
				mostrarvel = TRUE;
				t0_flag1s = FALSE;
			} else if (mostrarvel) {
				velocidad = pulsos / PULSOS_POR_CM;
				estado = MOSTRAR;
			} else if (!pinEncoder) {
				leerPinEncoder();
			} else if (pinEncoder) {
				estado = ALTO;
			}

			break;

		case ALTO:

			if (t0_flag1s) {
				mostrarvel = TRUE;
			} else if (mostrarvel) {
				velocidad = pulsos / 10;
				estado = MOSTRAR;
			} else if (pinEncoder) {
				leerPinEncoder();
			} else if (!pinEncoder) {
				pulsos += 1;
				estado = BAJO;
			}

			break;

		case MOSTRAR:

			if (mostrarvel && !velocidad) {
				emergencia = TRUE;
			} else if (mostrarvel) {
				MostrarVelocidad();
				mostrarvel = FALSE;
				velocidad = 0;
				pulsos = 0;
				pinEncoder = FALSE;
				IniciarTimer0_1S();
				estado = BAJO;
			}

			break;

		default:

			mostrarvel = FALSE;
			velocidad = 0;
			pulsos = 0;
			pinEncoder = FALSE;
			IniciarTimer0_1S();
			estado = BAJO;

			break;


	}

}

void leerPinEncoder() {
	pinEncoder = (Entrada(PIN_ENCODER) == TRUE) ? TRUE : FALSE;
}

void IniciarTimer0_1S() {
	Timer_Start(EV_T0_1S, 1, Expiro_T0_1S, SEG);
}

void Expiro_T0_1S() {
	t0_flag1s = TRUE;
}

