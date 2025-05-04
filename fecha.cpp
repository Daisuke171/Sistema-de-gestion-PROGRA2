#include <iostream>
#include <cstring>
#include "fecha.h"
using namespace std;

Fecha::Fecha(){
    _anio=0;
    _mes=0;
    _dia=0;
}

Fecha::Fecha(int dia, int mes, int anio){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

void Fecha::setAnio(int anio){
    _anio = anio;
}
void Fecha::setMes(int mes){
    _mes = mes;
}
void Fecha::setDia(int dia){
    _dia = dia;
}

std::string Fecha::toString(){
    return to_string(_dia) + "/" + to_string(_mes) + "/" +to_string(_anio);
}
