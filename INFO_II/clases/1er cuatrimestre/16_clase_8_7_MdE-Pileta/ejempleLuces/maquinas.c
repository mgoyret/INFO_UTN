#include "include.h"

uint8_t Timer_5000 = FALSE;
uint8_t Timer_Periodicorio = FALSE;

void controlDeLuz (void)
{
    static uint8_t estado = APAGADO;

    switch (estado)
    {
    case APAGADO:
                if(Tecla0()) // == TRUE
                {
                    PrenderLuz();
                    IniciarTimer_5000();
                    estado = ENCENDIDO;
                }
        break;

    case ENCENDIDO:
                if(Timer_5000 == TRUE)
                {
                    ApagarLuz();
                    estado = APAGADO;
                }
        break;
    
    default:
            /* El umodel no me genera esta parte de default */
            ApagarLuz();
            DetenerTimer();
            estado = APAGADO;
        break;
    }
}

/* Esto es una fn buleana, se puede hacer o no el bool */
uint8_t Tecla0(void)
{
    uint8_t res;
    uint8_t tecla;

    tecla = GetTecla();
    if(tecla == SW0)
    {
        res = TRUE;
    }
    else
    {
        res = FALSE;   
    }
    

    return res;
}


void PrenderLuz(void)
{
    LedRGB(ROJO, OFF); //primitiva
}

void ApagarLuz(void)
{
    LedRGB(ROJO, ON); //primitiva
}

void IniciarTimer_5000(void)
{
    /*
        event hago define con el evento q dispara esto
    */
    TimerStart(E_LUZ, 5, handler(void) , SEG); //primitiva
}

void handler(void)
{
    Timer_5000 = TRUE;
}



void DetenerTimer(void)
{
    Timer_Close(); //primitiva. detiene todos los timers
//  Timer_Stop(E_LUZ); otra manera con otra primitiva. Detiene el tim. especificado  
}


//////////////////////////////////////////////////////////////////////////////////
/* Si nesecito algo periodico */

void IniciarTimer_Periodico(void)
{
    TimerStart(E_PERIODICO, 10, handlerPer(void) , SEG); //primitiva
}

void handlerPeriodico()
{
    Timer_Periodico = TRUE;
    TimerStart(E_PERIODICO, 10, handlerPer, SEG); //primitiva
}
/* En maquina() seria */
if(Timer_Pediodico == TRUE)
{
    //accion periodica
    Timer_Periodicorio = FALSE;
}
/* Cuando quiera lo apago */
