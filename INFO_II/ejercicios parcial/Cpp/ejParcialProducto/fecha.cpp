#include "fecha.h"

ostream& operator<<(ostream& os, Fecha& f)
{
    os <<"FECHA: "<<f.dia<<"/"<<f.mes<<"/"<<f.anio<<endl;
    return os;
}
