#ifndef ARCHIVOACCESO_H_INCLUDED
#define ARCHIVOACCESO_H_INCLUDED

#include <iostream>
#include <cstring>
#include "acceso.h"

class ArchivoAcceso{
private:
    std::string _nombreArchivo = "lista de accesos.dat";
public:
    ArchivoAcceso(std::string nombreArchivo);
    ArchivoAcceso();

    bool guardarAcceso(Acceso reg); ///escritura
    int getCantidadRegistros();
    bool leerMuchos(Acceso reg[], int cantidad); ///lectura archivos
    Acceso Leer(int posicion); ///lectura
    int getNewID();
    bool validarID(int idBuscado, Acceso &resultado);
    int buscarAccesoPorCancion(std::string cancion, Acceso &resultado);
    int buscarAccesoPorArtista(std::string artista, Acceso &resultado);
    bool guardarAcceso(Acceso reg, int posicion); ///sobreescritura
};

#endif // ARCHIVOACCESO_H_INCLUDED
