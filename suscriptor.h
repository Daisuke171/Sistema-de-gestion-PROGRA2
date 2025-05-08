#ifndef SUSCRIPTOR_H_INCLUDED
#define SUSCRIPTOR_H_INCLUDED

#include <iostream>
#include "fecha.h"
#include <cstring>

class Subscriptor{
private:
    int _id;
    int _dni;
    char _nombre[30];
    char _apellido[30];
    char _telefono[20];
    char _email[40];
    Fecha _nacimiento;
public:
    Subscriptor();
    Subscriptor(int id, int dni, std::string nombre, std::string apellido, std::string telefono, std::string email, Fecha nacimiento);

    //SETTERS
    void setId(int) ;
    void setDni(int);
    void setNombre(std::string);
    void setApellido(std::string);
    void setTelefono(std::string);
    void setEmail(std::string);
    void setNacimiento(const Fecha &fecha);

    //GETTERS
    int getIDSub() const;
    int getDni() const;
    std::string getNombre() const;
    std::string getApellido() const;
    std::string getTelefono() const;
    std::string getEmail() const;
    std::string getFechaNacimiento();
};


#endif // SUSCRIPTOR_H_INCLUDED
