#include <iostream>
#include <cstring>
#include "fecha.h"
#include <ctime>
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

int Fecha::getAnio() const{
    return _anio;
}

int Fecha::getMes() const{
    return _mes;
}

int Fecha::getDia() const{
    return _dia;
}

int Fecha::getDiaDesdeSTR(std::string diaSTR){
    char slash = '/';
    int slashInt = (int)slash;
    int vDia[2] = {};

    int contadorSlashes = 0;
    int dia = 0;
    for(int  i=0; i<diaSTR.length(); i++) {
        if(diaSTR[i]==slash) {
            contadorSlashes++;
        }

        if(contadorSlashes==1){
            if(i==2){
                vDia[0] = diaSTR[0] - '0';
                vDia[1] = diaSTR[1] - '0';

                dia = vDia[0]*10 + vDia[1];
                break;
            }
            else if(i==1){
                vDia[0] = 0;
                vDia[1] = diaSTR[0] - '0';

                dia = vDia[1];
                break;
            }
        }
    }

    return dia;
}

int Fecha::getMesDesdeSTR(std::string mesSTR){
    char slash = '/';
    int slashInt = (int)slash;
    int vMes[2] = {};

    int contadorSlashes = 0;
    int mes = 0;
    for(int  i=0; i<mesSTR.length(); i++) {
        if(mesSTR[i]==slash) {
            contadorSlashes++;
            continue;
        }

        if(contadorSlashes==1){
            if(mesSTR[i+1]==slash){
                mes = mesSTR[i] - '0';
                break;
            }
            else if(mesSTR[i+1]!=slash){
                vMes[0] = mesSTR[i] - '0';
                vMes[1] = mesSTR[i+1] - '0';
                mes = vMes[0]*10 + vMes[1];
                break;
            }
        }

    }

    return mes;
}

int Fecha::getAnioDesdeSTR(std::string anioSTR){
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
