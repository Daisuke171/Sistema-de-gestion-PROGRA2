#include <iostream>
#include <cstring>
using namespace std;
#include "acceso.h"
#include "archivoAcceso.h"

bool ArchivoAcceso::guardarAcceso(Acceso reg){
    bool result;
    FILE *pFile;
    pFile = fopen(_nombre_archivo.c_str(), "ab");

    if(pFile==nullptr){
        return false;
    }

    result = fwrite(&reg, sizeof(Acceso), 1, pFile);

    fclose(pFile);

    return result;
}

int ArchivoAcceso::getCantidadRegistros(){
    FILE *pFile;
    pFile = fopen(_nombre_archivo.c_str(), "rb");
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
    pFile = fopen(_nombre_archivo.c_str(), "rb");

    if(pFile==nullptr){
        return false;
    }

    fread(reg, sizeof(Acceso), cantidad, pFile);

    fclose(pFile);
    return true;
}
