#include <iostream>
#include <cstring>
using namespace std;
#include "artista.h"

Artista::Artista(){
    _nombreArtista[0] = '\0';
    _idArtista = -1;
    _generoMusical[0] = '\0';
    _emailArtista[0] = '\0';
}

Artista::Artista(std::string nombre, int idArtista, std::string generoMusical, std::string email, std::string pais, bool estado){
    setNombre(nombre);
    setIDArtista(idArtista);
    setGenero(generoMusical);
    setEmail(email);
    setPais(pais);
    setEstado(estado);
}

void Artista::setNombre(std::string nombre){
    strcpy(_nombreArtista, nombre.c_str());
}

void Artista::setIDArtista(int idArtista){
    _idArtista = idArtista;
}

void Artista::setGenero(std::string genero){
    strcpy(_generoMusical, genero.c_str());
}

void Artista::setEmail(std::string email){
    strcpy(_emailArtista, email.c_str());
}

void Artista::setPais(std::string pais){
    strcpy(_paisArtista, pais.c_str());
}

void Artista::setEstado(bool estado){
    _estadoArtista = estado;
}


std::string Artista::getNombre() const{
    return _nombreArtista;
}

int Artista::getIDArtista() const{
    return _idArtista;
}

std::string Artista::getGenero() const{
    return _generoMusical;
}

std::string Artista::getEmail() const{
    return _emailArtista;
}

std::string Artista::getPais() const{
    return _paisArtista;
}

bool Artista::getEstado() const{
    return _estadoArtista;
}
