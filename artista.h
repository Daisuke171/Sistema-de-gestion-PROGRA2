#ifndef ARTISTA_H
#define ARTISTA_H
#include <iostream>
#include<cstring>

class Artista{
private:
    char _nombreArtista[40];
    int _idArtista;
    char _generoMusical[40];
    char _emailArtista[40];
    char _paisArtista[40];
    bool _estadoArtista;
public:
    Artista();
    Artista(std::string nombre, int idArtista, std::string generoMusical, std::string email, std::string pais, bool estado);

    ///setters
    void setNombre(std::string nombre);
    void setIDArtista(int idArtista);
    void setGenero(std::string genero);
    void setEmail(std::string email);
    void setPais(std::string pais);
    void setEstado(bool estado);

    ///getters
    std::string getNombre() const;
    int getIDArtista() const;
    std::string getGenero() const;
    std::string getEmail() const;
    std::string getPais() const;
    bool getEstado() const;
};

#endif // ARTISTA_H
