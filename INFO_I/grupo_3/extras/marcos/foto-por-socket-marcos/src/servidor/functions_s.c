#include "../../inc/functions.h"

void send_image(int cliente)
{
	char buffer[MAXBUFFER];
	FILE* fp;
	int i = 1;

	fp = fopen("lenna.png", "r");
	if (fp != NULL)
	{	
		while (!feof(fp))
		{
			fread(buffer, sizeof(char), MAXBUFFER, fp);
			send(cliente, buffer, MAXBUFFER, 0);
		}
		send(cliente, "FIN", sizeof("FIN"), 0);
		printf("Imagen enviada\n");
		fclose(fp);
	}
	else
	{
		HIGHLIGHT
		SET_RED
		printf("Error al cargar imagen");
		DEFAULT
	}
}