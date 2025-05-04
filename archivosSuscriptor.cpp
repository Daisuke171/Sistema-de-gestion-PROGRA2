#include "archivosSuscriptor.h"
#include "suscriptor.h"

bool ArchivoSubscriptor::guardarSubscriptor(Subscriptor reg){
    bool result;
    FILE *pFile;
    pFile = fopen(_nombre_archivo.c_str(), "ab");

    if(pFile==nullptr){
        return false;
    }

    result = fwrite(&reg, sizeof(Subscriptor), 1, pFile);

    fclose(pFile);

    return result;
}

int ArchivoSubscriptor::getCantidadRegistros(){
    FILE *pFile;
    pFile = fopen(_nombre_archivo.c_str(), "rb");
    int cantidad;

    if(pFile==nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END); ///el cursor del puntero se mueve sin leer el archivo hasta el final del archivo

    cantidad = ftell(pFile) / sizeof(Subscriptor); ///ftell nos da el byte donde se encuentra el cursor actualmente, al estar al final nos va a dar el peso total del archivo

    fclose(pFile);

    return cantidad;
}

bool ArchivoSubscriptor::leerMuchos(Subscriptor reg[], int cantidad){
    FILE *pFile;
    pFile = fopen(_nombre_archivo.c_str(), "rb");

    if(pFile==nullptr){
        return false;
    }

    fread(reg, sizeof(Subscriptor), cantidad, pFile);

    fclose(pFile);
    return true;
}

int ArchivoSubscriptor::getNewID(){
    return getCantidadRegistros() + 1;
}
