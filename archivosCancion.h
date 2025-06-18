#ifndef ARCHIVOSCANCION_H_INCLUDED
#define ARCHIVOSCANCION_H_INCLUDED

#include "cancion.h"

class ArchivoCancion{
private:
    std::string _nombreArchivo = "lista de canciones.dat";
public:
    ArchivoCancion(std::string nombreArchivo);
    ArchivoCancion();

    bool guardarCancion(Cancion reg); ///escritura
    int getCantidadRegistros();
    Cancion Leer(int posicion); ///lectura
    bool leerMuchos(Cancion reg[], int cantidad); ///lectura archivos
    bool validarID(int idBuscado, Cancion &resultado);
    int getNewID();
    bool buscarPorCancionID(int idBuscado, Cancion &resultado);
    bool buscarPorCancionNombre(std::string nombre, Cancion &resultado);
    bool guardarCancion(Cancion reg, int posicion); ///sobreescritura


    ///ordenamiento
    void ordenarCancionesPorGenero(Cancion *vCanciones, int tam);
    void ordenarCancionesPorArtistas(Cancion *vCanciones, int tam);
    void ordenarCancionesPorAnio(Cancion *vCanciones, int tam);
};

#endif // ARCHIVOSCANCION_H_INCLUDED
