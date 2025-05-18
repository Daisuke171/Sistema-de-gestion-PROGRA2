#ifndef ARCHIVOARTISTA_H_INCLUDED
#define ARCHIVOARTISTA_H_INCLUDED

#include <iostream>
#include <cstring>
#include "artista.h"

class ArchivoArtista{
private:
    std::string _nombreArchivo = "lista de artista.dat";
public:
    ArchivoArtista(std::string nombreArchivo);
    ArchivoArtista();

    bool guardarArtista(Artista reg); ///escritura
    int getCantidadRegistros();
    bool leerMuchos(Artista reg[], int cantidad); ///lectura archivos
    Artista Leer(int posicion); ///lectura
    int getNewID();
    bool validarID(int idBuscado, Artista &resultado);
    bool validarNombreArtista(std::string nombre, Artista &resultado);
    int buscarArtistaPorID(int idBuscado, Artista &resultado);
    bool guardarArtista(Artista reg, int posicion); ///sobreescritura
};

#endif // ARCHIVOARTISTA_H_INCLUDED
