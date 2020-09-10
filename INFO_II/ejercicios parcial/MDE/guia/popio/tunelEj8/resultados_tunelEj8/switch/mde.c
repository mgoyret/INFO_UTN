/**
*	\file mde.c
*	\brief Implementacion switch-case
*	\details Descripcion detallada del archivo
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/

#include "mde.h" 


extern int presenciaActual;
extern int sonar;
extern int timerFin;
extern int timerSirenaFin;
extern int tramaFin;


/**
*	\fn void maquina_general()
*	\brief Implementacion switch-case
*	\details 
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void maquina_general()
{
		static int estado = ESPERANDO;

	switch(estado)
	{
		case ESPERANDO:
			if( ingreso( ) )
			{
				#ifdef DEPURAR
					Log( 0 , 0 , 0 );
				#endif
				presenciaActual = TRUE;
				iniciarTimer_10s( );
				estado = VEICULO;	
			}
			break;
			
		case VEICULO:
			if( egreso( ) )
			{
				#ifdef DEPURAR
					Log( 0 , 1 , 0 );
				#endif
				detenerTimer();
				presenciaActual = FALSE;
				estado = ESPERANDO;	
			}
			if( timerFin == TRUE )
			{
				#ifdef DEPURAR
					Log( 0 , 1 , 1 );
				#endif
				/* Restablesco valor de variable para que no entre al if */
				timerFin = FALSE;
				sonar = TRUE;
				estado = SIRENA;	
			}
			break;
			
		case SIRENA:
			maquina_recepcion_trama();
			if( egreso() || TECLA0() || (tramaFin==TRUE) )
			{
				#ifdef DEPURAR
					Log( 0 , 2 , 0 );
				#endif
				tramaFin = FALSE;
				/* En realidad, si se presiono el boton el veiculo sigue dentro, pero
				como el enunciado no especifica nada aqui, presupongo que se retira de inmediato
				el veiculo del tunel ya que el led estara verde */
				presenciaActual = FALSE;
				sonar = FALSE;
				estado = ESPERANDO;	
			}
			/* Lo pongo luego del if(), asi en la misma vuelva que
			se de egreso()/TECLA0() la sirena se apaga por sonar=false */
			maquina_sirena();//estado compuesto
			break;
			
		default:
			reset_general();
			estado = ESPERANDO;
			break;
	}
}

/**
*	\fn void maquina_led()
*	\brief Implementacion switch-case
*	\details 
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void maquina_led()
{
	static int estado = VERDE;

	switch(estado)
	{
		case VERDE:
			if( presenciaActual == TRUE )
			{
				#ifdef DEPURAR
					Log( 1 , 0 , 0 );
				#endif
				rojoOn( );
				verdeOff( );
				estado = ROJA;	
			}
			break;
			
		case ROJA:
		/* Viendo la maquina general, se ve que la luz roja solo se apaga si el veiculo sale
			o en caso de sonar la alarma, si se presiona el boton antes. Pero continua roja cuando
			suena la alarma */
			if( presenciaActual == FALSE )
			{
				#ifdef DEPURAR
					Log( 1 , 1 , 0 );
				#endif
				rojoOff( );
				verdeOn( );
				estado = VERDE;	
			}
			break;
			
		default:
			reset_led();
			estado = VERDE;
	}
}

/**
*	\fn void maquina_sirena()
*	\brief Implementacion switch-case
*	\details 
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
void maquina_sirena()
{
		static int estado = STANDBY;

	switch(estado)
	{
		case STANDBY:
			if( sonar == TRUE )
			{
				#ifdef DEPURAR
					Log( 2 , 0 , 0 );
				#endif
				iniciarTimerSirena( );
				sirenaOn( );
				estado = ON;	
			}
			break;
		
		case ON:
			if( sonar == FALSE )
			{
				#ifdef DEPURAR
					Log( 2 , 1 , 0 );
				#endif
				detenerTimerSirena( );
				sirenaOff( );
				estado = STANDBY;	
			}
			if( (timerSirenaFin == TRUE) && (sonar == TRUE) )
			{
				#ifdef DEPURAR
					Log( 2 , 1 , 1 );
				#endif
				/* Restablesco valor de variable para que no entre al if */
				timerSirenaFin = FALSE;
				iniciarTimerSirena( );	
				sirenaOff( );
				estado = OFF;	
			}
			break;
		
		case OFF:
			if( (timerSirenaFin == TRUE) && (sonar == TRUE) )
			{
				#ifdef DEPURAR
					Log( 2 , 2 , 0 );
				#endif
				timerSirenaFin = FALSE;
				iniciarTimerSirena( );
				sirenaOn( );
				estado = ON;	
			}
			if( sonar == FALSE )
			{
				#ifdef DEPURAR
					Log( 2 , 2 , 1 );
				#endif
				detenerTimerSirena();
				estado = STANDBY;
			}
			break;
		
		default:
			reset_sirena();
			estado = STANDBY;
	}
}

