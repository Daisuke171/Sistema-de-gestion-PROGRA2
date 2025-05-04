#ifndef ARCHIVOSSUSCRIPTOR_H_INCLUDED
#define ARCHIVOSSUSCRIPTOR_H_INCLUDED

#include <iostream>
#include <cstring>
#include "suscriptor.h"

class ArchivoSubscriptor{
private:
    std::string _nombre_archivo = "lista de subscriptores.dat";
public:
    bool guardarSubscriptor(Subscriptor reg);
    int getCantidadRegistros();
    bool leerMuchos(Subscriptor reg[], int cantidad);
    int getNewID();
};

#endif // ARCHIVOSSUSCRIPTOR_H_INCLUDED
