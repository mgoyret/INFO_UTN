
#include "TodosLosHeaders.h"

int main()
{
	inicializacion();
	inicializacionMdE();

	while(1)
	{
		maquina_ControLuces();
	}

	return 0;
}

void inicializacionMdE()
{

//	inicializarControlLuz();

	// para la maquina de control de luces
	ApagarLuz();
	DetenerTimer();
}