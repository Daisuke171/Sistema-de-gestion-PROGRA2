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
    bool validarNombreArtista(std::string nombre, Artista &resultado);
    bool leerMuchos(Artista reg[], int cantidad); ///lectura archivos
    Artista Leer(int posicion); ///lectura
    int getNewID();
    bool validarID(int idBuscado, Artista &resultado);
    int buscarArtistaPorID(int idBuscado, Artista &resultado);
    bool guardarArtista(Artista reg, int posicion); ///sobreescritura

    ///ordenamiento
    //Ordenado por generos
    //Ordenado en orden alfabético
    void ordenarDefaultID(Artista *vArtista, int tam);
    void ordenarAlfabeticamente(Artista *vArtistas, int tam);
    void ordenarArtistasPorGenero(Artista *vArtistas, int tam);
    void ordenarArtistasPorPais(Artista *vArtistas, int tam);
};

#endif // ARCHIVOARTISTA_H_INCLUDED
