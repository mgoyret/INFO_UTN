#include <iostream>
#include "producto.h"
#include "productoenstock.h"

using namespace std;

void clean(void);

void clean(void)
{
    int ch;
    while ((ch = fgetc(stdin)) != EOF)
    {
      if( ch == '\n' ) break;
    }
}

int main()
{
    char* name=new char[15];
///*
    cout << "nombre: ";;
    cin>>name;
    clean();

    Producto a(name, 123);
    cout << "1. " << a;
    Producto b(a);
    cout << "2. " << b;

    cout << "nombre: ";;
    cin>>name;
    clean();
    a.Set_Nombre(name);
    cout << "3. " << a;

    cout << "nombre: ";
    cin>>name;
    clean();
    a.Set_Datos(name, 12);
    cout << "4. " << a;

    cout << "PRESS KEY" << endl;
    cin.get();
    clean();
//*/
    cout << "nombre: ";
    cin>>name;
    clean();
    PRODUCTOenSTOCK p, q(name, 15, 1, name, 2, 2, 11);
    cout << "5. " << p;
    cout << "6. " << q;

    PRODUCTOenSTOCK r(q);
    cout << "7. " << q;
    p.Set_Datos(name, 199, 4, name, 11, 10, 1999);
    cout << "8. " << p;
    p++; p++;
    cout << "9. " << p;
    p--; p--; p--; p--; p--; p--; p--;
    cout << "10. " << p;

    cout << "PARA FINALIZAR PRESIONE UNA TECLA" << endl;
    cin.get();

    return 0;
}
