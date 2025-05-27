#ifndef MANAGERACCESO_H_INCLUDED
#define MANAGERACCESO_H_INCLUDED

#include "archivoAcceso.h"

class ManagerHistorial{
private:
    ArchivoHistorial _archivo;
public:
    /// SUBMENU ACCESO
    void mostrarSubmenuHistorial();
    ///1 agregar acceso a archivo
    void cargarHistorial();
    ///2 ver acceso en archivo
    void mostrarHistorial();
    ///3 buscar acceso (cancion)
    void filtrarHistorialPorCancion();
    ///4 buscar acceso (artista)
    void filtrarHistorialPorArtista();
    ///5 eliminar acceso en archivo
    void eliminarHistorial();
    ///6 sobreescribir acceso en archivo
    void modificarHistorial();
};

#endif // MANAGERACCESO_H_INCLUDED
