/**
 * \file            functions.c
 * \brief           Funciones - Archivos Header - Función definida por el usuario
 * \author          Marcos Goyret, Felipe Galli, Matias.
 * \date            Ago 02, 2019
 * \details         Usar bash script para compilar, linkear y ejecutar
 */

#include "../inc/funciones.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////

int ingresar (Datos clienteIngresado,int clientSocketFd)
{
    char usuario[ARRA], contra[ARRA];
    Datos *cliente;
    FILE *fp;
    int j = 0, distintos = EXITO, ubicacion = 0, status = ERROR;
    #ifndef ALGO
        char DBGMSG[DBG];
    #endif
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

        strcpy(usuario,clienteIngresado.usuario);
        strcpy(contra,clienteIngresado.contra);

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

            //printf("Contra %s -- %s \n Largos %ld -- %ld\n",cliente[ubicacion].contra,contra,strlen(cliente[ubicacion].contra), strlen(contra));
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
                printf("Contraseña* y/o usuario incorrectos\n");
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
        	printf("Contraseña y/o usuario* incorrectos\n"); 
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
/*  Definicion de la funcion "registrarse" */

/**
 * \fn      int registrarse (Datos nuevocliente,int clientSocketFd)
 * \brief   Registra los usuarios ingresados
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Nov 14, 2019
 * \param	Datos nuevocliente: estrcutura donde se guarda los datos de los usuarios nuevos
 *      		
 */
int registrarse (Datos nuevocliente,int clientSocketFd)
{
    Datos *cliente;
    FILE *fp;
    char  usuario[ARRA],contra[ARRA];
    int cantuser=0,distintos,status=ERROR;  
    #ifndef ALGO
        char DBGMSG[DBG];
    #endif

    strcpy(usuario,nuevocliente.usuario);
    strcpy(contra,nuevocliente.contra);

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
        /* Indiferente si el usuario es escrito en mayusculas o minusculas y reviso si existe el usuario */
        usuario_existe(cliente,cantuser,usuario,&distintos);
        /* Si el usuario no existe lo cargo */
        if (distintos==EXITO)
        {
            status=EXITO;            
            #ifndef ALGO
                sprintf(DBGMSG,"Comprobando que haya usuarios ingresados\n");
                log_msg(INFO,__FILE__,__LINE__,DBGMSG);
            #endif

            if(cantuser>0)
            {
                cliente[cantuser].tiempo=time(NULL);
                printf("%ld\n",cliente[cantuser].tiempo);
                
                #ifndef ALGO
                    sprintf(DBGMSG,"Hay usuarios ingresados\n");
                    log_msg(INFO,__FILE__,__LINE__,DBGMSG);
                #endif   
                cliente=(Datos*)realloc(cliente,(cantuser+1)*sizeof(Datos));   
                if ((cliente[cantuser].tiempo>0) && (strlen(usuario)>0) && (strlen(contra)>0))
                {
                    printf("Cargando cliente en archivo:\nTiempo: '%ld'\nUsuario: '%s'\nClave: '%s'\n\n", cliente[cantuser].tiempo,usuario,contra);
                    fprintf(fp,"\n%ld,%s,%s",cliente[cantuser].tiempo,usuario,contra);
                }
                
            //    send(clientSocketFd,"Usuario registrado exitosamente\n",41,0);
                BLANCO
            }
            else
            {
                cliente[cantuser].tiempo=time(NULL);
                //printf("%ld\n",cliente[cantuser].tiempo);
                cliente=(Datos*)malloc(sizeof(Datos));
                if ((strlen(usuario)>0) && (strlen(contra)>0))
                {
                    printf("Cargando cliente en archivo:\nTiempo: '%ld'\nUsuario: '%s'\nClave: '%s'\n\n", cliente[cantuser].tiempo,usuario,contra);
                    fprintf(fp,"%ld,%s,%s",cliente[cantuser].tiempo, usuario, contra);
                }
            //    send(clientSocketFd,"Usuario registrado exitosamente\n",33,0);
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

/*  Definicion de la funcion "eliminar" */

/**
 * \fn      int eliminar(Datos eliminarcliente,int clientSocketFd)
 * \brief   Elimina el usuario utilizado
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Nov 14, 2019
 * \param	Datos eliminarcliente: estrcutura donde se guarda los datos el usuario  ingresado
 *      		
 */
int eliminar(Datos eliminarcliente,int clientSocketFd)
{
    char usuario[ARRA],contra[ARRA];
    int nrouser=0,distinto=EXITO,ubicacion=0,i=0,status=ERROR;
    Datos *cliente,*respaldo;
    FILE *fp;
    #ifndef ALGO
        char DBGMSG[DBG];
    #endif
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

            strcpy(usuario,eliminarcliente.usuario);
            strcpy(contra,eliminarcliente.contra);
            
            
            /* Notamos que en ocaciones en el archivo .csv se agregaba al final del string de la clave, un caracter
            "DEL", (ASCII = 127), por lo que, si fue anadido, es borrado */
            if (cliente[ubicacion].contra[(strlen(cliente[ubicacion].contra)-1)]==127)
            {
                cliente[ubicacion].contra[(strlen(cliente[ubicacion].contra)-1)]='\0';
            }


            ubicacion = usuario_existe(cliente, nrouser, usuario, &distinto);
            if (distinto == ERROR)
            {
                respaldo = (Datos*)malloc((nrouser-1)*sizeof(Datos));
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
                    printf("Ubicacion= %d de %d\n",ubicacion,nrouser);
                    for ( i = 0; i < ubicacion; i++)
                    {
                        printf("Posicion %d\n",i);
                        if(i != ubicacion)
                        {
                            printf("paso Posicion %d\n",i);
                            respaldo[i]=cliente[i];
                        }
                    }
                    printf("salteamos el valor %d\n",i);
                    for ( i = ubicacion; i < nrouser; i++)
                    {
                        printf("Posicion %d\n",i+1);
                        printf("paso\n");
                        respaldo[i]=cliente[i+1];
                    }
                    status = EXITO;
                }
              	else
                {
                    ROJO
                    printf("Contraseña y/o usuario incorrectos\n");
                    BLANCO
                    #ifndef ALGO
                        sprintf(DBGMSG,"Contraseña incorrecta\n");
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
                    sprintf(DBGMSG,"Usuario incorrecto\n");
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

    if (status==EXITO)
    {
        cargar_archivo(respaldo, nrouser-1);
    }

    if(nrouser > 0)
    {
        free(cliente);
        free(respaldo);
    }

    return status;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  Definicion de la funcion "ver" */

/**
 * \fn      int ver()
 * \brief   Llama a la funcion Imprimir_arreglos y los muestra por pantalla
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Nov 14, 2019
 * \param	
 *      		
 */
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
/*  Definicion de la funcion "salir" */

/**
 * \fn      int salir()
 * \brief   Imprime adios al finalizar
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Nov 14, 2019
 * \param	
 *      		
 */
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

/*  Definicion de la funcion "cargar_archivo" */

/**
 * \fn      void cargar_archivo(Datos *cliente,int j)
 * \brief   Carga el archivo .csv con los datos de los usuarios
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Nov 14, 2019
 * \param	
 *      		
 */
void cargar_archivo(Datos *cliente,int j)
{
    int i;
    FILE *fp;
    #ifndef ALGO
        char DBGMSG[DBG];
    #endif
    #ifndef ALGO
        sprintf(DBGMSG,"Abriendo archivo\n");
        log_msg(INFO,__FILE__,__LINE__,DBGMSG);
    #endif 


    fp=fopen("clientes.csv", "w");
    
    #ifndef ALGO
        sprintf(DBGMSG,"Archivo abierto exitosamente\n");
        log_msg(INFO,__FILE__,__LINE__,DBGMSG);
    #endif 

    if(fp != NULL)
    {
        for (i = 0; i < j-1; i++)
        {
        //    if((strlen(cliente[i].usuario)>0) && (strlen(cliente[i].contra)>0))
        //    {
                fprintf(fp,"%ld,%s,%s\n",cliente[i].tiempo,cliente[i].usuario,cliente[i].contra);
                printf("Cargando cliente en archivo:\nTiempo: '%ld'\nUsuario: '%s'\nClave: '%s'\n\n", cliente[i].tiempo, cliente[i].usuario, cliente[i].contra);
        //    }       
        }
        //if((strlen(cliente[i].usuario)>0) && (strlen(cliente[i].contra)>0))
        //{
                printf("Cargando cliente en archivo:\nTiempo: '%ld'\nUsuario: '%s'\nClave: '%s'\n\n", cliente[i].tiempo, cliente[i].usuario, cliente[i].contra);
                fprintf(fp,"%ld,%s,%s",cliente[i].tiempo,cliente[i].usuario,cliente[i].contra);
        //}   

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
/*  Definicion de la funcion "ordenar" */

/**
 * \fn      void ordenar(Datos **cliente, int nro) 
 * \brief   Ordena los usuarios cargados
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Nov 14, 2019
 * \param	 **cliente: datos ingresados por el usuario, nro: numero de usuario
 *      		
 */

void ordenar(Datos **cliente, int nro) 
{
    int j = 0,k, estaOrdenado = 1;
    int ultimoDesordenado = nro -1;
    int res = 0;

    while (0 != estaOrdenado) 
    {
        estaOrdenado = 0;
        for (j = 0; j < ultimoDesordenado; j++) 
        {
            k=j+1;
        printf("\nusu1\nusuario: %s\nClave:%s\ntiempo: %ld\n",(*(*cliente+j)).usuario,(*(*cliente+j)).contra,(*(*cliente+j)).tiempo);
        printf("\nusu2\nnusuario: %s\nClave:%s\ntiempo: %ld\n",(*(*cliente+k)).usuario,(*(*cliente+k)).contra,(*(*cliente+k)).tiempo);
            res = (*(*cliente+j)).tiempo- (*(*cliente+k)).tiempo;
            if (res < 0)
            {
                swap((*cliente+j),(*cliente+k));
            }
            estaOrdenado = 1;
        }
        ultimoDesordenado--;
    }
}
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  Definicion de la funcion "usuario_existe" */

/**
 * \fn      int usuario_existe(Datos *cliente,int largo,char *usuario,int *distintos)
 * \brief   Comprueba que el usuario exista
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Nov 14, 2019
 * \param	 *cliente: datos del cliente ingresados en la estructura 
 *      	 int largo: largo del    	
 */
int usuario_existe(Datos *cliente,int largo,char *usuario,int *distintos)
{
    int i=0,j=0;
    char respaldo_usuario[ARRA],respaldo_datos[ARRA];
    #ifndef ALGO
        char DBGMSG[DBG];
    #endif
    
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
        //printf("es: %d \nlargo: %ld - %ld \npalabras : %s %s\n",strcmp(respaldo_datos, respaldo_usuario),strlen(respaldo_datos),strlen(respaldo_usuario),respaldo_datos,respaldo_usuario);
        if (strcmp(respaldo_datos, respaldo_usuario) == 0)
        {            
            *distintos = ERROR;
            break;
        }
    }
    return i;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  Definicion de la funcion "Imprimir_Arreglo" */

/**
 * \fn      void Imprimir_Arreglo(Datos *p,int largo)
 * \brief   Imprime los datos ingresados por el cliente
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Nov 14, 2019
 * \param	 *cliente: datos del cliente ingresados en la estructura 
 *      	 int largo: largo del    	
 */
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
/*  Definicion de la funcion "cargar_usuario" */

/**
 * \fn      int cargar_usuario(FILE *fp,Datos **clientes)
 * \brief   Carga los clientes ingresados en la estructura Datos
 * \author  Marcos Goyret, Felipe Galli, Matias Schvartzman
 * \date    Nov 14, 2019
 * \param	
 *      	    	
 */
int cargar_usuario(FILE *fp,Datos **clientes)
{
    char *token,texto[TAM];
    int j = 0;
    long int tokaux;
    #ifndef ALGO
        char DBGMSG[DBG];
    #endif
    if(fp!=NULL)
    {
        #ifndef ALGO
            sprintf(DBGMSG,"Leyendo archivo\n");
            log_msg(INFO,__FILE__,__LINE__,DBGMSG);
        #endif
        
                fgets(texto, TAM, fp);
                printf("TEXTO: '%s'\n", texto);       
        
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
                printf("token = %s   tokenint = %ld \n",token,tokaux);
                (*(*clientes+j)).tiempo = tokaux;//Realice un casteo		
                token = strtok(NULL, ",""\n");

                if(token != NULL)
                {
                    printf("USER: '%s'\n", token);
                    strcpy((*(*clientes+j)).usuario, token);
                    token = strtok(NULL, ",""\n");
                    if(token != NULL)
                    {
                        printf("CLAVE: '%s'\n", token);
                        strcpy((*(*clientes+j)).contra, token);
                        
                        //printf("descagando palabra %s de largo %ld\n",token,strlen(token));	
                        
                            fgets(texto, TAM, fp);
                            printf("TEXTO: '%s'\n", texto);				
                            token = strtok(texto, ",");                     
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

void swap(Datos *user1, Datos *user2)
{
    RESALTAR
    printf("ENTRO FUNCION SWAP\n");
    BLANCO
    Datos aux;
    printf("\nusu1\nusuario: %s\nClave:%s\ntiempo: %ld\n",(*user1).usuario,((*user1)).contra,((*user1)).tiempo);
    printf("\nusu2\nnusuario: %s\nClave:%s\ntiempo: %ld\n",(*user2).usuario,((*user2)).contra,((*user2)).tiempo);
    printf("\nInicio swap\n");
    aux = *user1;
    printf("Parte1\n");
    *user1 = *user2;
    printf("Parte2\n");
    *user2 = aux;
    printf("Parte3\n");
    printf("\nusu1\nusuario: %s\nClave:%s\ntiempo: %ld\n",(*user1).usuario,((*user1)).contra,((*user1)).tiempo);
    printf("\nusu2\nnusuario: %s\nClave:%s\ntiempo: %ld\n",(*user2).usuario,((*user2)).contra,((*user2)).tiempo);
    
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
    fprintf(fp, "%ld\t||\t%s\t||\t%s\t||\t%d\t||\t%s\n\t", tiempo,log_n, archivo,linea,mensaje);

    fclose(fp);
}