#include <iostream>
#include <cstring>
using namespace std;
#include "acceso.h"


Acceso::Acceso(){
    _cancion = -1;
    _usuario = -1;
    _fecha = Fecha();
    _hora = -1;
}

Acceso::Acceso(int idSong, int idSub, Fecha fecha, int hora){
    setIdSong(idSong);
    setIdSub(idSub);
    setFecha(fecha);
    setHora(hora);
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
