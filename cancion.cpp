#include <iostream>
#include <cstring>
using namespace std;
#include "cancion.h"
#include "fecha.h"
#include "artista.h"
#include "archivoArtista.h"

Cancion::Cancion(){
    _idCancion = 0;
    _idArtista = 0;
    _nombre[0] = '\0';
    _autor[0] = '\0';
    _interprete[0] = '\0';
    _fechaPublicacion = Fecha();
    _estadoCancion = false;
}

Cancion::Cancion(int id, int idArtista, std::string nombre, std::string autor, std::string interprete, Fecha fechaPublicacion, bool estado){
    setID(id);
    setIDArtista(idArtista);
    setNombre(nombre);
    setAutor(autor);
    setInterprete(interprete);
    setFechaPublicacion(fechaPublicacion);
    setEstado(estado);
}


///SETTERS
void Cancion::setID(int id){
    _idCancion = id;
}

void Cancion::setIDArtista(int idArtista){
    _idArtista = idArtista;;
}

void Cancion::setNombre(std::string nombre){
    strcpy(_nombre, nombre.c_str());
}

void Cancion::setAutor(std::string autor){
    strcpy(_autor, autor.c_str());
}

void Cancion::setInterprete(std::string interprete){
    strcpy(_interprete, interprete.c_str());
}

void Cancion::setFechaPublicacion(const Fecha &fechaPublicacion){
    _fechaPublicacion = fechaPublicacion;
}

void Cancion::setEstado(bool estado){
    _estadoCancion = estado;
}


///GETTERS
int Cancion::getID() const{
    return _idCancion;
}

int Cancion::getIDArtista() const{
    return _idArtista;
}

std::string Cancion::getNombre() const{
    return _nombre;
}

std::string Cancion::getAutor() const{
    return _autor;
}

std::string Cancion::getInterprete() const{
    return _interprete;
}

Fecha Cancion::getFecha(){
    Fecha _fechaPublicacion;
}

std::string Cancion::getFechaPublicacion(){
    return _fechaPublicacion.toString();
}

bool Cancion::getEstado() const{
    return _estadoCancion;
}

std::string Cancion::getGenero() const{
    Artista regArt;
    ArchivoArtista archivoArtista("lista de artista.dat");
    std::string _genero;
    int idArtista = this -> getIDArtista();

    regArt = archivoArtista.Leer(idArtista-1);
    _genero = regArt.getGenero();

    return _genero;
}

int Cancion::getAnioPublicacion(){
    std::string anioSTR = this -> getFechaPublicacion();
    char slash = '/';
    int slashInt = (int)slash;
    int vAnio[4] = {};
    int indexAnio = 0;

    int contadorSlashes = 0;
    for(int  i=0; i<anioSTR.length(); i++) {
        if(anioSTR[i]==slash) {
            contadorSlashes++;
            continue;
        }

        if(contadorSlashes==2 && indexAnio<4) {
            // Convertimos de char '2' a int 2 restando '0' que es 48 en int
            vAnio[indexAnio] = anioSTR[i] - '0';
            indexAnio++;
        }
    }

    int anio = 0;
    int unidades = 1000;

    for(int i=0; i<4; i++){
        anio += vAnio[i]*unidades;
        unidades /= 10;
    }

    return anio;
}
