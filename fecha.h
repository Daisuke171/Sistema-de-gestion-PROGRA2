#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

#include <iostream>
#include <cstring>
#include <ctime>

class Fecha{
private:
    int _dia;
    int _mes;
    int _anio;
public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    ///getters
    int getAnio() const;
    int getMes() const;
    int getDia() const;


    ///setters
    void setAnio(int anio);
    void setMes(int mes);
    void setDia(int dia);

    std::string toString();
    int getDiaDesdeSTR(std::string anioSTR);
    int getMesDesdeSTR(std::string anioSTR);
    int getAnioDesdeSTR(std::string anioSTR);
};

#endif // CLSFECHA_H_INCLUDED
