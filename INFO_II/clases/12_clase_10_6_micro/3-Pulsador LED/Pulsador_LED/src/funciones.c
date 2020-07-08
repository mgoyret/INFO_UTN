/**
*	\file funciones.c
*	\brief Contiene la máquina de estados y funciones necesarias
*	\details
*	\author Federico Bua
*	\date 31-03-2019 17:38:41
*/




int estado_p2 = 0 ;int estado_p1 = 0 ;
#include "funciones.h" 

//Implementacion Switch-Case

/**
*	\fn void maquina_estado()
*	\brief Implementacion Switch-Case
*	\details Cambia el estado de un LED dependiendo del estado de la máquina de estado (APAGADO-PRENDIDO) a través de dos teclas del Infotronic
*	\author Federico Bua
*	\date 31-03-2019 17:38:41
*/
void maquina_estado()
{
		static int estado = APAGADO;

		switch(estado)
		{
			case APAGADO:
			
				estado_p1=consultar(KEY0);
				if(estado_p1==APRETADO)
				{
					LED(ON);
					estado = PRENDIDO;
				}
				if(estado_p1!=APRETADO)
				{
					estado = APAGADO;
				}


				break;
			
			case PRENDIDO:


				estado_p2=consultar(KEY1);
				if(estado_p2==APRETADO)
				{
					LED(OFF);
					estado = APAGADO;
				}
				if(estado_p2!=APRETADO)
				{
					estado = PRENDIDO;
				}

				break;
			
			default: estado = APAGADO;
		}


}


void LED (uint8_t estado)
{
	LedsRGB(ROJO,estado);
}


void inicializar (void)
{

	InicializarRGB(); //Inicializo LED RGB del Infotronic
	LedsRGB(ROJO,OFF); //Apago ROJO
	LedsRGB(AZUL,OFF); //Apago AZUL
	LedsRGB(VERDE,OFF); //Apago VERDE

	InicializarTeclado(); //Inicializo teclas del Infotronic

}

uint8_t consultar (uint8_t puerto, uint8_t pin)
{
	uint8_t estado;
/*======================================
Puerto y pin están dados por el conexionado de las teclas con el LPC1769
En el archivo DR_Infotronic.h:
#define		KEY0			PORT2,10
#define		KEY1			PORT0,18
#define		KEY2			PORT0,11
#define		KEY3			PORT2,13		// EINT3
 *
 */
	estado=GetPIN(puerto,pin, BAJO); //BAJO hace referencia a si el teclado es activo bajo o alto (Teclas del infotronic son activo bajo, es decir, están apretadas cuando al pin del LPC le llega un 0
	if(estado==1)
		return APRETADO;
	else
		return SOLTADO;

	/*Aclaración: podría haberse resuelto haciendo un "return estado;"*/
}
