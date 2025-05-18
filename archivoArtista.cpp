#include <iostream>
#include <cstring>
using namespace std;
#include "archivoArtista.h"
#include "artista.h"

ArchivoArtista::ArchivoArtista(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

ArchivoArtista::ArchivoArtista(){
    _nombreArchivo = "lista de artista.dat";
}

bool ArchivoArtista::guardarArtista(Artista reg){
    bool result;
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile==nullptr){
        return false;
    }

    result = fwrite(&reg, sizeof(Artista), 1, pFile);

    fclose(pFile);

    return result;
}

int ArchivoArtista::getCantidadRegistros(){
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");
    int cantidad;

    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END); ///el cursor del puntero se mueve sin leer el archivo hasta el final del archivo

    cantidad = ftell(pFile) / sizeof(Artista); ///ftell nos da el byte donde se encuentra el cursor actualmente, al estar al final nos va a dar el peso total del archivo

    fclose(pFile);

    return cantidad;
}

bool ArchivoArtista::validarNombreArtista(std::string nombre, Artista &resultado){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return false;

    Artista reg;
    while(fread(&reg, sizeof(Artista), 1, pFile) == 1){
        if(reg.getNombre() == nombre){
            resultado = reg;
            fclose(pFile);
            return true;
        }
    }

    fclose(pFile);
    return false;
}
