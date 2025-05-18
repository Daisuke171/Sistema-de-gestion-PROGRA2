#include <iostream>
#include <cstring>
using namespace std;
#include "acceso.h"


Acceso::Acceso(){
    _cancion = -1;
    _usuario = -1;
    _fecha = Fecha();
    _hora = -1;
    _estado = false;
}

Acceso::Acceso(int id, int idSong, int idSub, Fecha fecha, int hora, bool estado){
    setID(id);
    setIdSong(idSong);
    setIdSub(idSub);
    setFecha(fecha);
    setHora(hora);
    setEstado(estado);
}

void Acceso::setID(int id){
    _id = id;
}

void Acceso::setIdSong(int idSong){
    _cancion = idSong;
}

void Acceso::setIdSub(int idSub){
    _usuario = idSub;
}

void Acceso::setFecha(const Fecha &fecha){
    _fecha = fecha;
}

void Acceso::setHora(int hora){
    _hora = hora;
}

void Acceso::setEstado(bool estado){
    _estado = estado;
}

int Acceso::getID() const{
    return _id;
}

int Acceso::getIdSong() const{
    return _cancion;
}

int Acceso::getIdSub() const{
    return _usuario;
}

std::string Acceso::getFecha(){
    return _fecha.toString();
}

int Acceso::getHora() const{
    return _hora;
}

bool Acceso::getEstado() const{
    return _estado;
}
