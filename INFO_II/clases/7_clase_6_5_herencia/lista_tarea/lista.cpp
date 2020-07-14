#include "lista.h"

//constructor por defecto
lista::lista()
{
    cout << this << " - constructor por defecto clase lista" << endl;
}

//constructor parametrizado
lista::lista(int num): ColaPila(num)
{
    cout << this << " - constructor parametrizado clase lista" << endl;
}

//constructor de copia
lista::lista(const lista& orig): ColaPila(orig){}


lista::~lista()
{
    cout << this << " - destructor clase lista" << endl;
}

int lista::insertar(int num)
{
    int exit = -1;
    nodo *aux1, *aux2;

    if((h == nullptr) || (cantidad == 0)) // o si cantidad = 0
    {
        //es el primer dato, no importa si lo coloco delante o detras
        AgregarDelante(num);
    }
    //chequeo si debo agregarlo al final
    aux1 = h;
    while(aux1->sig != nullptr)
    {
        aux1 = aux1->sig;
    }

    if(aux1->valor < num)
    {
        exit = AgregarFinal(num);
    }
    else if (h->valor > num)
    {
        exit = AgregarDelante(num);
    }
    else if (cantidad > 1)
    {   
        //nesecitare aux2 si o si, por lo que si falla new() ya corto la funcion, total no funcionara
        if((aux2 = new nodo) != nullptr)
        {
            aux1 = h;
            while (aux1->valor < num)
            {
                if((aux1->sig)->valor > num)
                    break;
                aux1 = aux1->sig;
            }
            // el siguiente a aux1 tiene valor mas grande que num, debo agregar num seguido de aux1
            aux2->valor = num;
            aux2->sig = aux1->sig;
            aux1->sig = aux2;
            cantidad++;
            exit = aux2->valor;
        }
    }
/*///////////   VIEJO   //////////////
        if(((aux1 = new nodo) != nullptr) && ((aux2 = new nodo) != nullptr))
        {
            aux1 = h;
            while (aux1->valor < num)
            {
                if((aux1->sig)->valor > num)
                    break;
                aux1 = aux1->sig;
            }
            // el siguiente a aux1 tiene valor mas grande que num, debo agregar num seguido de aux1
            aux2->valor = num;
            aux2->sig = aux1->sig;
            aux1->sig = aux2;
            cantidad++;
            exit = aux2->valor;
        }
/////////////////////////////////////////
*/

    //retorna el valor agregado, o -1 en caso de error
    return exit;
}


int lista::Retirar(int num)
{
    nodo *aux1 = h, *aux2;
    int i, flag = 0, exit = -1;


    i = 0;
    aux1 = h;
    while(i < cantidad)
    {
        if(aux1->valor == num)
        {
            flag = 1;
            break;
        }
        aux1 = aux1->sig;
        i++;
    }
    if(flag)
    {
        if(h->valor == num)
        {
            exit = RetirarDelante();
        }
        else
        {
            //Retiro si es el del final//////////
            while(aux1->sig != nullptr)
            {
                aux1 = aux1->sig;
            }
            if(aux1->valor == num)
            {
                aux1 = h;
                while((aux1->sig)->sig != nullptr)
                {
                    aux1 = aux1->sig;
                }
                aux2 = aux1->sig;
                aux1->sig = nullptr;
                exit = aux2->valor;
                delete aux2;
                cantidad--;
            }
            /////////////////////////////////////
            else
            {
                aux1 = h;
                while((aux1->sig)->valor != num)
                {
                    aux1 = aux1->sig;
                }
                aux2 = aux1->sig;
                aux1->sig = aux2->sig;
                delete aux2;
                cantidad--;
                exit = num;
            }
        }
    }
    else
    {
        cout << "valor inexistente en lista" << endl;
    }

    return exit;
}
