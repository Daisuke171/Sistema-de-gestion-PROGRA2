#ifndef ARCHIVOSCANCION_H_INCLUDED
#define ARCHIVOSCANCION_H_INCLUDED

#include "cancion.h"

class ArchivoCancion{
private:
    std::string _nombre_archivo = "lista de canciones.dat";
public:
    bool guardarCancion(Cancion reg);
    int getCantidadRegistros();
    bool leerMuchos(Cancion reg[], int cantidad);
    int getNewID();
};

#endif // ARCHIVOSCANCION_H_INCLUDED
