#ifndef MANAGERCONFIGURACION_H_INCLUDED
#define MANAGERCONFIGURACION_H_INCLUDED

#include "artista.h"
#include "cancion.h"
#include "acceso.h"
#include "suscriptor.h"
#include "archivoAcceso.h"
#include "archivosCancion.h"
#include "archivoArtista.h"
#include "archivosSuscriptor.h"

class ManagerConfiguracion{
public:
    void mostrarSubmenuConfig();

    ///guardar
    bool guardarData();

    ///restaurar
    bool restaurarData();

    ///exportar
    bool exportarData();

    bool validarInit(Artista reg, ArchivoArtista archivo, FILE *pFileINIT);
    bool validarInit(Cancion reg, ArchivoCancion archivo, FILE *pFileINIT);
    bool validarInit(HistorialUsuario reg, ArchivoHistorial archivo, FILE *pFileINIT);
    bool validarInit(Subscriptor reg, ArchivoSubscriptor archivo, FILE *pFileINIT);

    bool validarBKP(Artista reg, ArchivoArtista archivo, FILE *pFile);
    bool validarBKP(Cancion reg, ArchivoCancion archivo, FILE *pFile);
    bool validarBKP(HistorialUsuario reg, ArchivoHistorial archivo, FILE *pFile);
    bool validarBKP(Subscriptor reg, ArchivoSubscriptor archivo, FILE *pFile);
};



#endif // MANAGERCONFIGURACION_H_INCLUDED
