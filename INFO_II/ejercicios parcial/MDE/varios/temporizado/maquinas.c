#include "lo que sea.h"

void controlLuz (void)
{
	static uint8_t estado = APAGADO ;

	switch(estado)
	{
		case APAGADO:
			if(Tecla0() == TRUE)
			{
				PrenderLuz();
				IniciarTimer_5000();
				estado = ENCENDIDO ;
			}				
			break;

		case ENCENDIDO:

			
			//original
			if(Timer_5000 == SI)
			{
				ApagarLuz();
				estado = APAGADO ;		
			}
			
			break;


		default:
			ApagarLuz();
			DetenerTimer();

			estado = APAGADO ;
	
	}

}


typedef uint8_t		unsigned char ;

#define SI	1
#define NO	0

uint8_t Tecla0(void)
{
	uint8_t res ;
	uint8_t tecla;

	tecla = GetTecla();

	//TECLA_0 es un define
	if(tecla == TECLA_0)
	{
		res = SI;
	}
	else
	{
		res = NO ;
	}	


	return res;
}



void PrenderLuz(void)
{
	LedRGB(ROJO,ON);
}

void ApagarLuz(void)
{
	LedRGB(ROJO,OFF);
}

void IniciarTimer_5000(void)
{
	TimerStart(E_LUZ,5,funcion,SEG);  

	//TimerStart(E_OTRO,10,otraFuncion,DEC); 
	
}



void funcion (void)
{
	Timer_5000 = SI;	
}

/*
void otraFuncion(void)
{
	flagOtro = SI;
}
*/

void DetenerTimer(void)
{
	//opcion 1 detengo todos
	Timer_Close();

	//opcion 2 detengo EL timer
	Timer_Stop(E_LUZ);
}

void IniciarTimerPeriodico(void)
{
	TimerStart(E_PERIODICO,10,Periodico,SEG);  

	
}


void Periodico()
{
	Timer_Periodico = SI;
	TimerStart(E_PERIODICO,10,Periodico,SEG);  


}


void maquina()
{
	if(Timer_Periodico == SI)
	{

//		TO-DO

		Timer_Periodico = NO;

	}


}

void ApagarTimerPeriodico()
{
	Timer_Stop(E_PERIODICO);
}