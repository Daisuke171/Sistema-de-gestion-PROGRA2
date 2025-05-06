#ifndef ARCHIVOACCESO_H_INCLUDED
#define ARCHIVOACCESO_H_INCLUDED

#include "acceso.h"

class ArchivoAcceso{
private:
    std::string _nombre_archivo = "lista de accesos.dat";
public:
    bool guardarAcceso(Acceso reg);
    int getCantidadRegistros();
    bool leerMuchos(Acceso reg[], int cantidad);
};

#endif // ARCHIVOACCESO_H_INCLUDED
