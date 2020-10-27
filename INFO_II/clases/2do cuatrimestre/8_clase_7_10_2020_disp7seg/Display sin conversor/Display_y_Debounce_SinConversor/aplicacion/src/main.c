#include "funciones.h"
#include "FW_Display-Expansion2.h"


uint8_t buffKey;				//Buffer de teclado
volatile uint8_t msgDisplay[DIGITOS];	//Buffer de display

int main(void) {

	Inicializar();
    while(1) {
    	uint8_t tecla;
    	static uint32_t Val=0;
    	tecla = Teclado();

    	if(tecla==KEY0)
    			Val=Val+1;
    	if(tecla==KEY1)
    			Val=Val+10;
    	if(tecla==KEY2)
    	    	Val=Val+100;
    	if(tecla==KEY3)
    	    	Val=Val+1000;
    	if(tecla==KEY4)
    			Val=0;


    	Display(Val);

    }
    return 0 ;

}
