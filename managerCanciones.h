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
    ///3 buscar sub
    void buscarCancion();
    ///4 eliminar subs en archivo
    void eliminarCancion();
    ///5 sobreescribir
    void modificarCancion();
};

#endif // MANAGERCANCIONES_H_INCLUDED
