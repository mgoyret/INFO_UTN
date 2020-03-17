#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sockets
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>

//opencv
#include </usr/include/opencv/cv.h>
#include </usr/include/opencv/highgui.h>

#define MAXCONEXIONES 	10
#define MAXBUFFER		10000
#define HOST_IP			"127.0.0.1"
#define TEMP_IMG	"temp_img"

#define SEPARATOR   printf("//////////////////////////////////////////////////////////////////////////////\n");
#define SPACE       printf("\n\n");
#define DEFAULT     printf("\033[00m");
#define SET_RED     printf("\033[31m");
#define SET_GREEN   printf("\033[32m");
#define HIGHLIGHT   printf("\033[07m");

void send_image(int cliente);

void show_image(char* img_name);

#endif