#include"funciones.h"

int usuario_existe(Datos *cliente,int largo,char *usuario)
{
    int i=0,j=0,distintos=EXITO;
    char respaldo_usuario[ARRA],respaldo_datos[ARRA];

    for(i=0;i<largo;i++)
    {
        for (j = 0; j < ARRA; j++)
        {
            respaldo_datos[j] = tolower(cliente[i].usuario[j]);
            respaldo_usuario[j] = tolower(usuario[j]);
        }
        if (strcmp(respaldo_datos,respaldo_usuario)==0)
        {            
            ROJO
            ESPACIO
            printf("Nombre de usuario existente\n");
            ESPACIO
            BLANCO
            distintos=ERROR;
            break;
        }
    }
return distintos;
}

void Imprimir_Arreglo(Datos *p,int largo)
{
    int i;
    for(i=0;i<largo;i++)
    {
        printf("\nvector[%d]=Ususario: %s\n",i,p[i].usuario);
        printf("vector[%d]=Contraseña %s\n\n",i,p[i].contra);
    }
}
//Carga los usuarios y contraseñas en una estructura tipo Dato, devuelve el numero de usuarios.
int cargar_usuario(FILE *fp,Datos *clientes)
{
    char *token,texto[TAM];
    int j=0;
    if(fp!=NULL)
    {

    fread(texto,sizeof(char),TAM,fp);

        token=strtok(texto,",");
        if (token!=NULL)
        {
            while (token!=NULL)
            {
                clientes[j].tiempo=((time_t*)(token));
                token=strtok(NULL,",""\n");
                if(token!=NULL)
                {
                    strcpy(clientes[j].usuario,token);
                    token=strtok(NULL,",""\n");
                    if(token!=NULL)
                    {
                        strcpy(clientes[j].contra,token);					
                        token=strtok(NULL,",""\n");
                        j++;
                    }
                }
            }
        }else
        {
            printf("Archivo vacio\n");
        }
        
    }
return j;
}



int registrarse ()
{
    Datos cliente[CANT];
    FILE *fp;
    char  respaldo_usuario[ARRA],usuario[ARRA], respaldo_datos[ARRA],contra[ARRA];
    int i = 0,j=0,cantuser=0,distintos;    

    fp = fopen("clientes.csv","a+");
    if(fp != NULL)
    {
        cantuser=cargar_usuario(fp,cliente);
        Imprimir_Arreglo(cliente,cantuser);
        if(cantuser<CANT)
        {
            printf("Nombre de usuario:  ");
            scanf("%s", usuario);
            printf("Ingrese contraseña:  ");
            INVISIBLE
            scanf("%s",contra);
            BLANCO

            // indiferente si el usuario es escrito en mayusculas o minusculas y reviso si existe el usuario
            distintos=usuario_existe(cliente,cantuser,usuario);
            //Si el usuario no existe lo cargo.
            if (distintos==EXITO)
            {
                cliente[cantuser].tiempo=time(NULL);
                if(cantuser>0)
                {
                    fprintf(fp,"\n%ld,%s,%s",cliente[cantuser].tiempo,usuario,contra);
                }else
                {
                    fprintf(fp,"%ld,%s,%s",cliente[cantuser].tiempo,usuario,contra);
                }
                
            }
        }else
        {
            printf("Archivo lleno.\n");
            distintos=ERROR;
        }
        
    }else
    {
        printf("Error al abrir el archivo");
        distintos=ERROR;
    }
    
fclose(fp);
return distintos;
}