#include <iostream>
#include <cstring>
#include "suscriptor.h"
#include "fecha.h"
using namespace std;

Subscriptor::Subscriptor()
{
    _idUsuario = -1;
    _dniUsuario[0] = -1;
    _nombreUsuario[0] = '\0';
    _apellidoUsuario[0] = '\0';
    _telefonoUsuario[0] = '\0';
    _email[0] = '\0';
    _fechaNacimientoUsuario = Fecha(0,0,0);
    _estado = false;
}

Subscriptor::Subscriptor(int id, std::string dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha fechaNaci, bool estado){
    setId(id);
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setFechaNacimiento(fechaNaci);
    setEstado(estado);
}

//SETTERS
void Subscriptor::setId(int i){
    _idUsuario = i;
}

void Subscriptor::setDni(std::string dni){
    strcpy(_dniUsuario, dni.c_str());
}

void Subscriptor::setNombre(string nombre){
    strcpy(_nombreUsuario, nombre.c_str());
}

void Subscriptor::setApellido(string apellido){
    strcpy(_apellidoUsuario, apellido.c_str());
}

void Subscriptor::setTelefono(string telefono){
    strcpy(_telefonoUsuario, telefono.c_str());
}

void Subscriptor::setEmail(string e){
    strcpy(_email, e.c_str());
}

void Subscriptor::setFechaNacimiento(const Fecha &nacimiento){ ///const para evitar que el objeto se modifique, y referencia para evitar que se hagan copias innecesarias
    _fechaNacimientoUsuario = nacimiento;
}

void Subscriptor::setEstado(bool estado){
    _estado = estado;
}

//GETTERS
int Subscriptor::getIDSub() const{
    return _idUsuario;
}

std::string Subscriptor::getDni() const{
    return _dniUsuario;
}

std::string Subscriptor::getNombre() const{
    return _nombreUsuario;
}

std::string Subscriptor::getApellido() const{
    return _apellidoUsuario;
}

string Subscriptor::getTelefono() const{
    return _telefonoUsuario;
}

string Subscriptor::getEmail() const{
    return _email;
}

string Subscriptor::getFechaNacimiento(){
    return _fechaNacimientoUsuario.toString();
}

bool Subscriptor::getEstado() const{
    return _estado;
}


