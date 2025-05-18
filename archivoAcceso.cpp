#include <iostream>
#include <cstring>
using namespace std;
#include "acceso.h"
#include "cancion.h"
#include "artista.h"
#include "archivoAcceso.h"
#include "archivosCancion.h"
#include "archivoArtista.h"

ArchivoAcceso::ArchivoAcceso(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}
ArchivoAcceso::ArchivoAcceso(){
    _nombreArchivo = "lista de accesos.dat";
}


bool ArchivoAcceso::guardarAcceso(Acceso reg){
    bool result;
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile==nullptr){
        return false;
    }

    result = fwrite(&reg, sizeof(Acceso), 1, pFile);

    fclose(pFile);

    return result;
}

int ArchivoAcceso::getCantidadRegistros(){
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");
    int cantidad;

    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END); ///el cursor del puntero se mueve sin leer el archivo hasta el final del archivo

    cantidad = ftell(pFile) / sizeof(Acceso); ///ftell nos da el byte donde se encuentra el cursor actualmente, al estar al final nos va a dar el peso total del archivo

    fclose(pFile);

    return cantidad;
}

bool ArchivoAcceso::leerMuchos(Acceso reg[], int cantidad){
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile==nullptr){
        return false;
    }

    fread(reg, sizeof(Acceso), cantidad, pFile);

    fclose(pFile);
    return true;
}

Acceso ArchivoAcceso::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr){
        return Acceso();
    }
    Acceso reg;
    fseek(pArchivo, sizeof(Acceso) * posicion, SEEK_SET);
    fread(&reg, sizeof(Acceso), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int ArchivoAcceso::buscarAccesoPorCancion(std::string cancion, Acceso &resultado){
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

int ArchivoAcceso::buscarAccesoPorArtista(std::string artista, Acceso &resultado){
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

bool ArchivoAcceso::guardarAcceso(Acceso reg, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr){
        return false;
    }
    fseek(pArchivo, sizeof(Acceso) * posicion, SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Acceso), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoAcceso::getNewID(){
    return getCantidadRegistros() + 1;
}

bool ArchivoAcceso::validarID(int idBuscado, Acceso &resultado){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return false;

    Acceso reg;
    while(fread(&reg, sizeof(Acceso), 1, pFile) == 1){
        if(reg.getID() == idBuscado){
            resultado = reg;
            fclose(pFile);
            return true;
        }
    }

    fclose(pFile);
    return false;
}
