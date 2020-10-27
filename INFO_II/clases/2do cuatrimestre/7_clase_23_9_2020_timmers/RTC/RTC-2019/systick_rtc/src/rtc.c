#include "myreg.h"

void Fijar_tiempo(uint32_t anio, uint8_t mes, uint8_t dia, uint8_t hora, uint8_t minutos, uint8_t segundos)
{
	YEAR = anio;
	MONTH = mes;
	DOM = dia;
	HOUR = hora;
	MIN = minutos;
	SEC = segundos;
}

void RTC_IRQHandler(void)
{
	if(ILR & 0x01) // Si interrumpio por counter
	{
		ILR |= 0x01;
		if(GetPIN(PORT0,22))
		{
			SetPIN(PORT0,22,0);
		}
		else
		{
			SetPIN(PORT0,22,1);
		}
	}
	if(ILR & 0x02) // Si interrumpio por alarma
	{

	}



}
