#ifndef MANAGERCANCIONES_H_INCLUDED
#define MANAGERCANCIONES_H_INCLUDED

#include "archivosCancion.h"

class ManagerCanciones{
private:
    ArchivoCancion _archivo;
public:
    /// SUBMENU Canciones
    void mostrarSubmenuCanciones();
    ///1 agregar canciones a archivo
    void cargarCancion();
    ///2 ver canciones en archivo
    void mostrarCancion();
};

#endif // MANAGERCANCIONES_H_INCLUDED
