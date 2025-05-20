#ifndef MANAGERARTISTA_H_INCLUDED
#define MANAGERARTISTA_H_INCLUDED

#include "archivoArtista.h"

class ManagerArtista{
private:
    ArchivoArtista _archivo;
public:
    /// SUBMENU SUSCRIPTORES
     void mostrarSubmenuArtista();
    ///1 agregar subs a archivo
     void cargarArtista();
     void cargarArtista(std::string nombre);
    ///2 ver subs en archivo
     void mostrarArtista();
    ///3 buscar sub
    void buscarArtista();
    ///4 eliminar subs en archivo
    void eliminarArtista();
    ///5 sobreescribir
    void modificarArtista();
};

#endif // MANAGERARTISTA_H_INCLUDED
