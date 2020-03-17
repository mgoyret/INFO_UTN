/*Realizar un m´odulo de manejo de arreglos est´aticos de estructuras, el cual al menos debe incorporar
funciones para poder agregar, remover e imprimir el contenido del arreglo. A partir de este sprint, toda
la informaci´on de los clientes se debe cargar en un arreglo est´atico al comenzar, y todas las operaciones
(buscar, agregar, eliminar, etc.) deber´an realizarse sobre el arreglo. Tener en cuenta que se debe
actualizar el archivo siempre que el arreglo sufra modificaciones, para mantener ambos sincronizados.
Se contemplar´a un m´aximo de 10 usuarios, donde se deber´a imprimir un mensaje de error si se quiere
registrar a un nuevo usuario luego de alcanzado el m´aximo.*/

#include"funciones.h"

int main()
{
    Datos clientes[CANT];
    int i=0,j=0;
    FILE *fp;
    char *token,texto[TAM];
    VERDE
    printf("Bienvenido!\n\n");
    BLANCO
    fp=fopen("archivo.csv","a+");
    if(fp!=NULL)
    {  
      fread(texto,sizeof(char),TAM,fp);
      token=strtok(texto,",");
      j=0;
      while (token!=NULL)
      {
          strcpy(clientes[j].usuario,token);
          printf("Usuario: %s\n",token);
          token=strtok(NULL,",""\n");
          strcpy(clientes[j].contra,token);	
          printf("Contra: %s\n",token);				
          token=strtok(NULL,",""\n");   
          j++;
      }
    }  
        printf("Ingrese el usuario:");
        scanf("%s",clientes[i].usuario);
        printf("Ingrese la contrasena: ");
        INVISIBLE 
        scanf("%s",clientes[i].contra); 
        BLANCO
    j++;
   Imprimir_Arreglo(clientes,CANT);
   if(j<CANT)
   { 
    printf("la cantidad de usuarios ingresados son: %d\n",j);
   }
   else
   {
       printf("Maximo numero de registros\n");
   }

return 0;
}

