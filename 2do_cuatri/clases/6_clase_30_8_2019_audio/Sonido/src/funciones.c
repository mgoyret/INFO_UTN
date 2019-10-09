/**
	\file    funciones.c
	\brief   Archivo con las funciones para configurar el dispositivo de audio
	\author  Spataro, Hector hspataro@frba.utn.edu.ar
	\date    2019.08.30
	\version 1.1.0
*/


//--------------
//-- Includes --
//--------------

#include "../inc/funciones.h"


/**
	\fn 	void set_audio_params (int fd)
	\brief  Se encarga de establecer los valores de velocidad de muestreo (Sampling Rate) 
		Sample Size (tamaño de la muestra), y número de canales, en la placa de audio del sistema.
		Utiliza la syscall ioctl (), (input output control), para acceder al dispositivo mediante el formato 
		establecido por la interfaz de sonido de LNUX, y el formato genérico de ioctl (file_descriptor, nombre 
		del parámetro, puntero al valor a escribir);
	\author  Spataro, Hector hspataro@frba.utn.edu.ar
	\date    2019.08.30
	\param  int fd: File Descriptor asociado al dispositivo de audio (/dev/dsp)
	\param  audio_params valor: Estructura con los parámetros para configurar el dispositivo de audio. 
		Recibido por referencia para que la función que la llamó sepa en cuanto se configuró.
*/


void set_audio_params (int fd, audio_params * valor)
{
	int 	arg;		/* argumento para ioctl */
	int	status;		/* salida de ioctl */

	/* seteamos los parametros de muestreo  */
	arg = valor->t_muestra;	   /* arg = Tamaño de muestra */
	status = ioctl(fd, SOUND_PCM_WRITE_BITS, &arg); 

	/* 
	SOUND_PCM_WRITE_BITS es la macro que escribe en la placa de sonido (a través del driver por supuesto), el valor
	del tamaño de muestra en bits que seteamos en la variable arg, cuyo puntero se provee como tercer argumento a ioctl().
	La interfaz genérica de audio manejada por streams traduce comandos generales a los comandos particulares para el
	hardware de modo transparente al programador
	*/
	if (status == -1) 
		perror("Error con comando SOUND_PCM_WRITE_BITS");

	/*
	El hecho que ioctl devuelva error no quiere decir que no se haya configurado el parámetro que se quiso programar.
	Por lo general la variable pasada por referencia vuelve con el valor programado si el original no estaba entre los
	posibles valores del parámetro que se quiso configurar. Por ejemplo, Tamaño de muestra: si arg hubiese ido en un
	valor por ejemplo 13, o 15, seguramente no coicidiría con los valores posibles para configurar el conversor A/D de
	la placa de sonido.
	En tal caso el driver programa al valor mas cercano al argumento recibido,modifica la variable recibda como
	referencia al valor, para que el programa que lo envió pueda saber el valor con el que se configuró, y hace que la
	función devuelva -1, para que se pueda analizar el error y tomar nota del valor configurado finalmente.
	*/

	if (arg != valor->t_muestra)
	{
		fprintf (stderr,"Tamaño de muestras no soportado. Se programó %d\n",arg);
		valor->t_muestra = arg;
	}

	/* mono o stereo */
	arg = valor->c_canales;
	status = ioctl(fd, SOUND_PCM_WRITE_CHANNELS, &arg);
	if (status == -1)
		perror("Error en comando SOUND_PCM_WRITE_CHANNELS");
	if (arg != valor->c_canales)
	{
		fprintf (stderr,"Cantidad de canales no soportado. Se programó %d\n",arg);
		valor->c_canales = arg;
	}


	/* Velocidad de Muestreo */
	arg = valor->v_muestreo;
	status = ioctl(fd, SOUND_PCM_WRITE_RATE, &arg);
	if (status == -1)
		perror("Error en comando SOUND_PCM_WRITE_RATE");
	if (arg != valor->v_muestreo)
	{
		fprintf (stderr,"Velocidad de muestreo no soportada. Se programó %d\n",arg);
		valor->v_muestreo = arg;
	}

	return;
}

//-------------------------------------------------------------------
