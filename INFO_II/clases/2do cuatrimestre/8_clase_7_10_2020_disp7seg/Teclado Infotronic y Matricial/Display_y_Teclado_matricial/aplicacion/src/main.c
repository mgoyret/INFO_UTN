#include "../../drivers/inc/FW_Display-Expansion3.h"
#include "funciones.h"
#include "GPIO.h"

uint8_t buffKey=NO_KEY;				//Buffer de teclado
volatile uint8_t msgDisplay[DIGITOS];	//Buffer de display

int main(void) {

	Inicializar();
    while(1) {
    	uint8_t tecla;
    	static uint32_t Val=0;
    	tecla = Teclado();

    	if(tecla==KEY0)
    			ROJO(ON);
    	if(tecla==KEY1)
    			AZUL(ON);
    	if(tecla==KEY2)
    	    	VERDE(ON);
    	if(tecla==KEY3)
    	{
    	    	ROJO(ON);
    			VERDE(ON);
    	}
    	if(tecla==5)
    	{
    		ROJO(OFF);
    		AZUL(OFF);
    		VERDE(OFF);
    	}
    }
    return 0 ;

}


void ROJO(uint8_t estado)
{
	SetPIN(RGB_RED,estado);
}
void AZUL(uint8_t estado)
{
	SetPIN(RGB_BLUE,estado);
}
void VERDE(uint8_t estado)
{
	SetPIN(RGB_GREEN,estado);
}
