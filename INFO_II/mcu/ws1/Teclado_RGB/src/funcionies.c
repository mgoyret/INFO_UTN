/**
*	\file funciones.c
*	\brief Contiene la máquina de estados y las funciones para LED, teclado
*	\details Para más información del funcionamiento leer la descripción del main.c
*	\author Federico Bua
*	\date 02-04-2019 16:23:41
*/





int pulsador0 = 0 ;int pulsador1 = 0 ;int pulsador2 = 0 ; //estado de los pulsadores
#include "funciones.h"


//Implementacion Switch-Case

/**
*	\fn void maquina_estado()
*	\brief Implementacion Switch-Case
*	\details
*	\author Federico Bua
*	\date 02-04-2019 16:23:41
*/
void maquina_estado()
{
	static int estado = APAGADO; //estado inicial

	switch(estado)
	{
		case APAGADO:

			pulsador0=consultar(KEY0);
			pulsador1=consultar(KEY1);
			pulsador2=consultar(KEY2);

			if((pulsador0==APRETADO) || (pulsador1==APRETADO)|| (pulsador2==APRETADO))
			{
				PrenderLedRed( );
				PrenderLedBlue( );
				ApagarLedGreen( );

				estado = eVIOLETA;
			}
			break;
////////////////////////////////////////////////////////////////////////////////////////
		case eVIOLETA:

			pulsador0=consultar(KEY0);
			if(pulsador0==APRETADO)
			{
				PrenderLedGreen( );
				ApagarLedBlue( );
				ApagarLedRed( );

				estado = eVERDE;
			}
			break;
/////////////////////////////////////////////////////////////////////////////////////////
		case eROJO:

			pulsador0=consultar(KEY0);
			pulsador1=consultar(KEY1);
			if(pulsador1==APRETADO)
			{
				PrenderLedBlue( );
				ApagarLedRed( );
				ApagarLedGreen( );

				estado = eAZUL;
			}
			if(pulsador0==APRETADO)
			{
				PrenderLedGreen( );
				ApagarLedRed( );
				ApagarLedBlue( );

				estado = eVERDE;
			}

			break;
/////////////////////////////////////////////////////////////////////////////////////////
		case eVERDE:

			pulsador1=consultar(KEY1);
			pulsador2=consultar(KEY2);
			if(pulsador1==APRETADO)
			{
				PrenderLedBlue( );
				ApagarLedRed( );
				ApagarLedGreen( );

				estado = eAZUL;
			}
			if(pulsador2==APRETADO)
			{
				PrenderLedRed( );
				ApagarLedGreen( );
				ApagarLedBlue( );

				estado = eROJO;
			}

			break;
/////////////////////////////////////////////////////////////////////////////////////////
		case eAZUL:

			pulsador2=consultar(KEY2);
			pulsador0=consultar(KEY0);
			if(pulsador2==APRETADO)
			{
				ApagarLedGreen( );
				ApagarLedBlue( );
				PrenderLedRed( );

				estado = eROJO;
			}
			if((pulsador0==APRETADO))
			{
				PrenderLedGreen( );
				ApagarLedRed( );
				ApagarLedBlue( );

				estado = eVERDE;

			}
			break;
/////////////////////////////////////////////////////////////////////////////////////////
		default: estado = APAGADO;
/////////////////////////////////////////////////////////////////////////////////////////
	}
}

//Funciones asociadas a los eventos

//Funciones asociadas a las acciones


void PrenderLedRed(  )
{
	LedsRGB(ROJO,ON);
}
void PrenderLedGreen(  )
{
	LedsRGB(VERDE,ON);
}
void PrenderLedBlue(  )
{
	LedsRGB(AZUL,ON);
}
void ApagarLedRed(  )
{
	LedsRGB(ROJO,OFF);
}
void ApagarLedGreen(  )
{
	LedsRGB(VERDE,OFF);
}
void ApagarLedBlue(  )
{
	LedsRGB(AZUL,OFF);
}



void inicializar(void)
{
//	InicializarRGB(); //Inicializo LED RGB del Infotronic
//	LedsRGB(ROJO,ON); //Apago ROJO
//	LedsRGB(AZUL,ON); //Apago AZUL
//	LedsRGB(VERDE,ON); //Apago VERDE

	InicializarTeclado(); //Inicializo teclas del Infotronic
	InicializarBuzzer();
	Buzzer(OFF);

}

/*=======Para más información de esta función leer el ejemplo Pulsador_Y_LED=================*/
uint8_t consultar (uint8_t puerto, uint8_t pin)
{
	uint8_t estado;

	estado=GetPIN(puerto,pin, BAJO); //BAJO hace referencia a si el teclado es activo bajo o alto (Teclas del infotronic son activo bajo, es decir, están apretadas cuando al pin del LPC le llega un 0
	if(estado==1)
		return APRETADO;
	else
		return SOLTADO;
}


