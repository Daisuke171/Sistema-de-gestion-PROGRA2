#include <iostream>
#include <cstring>
using namespace std;
#include "archivosSuscriptor.h"
#include "suscriptor.h"

bool ArchivoSubscriptor::guardarSubscriptor(Subscriptor reg){
    bool result;
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if(pFile==nullptr){
        return false;
    }

    result = fwrite(&reg, sizeof(Subscriptor), 1, pFile);

    fclose(pFile);

    return result;
}

int ArchivoSubscriptor::getCantidadRegistros(){
    FILE *pFile;
    pFile = fopen(_nombreArchivo.c_str(), "rb");
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
    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile==nullptr){
        return false;
    }

    fread(reg, sizeof(Subscriptor), cantidad, pFile);

    fclose(pFile);
    return true;
}

Subscriptor ArchivoSubscriptor::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr){
        return Subscriptor();
    }
    Subscriptor reg;
    fseek(pArchivo, sizeof(Subscriptor) * posicion, SEEK_SET);
    fread(&reg, sizeof(Subscriptor), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int ArchivoSubscriptor::getNewID(){
    return getCantidadRegistros() + 1;
}

ArchivoSubscriptor::ArchivoSubscriptor(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}
ArchivoSubscriptor::ArchivoSubscriptor(){
    _nombreArchivo = "lista de subscriptores.dat";
}

bool ArchivoSubscriptor::validarID(int idBuscado, Subscriptor &resultado){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return false;

    Subscriptor reg;
    while(fread(&reg, sizeof(Subscriptor), 1, pFile) == 1){
        if(reg.getIDSub() == idBuscado){
            resultado = reg;
            fclose(pFile);
            return true;
        }
    }

    fclose(pFile);
    return false;
}
int ArchivoSubscriptor::buscarSubPorID(int idBuscado, Subscriptor &resultado){
    FILE *pFile = fopen(_nombreArchivo.c_str(), "rb");
    if(pFile == nullptr) return -1;

    Subscriptor reg;
    int i=0;
    while(fread(&reg, sizeof(Subscriptor), 1, pFile) == 1){
        if(reg.getIDSub() == idBuscado){
            fclose(pFile);
            return i;
        }
        i++;
    }

    fclose(pFile);
    return -1;
}

bool ArchivoSubscriptor::guardarSubscriptor(Subscriptor reg, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr){
        return false;
    }
    fseek(pArchivo, sizeof(Subscriptor) * posicion, SEEK_SET);
    bool ok = fwrite(&reg, sizeof(Subscriptor), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

void ArchivoSubscriptor::ordenarSubscriptoresPorDNI(Subscriptor *vSubscriptor, int tam){
    int posmin;

    for(int i=0; i<tam-1; i++) {
        posmin = i;
        for(int j=i+1; j<tam; j++) {
            if(vSubscriptor[j].getDni()<vSubscriptor[posmin].getDni()) {
                posmin = j;
            }
        }

        Subscriptor aux = vSubscriptor[i];
        vSubscriptor[i] = vSubscriptor[posmin];
        vSubscriptor[posmin] = aux;
    }
}

void ArchivoSubscriptor::ordenarSubscriptoresPorNombre(Subscriptor *vSubscriptor, int tam){
    for(int i=0; i<tam-1; i++) {
        for(int j=0; j<tam-i-1; j++){
            std::string nombre1 = vSubscriptor[j].getNombre();
            std::string nombre2 = vSubscriptor[j+1].getNombre();
            if(nombre1 > nombre2){
                Subscriptor aux = vSubscriptor[j];
                vSubscriptor[j] = vSubscriptor[j + 1];
                vSubscriptor[j+1] = aux;
            }
        }
    }
}

void ArchivoSubscriptor::ordenarSubscriptoresPorApellido(Subscriptor *vSubscriptor, int tam){
    for(int i=0; i<tam-1; i++) {
        for(int j=0; j<tam-i-1; j++){
            std::string apellido1 = vSubscriptor[j].getApellido();
            std::string apellido2 = vSubscriptor[j+1].getApellido();
            if(apellido1 > apellido2){
                Subscriptor aux = vSubscriptor[j];
                vSubscriptor[j] = vSubscriptor[j + 1];
                vSubscriptor[j+1] = aux;
            }
        }
    }
}
