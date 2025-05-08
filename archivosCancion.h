#ifndef ARCHIVOSCANCION_H_INCLUDED
#define ARCHIVOSCANCION_H_INCLUDED

#include "cancion.h"

class ArchivoCancion{
private:
    std::string _nombre_archivo = "lista de canciones.dat";
public:
    ArchivoCancion(std::string nombreArchivo);
    ArchivoCancion();

    bool guardarCancion(Cancion reg);
    int getCantidadRegistros();
    bool leerMuchos(Cancion reg[], int cantidad);
    int getNewID();
    bool buscarPorID(int idBuscado, Cancion &resultado);
};

#endif // ARCHIVOSCANCION_H_INCLUDED
