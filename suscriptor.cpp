#include <iostream>
#include <cstring>
#include "suscriptor.h"
#include "fecha.h"
using namespace std;

Subscriptor::Subscriptor()
{
    _id = -1;
    _dni = -1;
    _nombre[0] = '\0';
    _apellido[0] = '\0';
    _telefono[0] = '\0';
    _email[0] = '\0';
    _fechaAlta = Fecha(0,0,0);
    _estado = false;
}

Subscriptor::Subscriptor(int id, int dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha fechaAlta, bool estado){
    setId(id);
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setFechaAlta(fechaAlta);
    setEstado(estado);
}

//SETTERS
void Subscriptor::setId(int i){
    _id = i;
}

void Subscriptor::setDni(int d){
    _dni  = d;
}

void Subscriptor::setNombre(string n){
    strcpy(_nombre, n.c_str());
}

void Subscriptor::setApellido(string a){
    strcpy(_apellido, a.c_str());
}

void Subscriptor::setTelefono(string t){
    strcpy(_telefono, t.c_str());
}

void Subscriptor::setEmail(string e){
    strcpy(_email, e.c_str());
}

void Subscriptor::setFechaAlta(const Fecha &nacimiento){ ///const para evitar que el objeto se modifique, y referencia para evitar que se hagan copias innecesarias
    _fechaAlta = nacimiento;
}

void Subscriptor::setEstado(bool estado){
    _estado = estado;
}

//GETTERS
int Subscriptor::getIDSub() const{
    return _id;
}

int Subscriptor::getDni() const{
    return _dni;
}

std::string Subscriptor::getNombre() const{
    return _nombre;
}

std::string Subscriptor::getApellido() const{
    return _apellido;
}

string Subscriptor::getTelefono() const{
    return _telefono;
}

string Subscriptor::getEmail() const{
    return _email;
}

string Subscriptor::getFechaAlta(){
    return _fechaAlta.toString();
}

bool Subscriptor::getEstado() const{
    return _estado;
}


