#ifndef MANAGERACCESO_H_INCLUDED
#define MANAGERACCESO_H_INCLUDED

#include "archivoAcceso.h"

class ManagerAcceso{
private:
    ArchivoAcceso _archivo;
public:
    /// SUBMENU ACCESO
    void mostrarSubmenuAccess();
    ///1 agregar subs a archivo
    void cargarAcceso();
    ///2 ver subs en archivo
    void mostrarAcceso();

};

#endif // MANAGERACCESO_H_INCLUDED
