/**
	\file    funciones.h
	\brief   Prototipos de las funciones incluidas en funciones.c
	\author  Spataro, Hector hspataro@frba.utn.edu.ar
	\date    2019.08.30 
	\version 1.0.0
*/


#ifndef FUNCIONES_AU_H
	#define FUNCIONES_AU_H

	//--------------
	//-- Includes --
	//--------------

	#include <unistd.h>
	#include <fcntl.h>
	#include <sys/types.h>
	#include <sys/ioctl.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <time.h>

	#include <linux/soundcard.h>
	/* Veamos el encabezado /usr/include/linux/soundcard.h */

	//-------------
	//-- Defines --
	//-------------

	/* segundos de audio a grabar */
	#define MSEG 10
	/* sampling rate = velocidad de muestreo del audio a la entrada*/
	#define RATE 48000
	/* sample size = Tamaño de muestra. Típicamente 8 o 16 bits */
	#define SIZE 16
	/* 1 = mono 2 = stereo */
	#define CHANNELS 2
	/* bits por bytes*/
	#define BITS 8
	/* milisengundos por segundo */
	#define MILI 1000
	/*Calcula dinámicamente el tamaño del buffer de audio*/
	#define BUFFSIZE MSEG*RATE*SIZE*CHANNELS/BITS/MILI

	//------------
	//-- Struct --
	//------------

	//Estructura definida para los parámetros de reproducción.
	typedef struct
	{
		int v_muestreo;
		int t_muestra;
		int c_canales;

	} audio_params;


	//----------------
	//-- Prototipos --
	//----------------

	void set_audio_params (int fd, audio_params * valor);

#endif