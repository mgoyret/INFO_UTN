/**
	\file    Record.c
	\brief   Función principal del programa que se encarga de grabar sonidos.
	\author  Spataro, Hector hspataro@frba.utn.edu.ar
	\date    2019.08.30
	\version 1.1.0
*/


//--------------
//-- Includes --
//--------------

#include "../inc/funciones.h"


/**
	\fn      int main(int argc, char ** argv)
	\brief   Función principal para la grabación de archivos a través de la placa de sonido.
	\author  Spataro, Hector hspataro@frba.utn.edu.ar
	\date    2019.08.30
	\param   int argc: Cantidad de parametros que se pasaron por línea de comando
	\param   char ** argv: Vector de punteros a string que apunta a los parámetros pasados por línea de comando.
	\return  salida: Codigo de finalización de la función:
		 0: Todo bien
	 	 1: Error en los argumentos de la línea de comando
		 2: No pudo abrir el archivo a reproducir
		 3: No pudo abrir el dispositivo de audio
		 4: No pudo leer el dispositivo de audio
		 5: No pudo escribir en el archivo a grabar
*/

int main(int argc, char ** argv)
{

	int dspfd;		/* sound device file descriptor */
	FILE * rawfd;   /* Archivo raw file descriptor */
	int status;		/* return status de system calls */

	audio_params config = {RATE, SIZE, CHANNELS};
	int buffsize;
	int salida = 0, i;
	int repro = 0;

	unsigned int cinta, i_cinta; 
 	unsigned char * buf = NULL;

	/* Controlamos los argumentos */
	if ((argc > 1) && (argc < 6))
	{
		for (i=1; i<argc; i++)
		{
			if((*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 'r'))
				config.v_muestreo = atoi((*(argv+i)+2));
			else if((*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 's'))
				config.t_muestra = atoi((*(argv+i)+2));
			else if((*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 'c'))
				config.c_canales = atoi((*(argv+i)+2));
			else if((*(*(argv+i)) == '-') && (*(*(argv+i)+1) == 'n'))
				repro = i;
			else salida = 1; 
		}

		/* bufer para el audio */
		buffsize = MSEG*config.v_muestreo*config.t_muestra*config.c_canales/BITS/MILI;
	 	buf = (unsigned char *) malloc(buffsize);
	}
	else
	{
		salida = 1;
	}

	if ((!repro) || (salida))
	{
		printf ("Argumentos erroneos\nUso: %s -n[filename] <-rRATE> <-sSIZE> <-cCHANNELS>\n",argv[0]);
		salida = 1;
	}

	if(!salida)
	{
		/* Creamos el archivo de audio. Si no existe lo creamos. Y si existe lo truncamos */
		if (!(rawfd = fopen(argv[repro]+2, "w")))
		{
		  	fprintf(stderr,"Error en función open\n"); 
			salida = 2;
		}
	}

	if (!salida)
	{
		/* Abrimos el dispositivo de audio */
		if ((dspfd = open("/dev/dsp", O_RDWR))<0)
		{ 
			fprintf(stderr,"Error en función open, Código de error: %s\n",strerror (dspfd)); 
			salida = 3;
		}
	}


	if (!salida)
	{
		/* Seteamos parámetros de audio */
		set_audio_params (dspfd, &config);

		i_cinta = time(NULL);
		printf("\033[2J\n");

		while (!salida)
		{ /* Si no hay error en la lectura o grabación se termina con Control-C */

			/* La siguiente función bloquea al proceso hasta que se llene el buffer. Esto con archivos comunes 
			no se nota, pero con un dispositivo de audio en donde se leen 8000 muestras por segundo..... */

			status = read(dspfd, buf, buffsize); /* lee */

			if (status != buffsize)
			{
				fprintf(stderr,"Error en función read, Código de error: %s\n",strerror (status));
				salida = 4;
			}

			if (!salida)
			{
				cinta = time(NULL);
		 		printf("\033[1;1HGrabando: \033[33m%s\n\t\t\033[0m(%02d:%02d)\n", argv[repro]+2, (cinta-i_cinta)/60, (cinta-i_cinta)%60);
		 		printf("Frec: %d\t Tam: %d\tCan: %d\n", config.v_muestreo, config.t_muestra, config.c_canales);

				/* Write generalmente no bloquea hasta que termina. Sino que envía la información presente en 
				el buffer al kernel. Por eso luego de enviar, vamos a sincronizar con ioctl ()*/

				status = fwrite(buf,1 ,buffsize, rawfd); /* reproduce */
				if (status != buffsize)
				{
					fprintf(stderr,"Error en función write, Código de error: %s\n",strerror (status)); 
					salida = 5;
				}
			}
		}
	}

	if (salida > 2) fclose(rawfd);
	if (salida > 3) close(dspfd);

	if (buf) free (buf);
	return salida;
}
