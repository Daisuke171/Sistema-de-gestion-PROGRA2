#include <iostream>
#include <cstring>
using namespace std;
#include "archivosCancion.h"
#include "cancion.h"

ArchivoCancion::ArchivoCancion(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

ArchivoCancion::ArchivoCancion(){
    _nombreArchivo = "lista de canciones.dat";
}

bool ArchivoCancion::guardarCancion(Cancion reg){
    bool result;
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile==nullptr){
        return false;
    }

    result = fwrite(&reg, sizeof(Cancion), 1, pFile);

    fclose(pFile);

    return result;
}

int ArchivoCancion::getCantidadRegistros(){
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");
    int cantidad;

    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END); ///el cursor del puntero se mueve sin leer el archivo hasta el final del archivo

    cantidad = ftell(pFile) / sizeof(Cancion); ///ftell nos da el byte donde se encuentra el cursor actualmente, al estar al final nos va a dar el peso total del archivo

    fclose(pFile);

    return cantidad;
}

Cancion ArchivoCancion::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr){
        return Cancion();
    }
    Cancion reg;
    fseek(pArchivo, sizeof(Cancion) * posicion, SEEK_SET);
    fread(&reg, sizeof(Cancion), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

bool ArchivoCancion::leerMuchos(Cancion reg[], int cantidad){
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile==nullptr){
        return false;
    }

    fread(reg, sizeof(Cancion), cantidad, pFile);

    fclose(pFile);
    return true;
}

bool ArchivoCancion::validarID(int idBuscado, Cancion &resultado){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return false;

    Cancion reg;
    while(fread(&reg, sizeof(Cancion), 1, pFile) == 1){
        if(reg.getID() == idBuscado){
            resultado = reg;
            fclose(pFile);
            return true;
        }
    }

    fclose(pFile);
    return false;
}

int ArchivoCancion::getNewID(){
    return getCantidadRegistros() + 1;
}

bool ArchivoCancion::buscarPorCancionID(int idBuscado, Cancion &resultado){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return false;

    Cancion reg;
    while(fread(&reg, sizeof(Cancion), 1, pFile) == 1){
        if(reg.getID() == idBuscado){
            resultado = reg;
            fclose(pFile);
            return true;
        }
    }

    fclose(pFile);
    return false;
}

bool ArchivoCancion::buscarPorCancionNombre(std::string nombre, Cancion &resultado){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return false;

    Cancion reg;
    while(fread(&reg, sizeof(Cancion), 1, pFile) == 1){
        if(reg.getNombre() == nombre){
            resultado = reg;
            fclose(pFile);
            return true;
        }
    }

    fclose(pFile);
    return false;
}

bool ArchivoCancion::guardarCancion(Cancion reg, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr){
        return false;
    }
    fseek(pArchivo, sizeof(Cancion) * posicion, SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Cancion), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}
