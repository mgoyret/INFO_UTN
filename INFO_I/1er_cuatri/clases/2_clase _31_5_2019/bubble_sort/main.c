void bubble_sort(float* vector, unsigned int largo)
{
    int i, j, EstaOrdenado; //EstaOrdenado == variable flag
    float aux;

    for(i=0;i<(largo-1);i++)
    {
        EstaOrdenado = 1;

        for(j=0;j<(largo-1-i);j++)
        {
            if(vector[j]>vector[j+1])
            {
                aux  = vector[j+1];
                vector[j+1] = vector[j];
                vector[j] = aux;
                EstaOrdenado = 0;   //solo lo hace si tuvo que swappear alguna vez
            }
        }
        if(EstaOrdenado)   //0=falso, osea q si EstaOrdenado = 0, no entra.        
        {
            break;
        }
    }
    printf("vector ordenado  = {");
    for(i=0; i<(largo-1); i++)
    {
        printf("%.2f, ", vector[i]);
    }
    printf("%.2f}\n", vector[largo-1]);
}

/* USANDO WHILE  TERMINAR DE COPIAR
void bubble_sort(int *array, unsigned int largo)
{
    int i, j, EstaOrdenado, UltimoDesordenado;//EstaOrdenado == variable flag

    for(i=0;i<(largo-1);i++)
    {
        EstaOrdenado = 0;

        for(j=0;j<(largo-1-i);j++)
        {
            if(array[j]>array[j+1])
            {
            swap(&array[j], &array[j+1])
            EstaOrdenado = 0;   //solo lo hace si tuvo que swappear alguna vez
            }
        }
        if(EstaOrdenado) 0=falso, osea q si EstaOrdenado es 0, no entra.  
                        si usaba un while mas arriba, en vez de este if, era while(!EstaOrdenado) 
                                                                y tenia que declarar EstaOrdenado=0
        {
            break;
        }
    }
}
*/