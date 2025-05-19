#ifndef MANAGERSUBSCRIPTORE_H_INCLUDED
#define MANAGERSUBSCRIPTORE_H_INCLUDED

#include "archivosSuscriptor.h"


class ManagerSubscriptores{
private:
    ArchivoSubscriptor _archivo;
public:
    /// SUBMENU SUSCRIPTORES
    void mostrarSubmenuSubs();
    ///1 agregar subs a archivo
    void cargarSubscriptor();
    ///2 ver subs en archivo
    void mostrarSubscriptores();
    ///3 buscar sub
    void buscarSubscriptor();
    ///4 eliminar subs en archivo
    void eliminarSubscriptor();
    ///5 sobreescribir
    void modificarSubscriptor();

    ///ADMIN
    ///RESTAURAR ARCHIVO DEFAULT

    ///ELIMINAR ARCHIVO
};

#endif // MANAGERSUBSCRIPTORE_H_INCLUDED
