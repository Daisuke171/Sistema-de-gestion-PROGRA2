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
    ///3 eliminar acceso en archivo
    void eliminarHistorial();
    ///4 sobreescribir acceso en archivo
    void modificarHistorial();

    void buscarHistorial();
};

#endif // MANAGERACCESO_H_INCLUDED
