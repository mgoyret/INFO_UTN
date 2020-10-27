#include "myreg.h"

void TIMER0_IRQHandler(void)
{
// Verifico cual fué la fuente de interrupcion. Al ser un ejemplo ponemos todas, pero en esta sección obviamente van las
// posibles, es decir las que habilité en mi función de inicialización.
	if(T0IR & 0x01) // Si interrumpió por Match 0
	{
		T0IR |= 0x01;
		Atencion_T0_M0();
	}
	if(T0IR & 0x02) // Si interrumpió por Match 1
	{
		T0IR |= 0x02;
		Atencion_T0_M1();
	}
	if(T0IR & 0x04) // Si interrumpió por Match 2
	{
		T0IR |= 0x04;
		Atencion_T0_M2();
	}
	if(T0IR & 0x08) // Si interrumpió por Match 3
	{
		T0IR |= 0x08;
		Atencion_T0_M3();
	}
	if(T0IR & 0x10) // Si interrumpió por captura 0
	{
		T0IR |= 0x10;
		Atencion_T0_C0();
	}
	if(T0IR & 0x20) // Si interrumpió por captura 1
	{
		T0IR |= 0x20;
		Atencion_T0_C1();
	}
}

void Atencion_T0_M0(void)
{
	static int led = 0;
		if(led == 0)
		{
			SetPIN(PORT2,3,0);
			SetPIN(PORT2,2,0);
			SetPIN(PORT2,1,1);
		}
		if(led == 1)
		{
			SetPIN(PORT2,3,0);
			SetPIN(PORT2,2,1);
			SetPIN(PORT2,1,0);

		}
		if(led == 2)
		{
			SetPIN(PORT2,3,1);
			SetPIN(PORT2,2,0);
			SetPIN(PORT2,1,0);
			led = -1;
		}
	led++;
		if(T0MR0 == 400000)
		{
			T0MR0 = 0;
		}
		else
		{
			T0MR0 = T0MR0 + 100000;
		}
}
void Atencion_T0_M1(void)
{
	if(GetPIN(PORT0,28))
		{
			SetPIN(PORT0,28,0);
		}
		else
		{
			SetPIN(PORT0,28,1);
		}
}
void Atencion_T0_M2(void)
{

}
void Atencion_T0_M3(void)
{

}
void Atencion_T0_C0(void)
{

}
void Atencion_T0_C1(void)
{

}