void maquina_central_control()
{
	static int estado = ESPERANDO;
	switch (estado)
	{
	case ESPERANDO:
		if( sonar == TRUE )
		{
			#ifdef DEPURAR
				Log( 3 , 0 , 0 );
			#endif
			estado = SIRENA;
		}
		break;
	
	case SIRENA:
		if( TECLA0() )
		{
			#ifdef DEPURAR
				Log( 3 , 1 , 0 );
			#endif
			enviarTrama();
		}
		if( sonar == FALSE )
		{
			#ifdef DEPURAR
				Log( 3 , 1 , 1 );
			#endif
			estado = ESPERANDO;
		}
		break;

	default: estado = ESPERANDO;
	}
}

void maquina_recepcion_trama( void )
{
	static int estado = ESPERANDO;
	int16_t aux, final;
	static int16_t buf[MSGTAM], cant=0;
	
	aux = Recibir(0);
	switch (estado)
	{
		case ESPERANDO:
			if(aux == INICIO)
			{
				estado = LEYENDO;
			}
			break;
		case LEYENDO:
			if( (aux != -1) && (cant < MSGTAM) )
			{
				guardoAux(aux, buf, cant); // aca adentro hago cant++
				cant++;
			}
			if( (aux != -1) && (cant == MSGTAM) )
			{
				final = aux;
				estado = CHECK;
			}
			break;
		case CHECK:
			if((final == FIN) && (tramaFinCheck(buf)==TRUE))
			{
				tramaFin = TRUE;
			}
			if( final != FIN)
			{
				tramaFin = FALSE;
			}
	default:
			estado = ESPERANDO;
			tramaFin = FALSE;
		break;
	}
}

/**
*	\fn int recibiTrama(void)
*	\brief Yo guarde la trama en c[5] pero en realidad no haria falta
*	\details Detalles
*	\author marcosGoyret
*	\date 24-07-2020 23:57:54
*/
/*
int recibiTrama()
{
	static int trcv = 0;
	int res = FALSE;
	int16_t aux, c[5];
	aux = Recibir(0);
	if( aux == 0xAA)
		c[0] = aux;
		trcv=1;
	switch (trcv)
	{
	case 0:
		aux = Recibir(0);
		if( aux == 0xAA)
			c[0] = aux;
			trcv=1;
		break;
	case 1:
		aux = Recibir(0);
		if(aux = 'O')
		{
			c[1]=aux;
			trcv=2;	
		}
		if((aux != 'O') && (aux != -1))//llego dato pero no pertenece a trama deseada
		{
			trcv=0;
		}
		break;
	case 2:
		aux = Recibir(0);
		if(aux = 'F')
		{
			c[2]=aux;
			trcv=3;
		}
		if((aux != 'F') && (aux != -1))//llego dato pero no pertenece a trama deseada
		{
			trcv=0;
		}
		break;
	case 3:
		aux = Recibir(0);
		if(aux = 'F')
		{
			c[3]=aux;
			trcv=4;
		}
		if((aux != 'F') && (aux != -1))//llego dato pero no pertenece a trama deseada
		{
			trcv=0;
		}
		break;
	case 4:
		aux = Recibir(0);
		if(aux = 0xEE)
		{
			c[4]=aux;
			// * Restauro la variable trcv, pero la funcion devuelve TRUE por lo que se sabe que se recibio la trama de fin
			// * Si se estaba recibiendo la trama pero antes de eso, el veiculo salio o se presiono el boton, no importa, este proceso se restablecera solo
			trcv=0;	
			res=TRUE;
		}
		if((aux != 0xAA) && (aux != -1))//llego dato pero no pertenece a trama deseada
		{
			trcv=0;
		}
		break;

	default:
		break;
	}
	return res;
}
*/