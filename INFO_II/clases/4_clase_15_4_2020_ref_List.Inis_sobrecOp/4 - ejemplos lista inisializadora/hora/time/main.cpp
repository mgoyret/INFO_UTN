/*
    No hice verificaciones de ningun tipo, solo estaba probando usar las clases
*/

#include "functions.h"

int main()
{
    class time t1;
    int a, b, c;

    cout << "objeto time creado, mostrando:" << endl;
    t1.stdtime();
    t1.unitime();

    cout << "indique:" << endl;

    do
    {
        cout << "hora:\t";
        cin >> a;
    }while ((a < 0) && (a >= 24));
    t1.seth(a);

    do
    {
        cout << "minuto:\t";
        cin >> b;
    }while((b < 0) && (b >= 60));
    t1.setm(b);

    do
    {
        cout << "segundo:";
        cin >> c;
    }while((c < 0) && (c <= 60));
    t1.sets(c);

    cout << "mostrando hora: " << endl;
    t1.stdtime();
    t1.unitime();

    cout << "FIN MAIN" << endl;

    return 0;
}
