#ifndef MANAGERACCESO_H_INCLUDED
#define MANAGERACCESO_H_INCLUDED

#include "archivoAcceso.h"

class ManagerAcceso{
private:
    ArchivoAcceso _archivo;
public:
    /// SUBMENU ACCESO
    void mostrarSubmenuAccess();
    ///1 agregar acceso a archivo
    void cargarAcceso();
    ///2 ver acceso en archivo
    void mostrarAcceso();
    ///3 buscar acceso (cancion)
    void filtrarAccesoPorCancion();
    ///4 buscar acceso (artista)
    void filtrarAccesoPorArtista();
    ///5 eliminar acceso en archivo
    void eliminarAcceso();
    ///6 sobreescribir acceso en archivo
    void modificarAcceso();
};

#endif // MANAGERACCESO_H_INCLUDED
