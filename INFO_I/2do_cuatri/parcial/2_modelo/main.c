#include <stdio.h>
#include <string.h>

#define TAM 100

int main(int argc, char** argv)
{
    FILE *fp;
    char line[TAM], arg[30], aux[30];
    int i = 0;

    memset(arg, '\0', 30);
    memset(aux, '\0', 30);

    if (argc > 2)
    {
        //fp = fopen(argv[1], "r");
        //if (fp != NULL)
        //{
            if(argc == 3) //PALABRA
            {
                strcpy(arg, argv[2]);
                printf("Pusiste la palabra '%s'\n", argv[2]);
            }
            else if (argc > 3) //FRASE
            {
                strcpy(arg, argv[2]);

                printf("arg es '%s'\n", arg);
                for(i=0; i<(strlen(arg)-1); i++)
                {
                    arg[i] = arg[i+1];
                }
                arg[strlen(arg)-1] = ' ';

                printf("ahora arg es '%s'\n", arg);
                
                for(i=3; i<(argc-1); i++)
                {
                    strcat(arg, argv[i]);
                    strcat(arg, " ");
                }
                strcpy(aux, argv[argc-1]);
                aux[strlen(aux)-1] = '\0';
                strcat(arg, aux);

                printf("ARG TOTAL ES '%s'\n", arg);

            }
            
            //while (!feof(fp))
            //{
            //    fgets(line, TAM, fp);

            //}
            //printf("FIN DEL ARCHIVO\n");

            //fclose(fp);   
        //}
        //else
        //{
        //    printf("ERROR: fopen()\n");
        //}
    }
    else
    {
        printf("./<programa> <archivo> <palabra o \"frase\">\n");
    }

    return 0;
}