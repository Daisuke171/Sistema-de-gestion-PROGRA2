#include <iostream>
#include <cstring>
using namespace std;
#include "acceso.h"


HistorialUsuario::HistorialUsuario(){
    _idCancion = -1;
    _idUsuario = -1;
    _fecha = Fecha();
    _hora = -1;
    _estado = false;
}

HistorialUsuario::HistorialUsuario(int id, int idSong, int idSub, Fecha fecha, int hora, bool estado){
    setID(id);
    setIdSong(idSong);
    setIdSub(idSub);
    setFecha(fecha);
    setHora(hora);
    setEstado(estado);
}

void HistorialUsuario::setID(int id){
    _idHistorial = id;
}

void HistorialUsuario::setIdSong(int idSong){
    _idCancion = idSong;
}

void HistorialUsuario::setIdSub(int idSub){
    _idUsuario = idSub;
}

void HistorialUsuario::setFecha(const Fecha &fecha){
    _fecha = fecha;
}

void HistorialUsuario::setHora(int hora){
    _hora = hora;
}

void HistorialUsuario::setEstado(bool estado){
    _estado = estado;
}

int HistorialUsuario::getID() const{
    return _idHistorial;
}

int HistorialUsuario::getIdSong() const{
    return _idCancion;
}

int HistorialUsuario::getIdSub() const{
    return _idUsuario;
}

std::string HistorialUsuario::getFecha(){
    return _fecha.toString();
}

int HistorialUsuario::getHora() const{
    return _hora;
}

bool HistorialUsuario::getEstado() const{
    return _estado;
}
