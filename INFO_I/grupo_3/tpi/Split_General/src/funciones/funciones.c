/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret, Felipe Galli, Matias.
 * \date            Ago 02, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */


 //mostrar_directorios("media");

#include"funciones.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////

int ingresar ()
{
    char usuario[ARRA], contra[ARRA];
    char DBGMSG[DBG];
    Datos *cliente;
    FILE *fp;
    int j = 0, distintos = EXITO,ubicacion=0,status=ERROR;
        #ifndef ALGO
            sprintf(DBGMSG,"\tAbriendo archivo\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif
    fp=fopen("clientes.csv","a+");
    if (fp!=NULL)
    {
        #ifndef ALGO
            sprintf(DBGMSG,"Archivo abierto exitosamente\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif
        printf("Nombre de usuario:");
        scanf("%s", usuario);
        printf("Contraseña:");
        INVISIBLE
        scanf("%s", contra);
        BLANCO

        /* J = Cantidad de usuarios existentes */
        j = cargar_usuario(fp,&cliente);
        ubicacion=usuario_existe(cliente,j,usuario,&distintos);
        if (distintos==ERROR)
        { 
        #ifndef ALGO
            sprintf(DBGMSG,"Se ingreso un usuario nuevo\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif
        /* Notamos que en ocaciones en el archivo .csv se agregaba al final del string de la clave, un caracter
            "DEL", (ASCII = 127), por lo que, si fue anadido, es borrado */
        if (cliente[ubicacion].contra[(strlen(cliente[ubicacion].contra)-1)]==127)
        {
            cliente[ubicacion].contra[(strlen(cliente[ubicacion].contra)-1)]='\0';
        }
        
            if(strcmp(cliente[ubicacion].contra,contra)==0)
            {
                VERDE
                printf("Bienvenido %s\n",cliente[ubicacion].usuario);
                BLANCO
                ESPACIO
                cliente[ubicacion].tiempo=time(NULL);
            }
          	else
            {
                distintos=EXITO;
                ROJO
                printf("Contraseña y/o usuario incorrectos\n");
                BLANCO
        #ifndef ALGO
            sprintf(DBGMSG,"Contraseña y/o usuario incorrectos\n");
            log_msg(error,__FILE__,__LINE__,DBGMSG);
        #endif  
            } 
        }
      	else
        {
            distintos=EXITO;
            ROJO
        	printf("Contraseña y/o usuario incorrectos\n"); 
            BLANCO
        #ifndef ALGO
             sprintf(DBGMSG,"Contraseña y/o usuario incorrectos\n");
            log_msg(error,__FILE__,__LINE__,DBGMSG);
        #endif
        }
    }
        #ifndef ALGO
            sprintf(DBGMSG,"Cerrando el archivo");
            log_msg(DEBUG,__FILE__,__LINE__,DBGMSG);
        #endif
fclose(fp);
        #ifndef ALGO
            sprintf(DBGMSG,"Archivo cerrado correctamente\n");
            log_msg(DEBUG,__FILE__,__LINE__,DBGMSG);
        #endif
    
    if(distintos==ERROR)
    {
        #ifndef ALGO
            sprintf(DBGMSG,"El usuario ingresado es existente");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif

        ordenar(&cliente,j);
        cargar_archivo(cliente,j);
        status=EXITO;
    }
if(j>0)
{
    free(cliente);
}
return status;
} 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int registrarse ()
{
    Datos *cliente;
    FILE *fp;
    char  usuario[ARRA],contra[ARRA];
    int cantuser=0,distintos,status=ERROR;  
    char DBGMSG[DBG];  

    #ifndef ALGO
        sprintf(DBGMSG,"Abriendo el archivo\n");
        log_msg(INFO,__FILE__,__LINE__,DBGMSG);
    #endif

    fp = fopen("clientes.csv","a+");

    if(fp != NULL)
    {
        #ifndef ALGO
            sprintf(DBGMSG,"Archivo '.csv' abierto/creado exitosamente \n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif

        cantuser=cargar_usuario(fp,&cliente);
        #ifndef ALGO
            sprintf(DBGMSG,"Imprimiendo usuarios\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif
     /* #ifndef ALGO
            sprintf(DBGMSG,"Se imprimio correctamente\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif */
        if(cantuser==0)
        {
            cliente=(Datos*)malloc(sizeof(Datos));
        }
        else
        {
            cliente=(Datos*)realloc(cliente,(cantuser+1)*sizeof(Datos));
        }
        printf("Nombre de usuario:  ");
        scanf("%s", usuario);
        printf("Ingrese contraseña:  ");
        INVISIBLE
        scanf("%s",contra);
        BLANCO
        #ifndef ALGO
            sprintf(DBGMSG,"Imprimiendo usuarios\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif
            
            
        /* Indiferente si el usuario es escrito en mayusculas o minusculas y reviso si existe el usuario */
        usuario_existe(cliente,cantuser,usuario,&distintos);
        /* Si el usuario no existe lo cargo */
        if (distintos==EXITO)
        {
            cliente[cantuser].tiempo=time(NULL);
            status=EXITO;            
            #ifndef ALGO
                sprintf(DBGMSG,"Comprobando que haya usuarios ingresados\n");
                log_msg(INFO,__FILE__,__LINE__,DBGMSG);
            #endif
            if(cantuser>0)
            {
                #ifndef ALGO
                    sprintf(DBGMSG,"Hay usuarios ingresados\n");
                    log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                #endif   

                fprintf(fp,"\n%ld,%s,%s",cliente[cantuser].tiempo,usuario,contra);
                VERDE
                printf("Usuario registrado exitosamente\n");
                BLANCO
            }
            else
            {
                fprintf(fp,"%ld,%s,%s",cliente[cantuser].tiempo,usuario,contra);
                VERDE
                printf("Usuario registrado exitosamente\n");
                BLANCO
            }               
        }
        else
        {
            ROJO
            printf("Ususario en uso\n");
            BLANCO
        }   
        #ifndef ALGO
            sprintf(DBGMSG,"Cerrando el archivo");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif
        /* El fclose va dentro del "if(fp != NULL)" ya que si fp es null, no hay ningun archivo a cerrar. Solo lo hay si fp != NULL */
        fclose(fp);
        
        #ifndef ALGO
            sprintf(DBGMSG,"Archivo cerrado correctamente\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif
    }
    else
    {
        ROJO
        printf("Archivo lleno.\n");
        BLANCO

        #ifndef ALGO
            sprintf(DBGMSG,"Maximo numero de usuarios ingresados\n");
            log_msg(error,__FILE__,__LINE__,DBGMSG);
        #endif
    }       

    if(cantuser > 0)
    {
        free(cliente);
    }
    return status;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int eliminar()
{
    char usuario[ARRA],contra[ARRA];
    int nrouser=0,distinto=EXITO,ubicacion=0,i=0,status=ERROR;
    Datos *cliente,*respaldo;
    FILE *fp;
    char DBGMSG[DBG];

    #ifndef ALGO
         sprintf(DBGMSG,"Abriendo archivo\n");
         log_msg(INFO, __FILE__, __LINE__, DBGMSG);
    #endif 
    fp=fopen("clientes.csv", "a+");
        
    if(fp!=NULL)
    {
        #ifndef ALGO
            sprintf(DBGMSG, "Archivo abierto correctamente\n");
            log_msg(INFO, __FILE__, __LINE__, DBGMSG);
        #endif
        #ifndef ALGO
            sprintf(DBGMSG,"Recorriendo el archivo");
            log_msg(DEBUG, __FILE__, __LINE__, DBGMSG);
        #endif

        nrouser = cargar_usuario(fp, &cliente);

        #ifndef ALGO
            sprintf(DBGMSG,"Comprobando que se haya ingresado algun usuario\n");
            log_msg(DEBUG,__FILE__,__LINE__,DBGMSG);
        #endif

        if(nrouser > 0)
        {
            #ifndef ALGO
                sprintf(DBGMSG,"Comprobacion exitosa\n");
                log_msg(DEBUG,__FILE__,__LINE__,DBGMSG);
            #endif
            printf("Nombre de usuario:  ");
            scanf("%s", usuario);
            printf("Ingrese contraseña:  ");
            INVISIBLE
            scanf("%s", contra);
            BLANCO

            ubicacion = usuario_existe(cliente, TAM, usuario, &distinto);
            if (distinto == ERROR)
            {
                respaldo = (Datos*)malloc(nrouser*sizeof(Datos));
                if (respaldo == NULL)
                {
                    ESPACIO
                    ROJO
                    printf("Error al cargar la memoria");
                    BLANCO
                    ESPACIO
                }
                else if(strcmp(cliente[ubicacion].contra,contra) == 0)
                {
                    for ( i = 0; i < nrouser; i++)
                    {
                        if(i != ubicacion)
                        {
                            respaldo[i]=cliente[i];
                        }
                        else
                        {
                            i++;
                        }   
                    }
                    status = EXITO;
                    cargar_archivo(respaldo, nrouser-1);
                }
              	else
                {
                    ROJO
                    printf("Contraseña y/o usuario incorrectos\n");
                    BLANCO
                    #ifndef ALGO
                        sprintf(DBGMSG,"Contraseña y/o usuario incorrectos\n");
                        log_msg(error,__FILE__,__LINE__,DBGMSG);
                    #endif
                }
            }
            else
            {
                ROJO
                printf("Contraseña y/o usuario incorrectos\n");
                BLANCO
                #ifndef ALGO
                    sprintf(DBGMSG,"Contraseña y/o usuario incorrectos\n");
                    log_msg(error,__FILE__,__LINE__,DBGMSG);
                #endif
            }
        }
        #ifndef ALGO
            sprintf(DBGMSG,"Cerrando el archivo");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif
        fclose(fp);
        #ifndef ALGO
            sprintf(DBGMSG,"Archivo cerrado correctamente\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif
    }

    if(nrouser > 0)
    {
        free(cliente);
        free(respaldo);
    }
    return status;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ver()
{
    Datos *cliente;
    FILE *fp;
    int nrouser, salida = ERROR;

    fp = fopen("clientes.csv", "r");
    if (fp != NULL)
    {
        nrouser = cargar_usuario(fp, &cliente);
        if (nrouser > 0)
        {
            Imprimir_Arreglo(cliente, nrouser);
            salida = EXITO;
        }
        else
        {
            ROJO
            printf("\nNo se encontraron usuarios\n\n");
            BLANCO
        }
        
        
    }
    else
    {
        ROJO
        printf("\nERROR AL ABRIR ARCHIVO\n\n");
        BLANCO
    }
    return salida;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int salir()
{
    ESPACIO
    RESALTAR
    printf("Adios!");
    BLANCO
    ESPACIO
    return EXITO;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cargar_archivo(Datos *cliente,int j)
{
    int i;
    FILE *fp;
    char DBGMSG[DBG];

    #ifndef ALGO
        sprintf(DBGMSG,"Abriendo archivo\n");
        log_msg(INFO,__FILE__,__LINE__,DBGMSG);
    #endif 
    fp=fopen("clientes.csv", "w+");
    #ifndef ALGO
        sprintf(DBGMSG,"Archivo abierto exitosamente\n");
        log_msg(INFO,__FILE__,__LINE__,DBGMSG);
    #endif 

    if(fp != NULL)
    {
        for (i = 0; i < j; i++)
        {
            fprintf(fp,"%ld,%s,%s\n",cliente[i].tiempo,cliente[i].usuario,cliente[i].contra);
        }
        #ifndef ALGO
            sprintf(DBGMSG,"Cerrando archivo\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif 
        fclose(fp);
        #ifndef ALGO
            sprintf(DBGMSG,"Archivo cerrado\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif 
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ordenar(Datos **cliente, int nro) 
{
    int j = 0, estaOrdenado = 1;
    int ultimoDesordenado = nro -1;
    int res = 0;

    while (0 != estaOrdenado) 
    {
        estaOrdenado = 0;
        for (j = 0; j < ultimoDesordenado; j++) 
        {
            res = (*(*cliente+j)).tiempo- (*(*cliente+(j+1))).tiempo;
            if (res < 0)
            {
                swap((cliente+j),(cliente+(j+1)));
            }
            estaOrdenado = 1;
        }
        ultimoDesordenado--;
    }
}
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int usuario_existe(Datos *cliente,int largo,char *usuario,int *distintos)
{
    int i=0,j=0;
    char respaldo_usuario[ARRA],respaldo_datos[ARRA];
    char DBGMSG[DBG];
    *distintos=EXITO;
    for(i=0;i<largo;i++)
    {   
        #ifndef ALGO
            sprintf(DBGMSG,"Recorriendo los usuarios\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif 
        for (j = 0; j < ARRA; j++)
        {
            #ifndef ALGO
                sprintf(DBGMSG,"Recorriendo las letras de cada usuario\n");
                log_msg(INFO,__FILE__,__LINE__,DBGMSG);
            #endif
            #ifndef ALGO
                sprintf(DBGMSG,"Pasando a minuscula\n");
                log_msg(INFO,__FILE__,__LINE__,DBGMSG);
            #endif              
            respaldo_datos[j] = tolower(cliente[i].usuario[j]);
            respaldo_usuario[j] = tolower(usuario[j]);
            #ifndef ALGO
                sprintf(DBGMSG,"Pase correcto\n");
                log_msg(INFO,__FILE__,__LINE__,DBGMSG);
            #endif    
        }
        if (strcmp(respaldo_datos, respaldo_usuario) == 0)
        {            
            *distintos = ERROR;
            break;
        }
    }
    return i;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Imprimir_Arreglo(Datos *p,int largo)
{
    int i;
    for(i=0; i<largo; i++)
    {
        printf("--------------&--------------\n");
        printf("\nusuario %d:\n %ld\n",i+1,p[i].tiempo);
        printf("Ususario: %s -",p[i].usuario);
        printf("Contraseña %s\n\n",p[i].contra);
        printf("--------------&--------------\n");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int cargar_usuario(FILE *fp,Datos **clientes)
{
    char *token,texto[TAM];
    int j = 0;
    long int tokaux;
    char DBGMSG[DBG];

    if(fp!=NULL)
    {
        #ifndef ALGO
            sprintf(DBGMSG,"Leyendo archivo\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif       
        fread(texto,sizeof(char),TAM,fp);
        #ifndef ALGO
            sprintf(DBGMSG,"Archivo leido exitosamente\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif

        token = strtok(texto, ",");
        if (token != NULL)
        {   
            *clientes = (Datos*)malloc(sizeof(Datos));
        
            #ifndef ALGO
                sprintf(DBGMSG,"Recorriendo archivo\n");
                log_msg(INFO,__FILE__,__LINE__,DBGMSG);
            #endif    
            while (token!=NULL && *clientes!=NULL)
            {
                #ifndef ALGO
                    sprintf(DBGMSG,"Recorrido exitoso\n");
                    log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                #endif        

                tokaux = atoi(token);
                (*(*clientes+j)).tiempo = tokaux;//Realice un casteo		
                token = strtok(NULL, ",""\n");

                if(token != NULL)
                {
                    strcpy((*(*clientes+j)).usuario, token);
                    token = strtok(NULL, ",""\n");

                    if(token != NULL)
                    {
                        strcpy((*(*clientes+j)).contra, token);					
                        token = strtok(NULL, ",""\n");                     
                        //tokaux=atoi(token);
                        j++;
                        if (token != NULL)
                        {
                            *clientes = (Datos*)realloc(*clientes,(j+1)*sizeof(Datos));
                        }
                    }
                }
            }
        }
        else
        {
            ROJO
            printf("\nArchivo vacio\n");
            BLANCO
            #ifndef ALGO
                sprintf(DBGMSG, "Archivo vacio\n");
                log_msg(FATAL, __FILE__, __LINE__, DBGMSG);
            #endif
        }
        
    }
    return j;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void swap(Datos **user1, Datos **user2)
{
    Datos aux;

    aux = **user1;
    **user1 = **user2;
    **user2 = aux;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Esta funcion sirve como seguimiento de un programa almacenando datos en un archivo separado para que no molesten*/
void log_msg(Nivel_Log nivel, const char* archivo, int linea, const char* mensaje)
{
    FILE *fp;
    time_t tiempo;
    char log_n[20] = {"Valor no valido"};
    
    tiempo = time(NULL);
    /* a+ indica que quiero leer, escribir, crear o usar el ya creado */
    fp = fopen("Datos_Log","a+");
    if(fp != NULL)
    {
        /* Depende el nivel que tome hay que completar el vector teniendo en cuenta 
            que DEBUG=! al char "DEBUG" y si se intenta imprimir imprime 1 */
        switch (nivel)
        {
            case DEBUG: 
                strcpy(log_n,"DEBUG");
                break;
            case INFO:
                strcpy(log_n,"INFO");
                break;
            case WARN:
                strcpy(log_n,"WARN");
                break;
            case error:
                strcpy(log_n,"ERROR");
                break;
            case FATAL:
                strcpy(log_n,"FATAL");
                break;
            default:
                /*Si no eligen ningun valor valido log_n quedara en "valor no valido"*/
                break;
        }
    }
    /*Imprimimos en el archivo fp y no en pantalla todos los datos en orden.*/
    fprintf(fp, "%ld || %s || %s || %d || %s\n\t", tiempo,log_n, archivo,linea,mensaje);

    fclose(fp);
}