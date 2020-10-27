#include "myreg.h"

void SysTick_Handler(void)
{
static uint8_t centesimas = 10;
static uint8_t decimas = 10;
static uint8_t segundos = 60;
static uint8_t minutos = 60;
static uint8_t horas = 24;

Funciones_centesimas();
centesimas --;
if(!centesimas)
{
	centesimas = 10;
	decimas --;
	Funciones_decimas();
}
if(!decimas)
{
	decimas = 10;
	segundos --;
	Funciones_segundos();
}
if(!segundos)
{
	segundos = 60;
	minutos --;
	Funciones_minutos();
}
if(!minutos)
{
	minutos = 60;
	horas --;
	Funciones_horas();
}
if(!horas)
{
	horas = 24;
	Funciones_dias();
}

}
void Funciones_centesimas(void)
{

}

void Funciones_decimas(void)
{

}

void Funciones_segundos(void)
{
	if(GetPIN(PORT2,2)==0)
		SetPIN(PORT2,2,1);
	else
		SetPIN(PORT2,2,0);
}

void Funciones_minutos(void)
{

}

void Funciones_horas(void)
{

}

void Funciones_dias(void)
{

}
