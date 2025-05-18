#ifndef ARTISTA_H
#define ARTISTA_H
#include <iostream>
#include<cstring>

class Artista{
private:
    char _nombre[40];
    int _idArtista;
    char _generoMusical[40];
    char _email[40];
public:
    Artista();
    Artista(std::string nombre, int idArtista, std::string generoMusical, std::string email);

    ///setters
    void setNombre(std::string nombre);
    void setIDArtista(int idArtista);
    void setGenero(std::string genero);
    void setEmail(std::string email);

    ///getters
    std::string getNombre() const;
    int getIDArtista() const;
    std::string getGenero() const;
    std::string getEmail() const;
};

#endif // ARTISTA_H
