#include <iostream>
#include <cstring>
using namespace std;
#include "acceso.h"
#include "cancion.h"
#include "artista.h"
#include "fecha.h"
#include "archivoAcceso.h"
#include "archivosCancion.h"
#include "archivoArtista.h"
#include "arrayUtils.h"

ArchivoHistorial::ArchivoHistorial(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}
ArchivoHistorial::ArchivoHistorial(){
    _nombreArchivo = "lista de accesos.dat";
}


bool ArchivoHistorial::guardarHistorial(HistorialUsuario reg){
    bool result;
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile==nullptr){
        return false;
    }

    result = fwrite(&reg, sizeof(HistorialUsuario), 1, pFile);

    fclose(pFile);

    return result;
}

int ArchivoHistorial::getCantidadRegistros(){
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");
    int cantidad;

    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END); ///el cursor del puntero se mueve sin leer el archivo hasta el final del archivo

    cantidad = ftell(pFile) / sizeof(HistorialUsuario); ///ftell nos da el byte donde se encuentra el cursor actualmente, al estar al final nos va a dar el peso total del archivo

    fclose(pFile);

    return cantidad;
}

bool ArchivoHistorial::leerMuchos(HistorialUsuario reg[], int cantidad){
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile==nullptr){
        return false;
    }

    fread(reg, sizeof(HistorialUsuario), cantidad, pFile);

    fclose(pFile);
    return true;
}

HistorialUsuario ArchivoHistorial::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr){
        return HistorialUsuario();
    }
    HistorialUsuario reg;
    fseek(pArchivo, sizeof(HistorialUsuario) * posicion, SEEK_SET);
    fread(&reg, sizeof(HistorialUsuario), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int ArchivoHistorial::buscarHistorialPorCancion(std::string cancion, HistorialUsuario &resultado){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return -1;

    Cancion reg;
    int i=0;
    while(fread(&reg, sizeof(Subscriptor), 1, pFile) == 1){
        if(reg.getNombre() == cancion){
            fclose(pFile);
            return i;
        }
        i++;
    }

    fclose(pFile);
    return -1;
}

int ArchivoHistorial::buscarHistorialPorArtista(std::string artista, HistorialUsuario &resultado){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return -1;

    Artista reg;
    int i=0;
    while(fread(&reg, sizeof(Subscriptor), 1, pFile) == 1){
        if(reg.getNombre() == artista){
            fclose(pFile);
            return i;
        }
        i++;
    }

    fclose(pFile);
    return -1;
}

bool ArchivoHistorial::guardarHistorial(HistorialUsuario reg, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr){
        return false;
    }
    fseek(pArchivo, sizeof(HistorialUsuario) * posicion, SEEK_SET);
    bool ok = fwrite(&reg, sizeof(HistorialUsuario), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoHistorial::getNewID(){
    return getCantidadRegistros() + 1;
}

bool ArchivoHistorial::validarID(int idBuscado, HistorialUsuario &resultado){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return false;

    HistorialUsuario reg;
    while(fread(&reg, sizeof(HistorialUsuario), 1, pFile) == 1){
        if(reg.getID() == idBuscado){
            resultado = reg;
            fclose(pFile);
            return true;
        }
    }

    fclose(pFile);
    return false;
}

void ArchivoHistorial::ordenarDefaultID(HistorialUsuario *vHistorial, int tam){
    int posmin;

    for(int i=0; i<tam-1; i++){
        posmin = i;
        for(int j=i+1; j<tam; j++){
            if(vHistorial[j].getID()<vHistorial[posmin].getID()){
                posmin = j;
            }
        }

        HistorialUsuario aux = vHistorial[i];
        vHistorial[i] = vHistorial[posmin];
        vHistorial[posmin] = aux;
    }
}

void ArchivoHistorial::ordenarHistorialPorUsuario(HistorialUsuario *vHistoriales, int tam){
    int posmin;

    for(int i=0; i<tam-1; i++) {
        posmin = i;
        for(int j=i+1; j<tam; j++) {
            if(vHistoriales[j].getIdSub()<vHistoriales[posmin].getIdSub()) {
                posmin = j;
            }
        }

        HistorialUsuario aux = vHistoriales[i];
        vHistoriales[i] = vHistoriales[posmin];
        vHistoriales[posmin] = aux;
    }
}

void ArchivoHistorial::ordenarHistorialPorFecha(HistorialUsuario *vHistoriales, int tam){
    for(int i=0; i<tam-1; i++) {
        int posMin = i;

        for(int j=i+1; j<tam; j++) {
            std::string fecha1 = vHistoriales[posMin].getFecha();
            std::string fecha2 = vHistoriales[j].getFecha();

            int anio1 = getAnioDesdeSTR(fecha1);
            int anio2 = getAnioDesdeSTR(fecha2);

            int mes1 = getMesDesdeSTR(fecha1);
            int mes2 = getMesDesdeSTR(fecha2);

            int dia1 = getDiaDesdeSTR(fecha1);
            int dia2 = getDiaDesdeSTR(fecha2);

            if(anio2 < anio1 || (anio2 == anio1 && mes2 < mes1) || (anio2 == anio1 && mes2 == mes1 && dia2 < dia1)){
                posMin = j;
            }
        }

        if (posMin != i) {
            HistorialUsuario aux = vHistoriales[i];
            vHistoriales[i] = vHistoriales[posMin];
            vHistoriales[posMin] = aux;
        }
    }
}
