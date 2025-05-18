#include <iostream>
#include <cstring>
using namespace std;
/**
Archivo::Archivo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool Archivo::Guardar(Servicio servicio){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&servicio, sizeof(Servicio), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool Archivo::Guardar(Servicio servicio, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Servicio) * posicion, SEEK_SET);
    bool ok = fwrite(&servicio, sizeof(Servicio), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int Archivo::Buscar(int IDServicio){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Servicio servicio;
    int i = 0;
    while(fread(&servicio, sizeof(Servicio), 1, pArchivo)){
        if(servicio.getIDServicio() == IDServicio){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Servicio Archivo::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Servicio();
    }
    Servicio servicio;
    fseek(pArchivo, sizeof(Servicio) * posicion, SEEK_SET);
    fread(&servicio, sizeof(Servicio), 1, pArchivo);
    fclose(pArchivo);
    return servicio;
}

int Archivo::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Servicio);
    fclose(pArchivo);
    return cantidadRegistros;
}

void Archivo::Leer(int cantidadRegistros, Servicio *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Servicio), 1, pArchivo);
    }
    fclose(pArchivo);
}
*/
