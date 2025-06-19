#ifndef ARCHIVOSSUSCRIPTOR_H_INCLUDED
#define ARCHIVOSSUSCRIPTOR_H_INCLUDED

#include <iostream>
#include <cstring>
#include "suscriptor.h"

class ArchivoSubscriptor{
private:
    std::string _nombreArchivo = "lista de subscriptores.dat";
public:
    ArchivoSubscriptor(std::string nombreArchivo);
    ArchivoSubscriptor();

    bool guardarSubscriptor(Subscriptor reg); ///escritura
    int getCantidadRegistros();
    bool leerMuchos(Subscriptor reg[], int cantidad); ///lectura archivos
    Subscriptor Leer(int posicion); ///lectura
    int getNewID();
    bool validarID(int idBuscado, Subscriptor &resultado);
    bool validarDNI(std::string dniBuscado);
    int devolverIDmediandeDNI(std::string dniBuscado);
    int buscarSubPorID(int idBuscado, Subscriptor &resultado);
    bool guardarSubscriptor(Subscriptor reg, int posicion); ///sobreescritura

    ///ordenamiento
    void ordenarDefaultID(Subscriptor *vSubscriptor, int tam);
    void ordenarSubscriptoresPorDNI(Subscriptor *vSubscriptor, int tam);
    void ordenarSubscriptoresPorNombre(Subscriptor *vSubscriptor, int tam);
    void ordenarSubscriptoresPorApellido(Subscriptor *vSubscriptor, int tam);
};

#endif // ARCHIVOSSUSCRIPTOR_H_INCLUDED
