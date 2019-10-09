/**
	\file    Sound.c
	\brief   Función principal del programa que se encarga de grabar y reproducir sonidos.
	\author  Spataro, Hector hspataro@frba.utn.edu.ar
	\date    2019.08.30
	\version 1.1.0
*/


//--------------
//-- Includes --
//--------------

#include "../inc/funciones.h"

/**
	\fn      int main()
	\brief   Función principal para la grabación y reproducción a través de la placa de sonido.
	\author  Spataro, Hector hspataro@frba.utn.edu.ar
	\date    2019.08.30
	\return  salida: Codigo de finalización de la función:
		 0: Todo bien
	 	 1: No pudo abrir el dispositivo de audio
		 2: No pudo leer el dispositivo de audio
		 5: No pudo escribir en el dispositivo de audio
*/

int main()
{
	int dspfd;	/* sound device file descriptor */
	int status;	/* return status de system calls */

	audio_params config = {RATE, SIZE, CHANNELS};
	int buffsize;
	int salida = 0;

 	unsigned char * buf = NULL;

	/* Configuración del bufer para el audio */
	buffsize = MSEG*config.v_muestreo*config.t_muestra*config.c_canales/BITS;
 	buf = (unsigned char *) malloc(buffsize);

	/* Abrimos el dispositivo de audio */
	if ((dspfd = open("/dev/dsp", O_RDWR))<0)
	{
		fprintf(stderr,"Error en función open, Código de error: %s\n",strerror (dspfd)); 
		salida = 1;
	}

	if (!salida)
	{
		/*Seteamos parámetros de audio*/
		set_audio_params (dspfd, &config);

		while (1)
		{
		/* Termina con Control-C */
			printf("Hablale al microfono ;):\n");

			/*La siguiente función bloquea al proceso hasta que se llene el buffer. Esto con archivos comunes 
			no se nota, pero con un dispositivo de audio en donde se leen 8000 muestras por segundo.....*/

			status = read(dspfd, buf, buffsize); /* lee */
			if (status != buffsize)
			{
				fprintf(stderr,"Error en función read, Código de error: %s\n",strerror (status));
				salida = 2;
			}

			if (!salida)
			{
				printf("Dijiste :\n");

				/* Write generalmente no bloquea hasta que termina. Sino que envía la información presente en el
				buffer al kernel. Por eso luego de enviar, vamos a sincronizar con ioctl ()*/

				status = write(dspfd, buf, buffsize); /* reproduce */
				if (status != buffsize)
				{
					fprintf(stderr,"Error en función write, Código de error: %s\n",strerror (status)); 
					salida = 3;
				}

				/* Espera a que termine de hacer el playback antes de volver a grabar */
 				status = ioctl(dspfd, SOUND_PCM_SYNC, 0);
	 			if (status == -1)
				{
 					perror("Error en comando SOUND_PCM_SYNC");
				}

			}

		}
	}

	if (salida > 1) close(dspfd);

	if (buf) free (buf);
	return salida;
}
