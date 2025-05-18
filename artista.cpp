#include <iostream>
#include <cstring>
using namespace std;
#include "artista.h"

Artista::Artista(){
    _nombre[0] = '\0';
    _idArtista = -1;
    _generoMusical[0] = '\0';
    _email[0] = '\0';
}

Artista::Artista(std::string nombre, int idArtista, std::string generoMusical, std::string email, bool estado){
    setNombre(nombre);
    setIDArtista(idArtista);
    setGenero(generoMusical);
    setEmail(email);
    setEstado(estado);
}


void Artista::setNombre(std::string nombre){
    strcpy(_nombre, nombre.c_str());
}

void Artista::setIDArtista(int idArtista){
    _idArtista = idArtista;
}

void Artista::setGenero(std::string genero){
    strcpy(_generoMusical, genero.c_str());
}

void Artista::setEmail(std::string email){
    strcpy(_email, email.c_str());
}

void Artista::setEstado(bool estado){
    _estado = estado;
}

std::string Artista::getNombre() const{
    return _nombre;
}

int Artista::getIDArtista() const{
    return _idArtista;
}

std::string Artista::getGenero() const{
    return _generoMusical;
}

std::string Artista::getEmail() const{
    return _email;
}
