#ifndef SUSCRIPTOR_H_INCLUDED
#define SUSCRIPTOR_H_INCLUDED

#include <iostream>
#include "fecha.h"
#include <cstring>

class Subscriptor{
private:
    int _idUsuario;
    char _dniUsuario[15];
    char _nombreUsuario[30];
    char _apellidoUsuario[30];
    char _telefonoUsuario[20];
    char _email[40];
    Fecha _fechaNacimientoUsuario;
    bool _estado;
public:
    Subscriptor();
    Subscriptor(int id, std::string dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha fechaNaci, bool estado);

    //SETTERS
    void setId(int) ;
    void setDni(std::string);
    void setNombre(std::string);
    void setApellido(std::string);
    void setTelefono(std::string);
    void setEmail(std::string);
    void setFechaNacimiento(const Fecha &fecha);
    void setEstado(bool);

    //GETTERS
    int getIDSub() const;
    std::string getDni() const;
    std::string getNombre() const;
    std::string getApellido() const;
    std::string getTelefono() const;
    std::string getEmail() const;
    std::string getFechaNacimiento();
    Fecha getFechaNacimiento() const;
    bool getEstado() const;
    int getEdad(const int dia, const int mes, const int anio) const;


};


#endif // SUSCRIPTOR_H_INCLUDED
