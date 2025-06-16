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

std::string Cancion::getFechaPublicacion(){
    return _fechaPublicacion.toString();
}

bool Cancion::getEstado() const{
    return _estadoCancion;
}
