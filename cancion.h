#ifndef CANCION_H_INCLUDED
#define CANCION_H_INCLUDED
#include "fecha.h"
#include <cstring>

class Cancion{
private:
    int _id;
    char _nombre[60];
    char _autor[60];
    char _interprete[60];
    Fecha _fechaPublicacion;
    bool _estado;
public:
    Cancion();
    Cancion(int id, std::string nombre, std::string autor, std::string interprete, Fecha fechaPublicacion, bool estado);

    ///Setters
    void setID(int id);
    void setNombre(std::string nombre);
    void setAutor(std::string autor);
    void setInterprete(std::string interprete);
    void setFechaPublicacion(const Fecha &fechaPublicacion);
    void setEstado(bool estado);

    ///Getters
    int getID() const;
    std::string getNombre() const;
    std::string getAutor() const;
    std::string getInterprete() const;
    std::string getFechaPublicacion();
    bool getEstado() const;
};

#endif // CANCION_H_INCLUDED
