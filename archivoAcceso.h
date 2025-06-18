#ifndef ARCHIVOACCESO_H_INCLUDED
#define ARCHIVOACCESO_H_INCLUDED

#include <iostream>
#include <cstring>
#include "acceso.h"

class ArchivoHistorial{
private:
    std::string _nombreArchivo = "lista de accesos.dat";
public:
    ArchivoHistorial(std::string nombreArchivo);
    ArchivoHistorial();

    bool guardarHistorial(HistorialUsuario reg); ///escritura
    int getCantidadRegistros();
    bool leerMuchos(HistorialUsuario reg[], int cantidad); ///lectura archivos
    HistorialUsuario Leer(int posicion); ///lectura
    int getNewID();
    bool validarID(int idBuscado, HistorialUsuario &resultado);
    int buscarHistorialPorCancion(std::string cancion, HistorialUsuario &resultado);
    int buscarHistorialPorArtista(std::string artista, HistorialUsuario &resultado);
    bool guardarHistorial(HistorialUsuario reg, int posicion); ///sobreescritura

    ///ordenamiento
    void ordenarHistorialPorUsuario(HistorialUsuario *vHistoriales, int tam);
    void ordenarHistorialPorFecha(HistorialUsuario *vHistoriales, int tam);
};

#endif // ARCHIVOACCESO_H_INCLUDED
