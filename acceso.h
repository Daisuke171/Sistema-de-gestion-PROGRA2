#ifndef ACCESO_H_INCLUDED
#define ACCESO_H_INCLUDED

#include "cancion.h"
#include "suscriptor.h"
#include "fecha.h"

class Acceso{
private:
    int _cancion;                   /// id cancion escuchada
    int _usuario;                   /// id usuario que escucho la cancion
    Fecha _fecha;                   /// fecha de acceso a la cancion (dd/mm/yy)
    int _hora;                      /// hora de acceso a la cancion (24hrs)
public:
    Acceso();
    Acceso(int idSong, int idSub, Fecha fecha, int hora);

    ///setters
    void setIdSong(int idSong);
    void setIdSub(int idSub);
    void setFecha(const Fecha &fecha);
    void setHora(int hora);

    ///getters
    int getIdSong() const;
    int getIdSub() const;
    std::string getFecha();
    int getHora() const;
};

#endif // ACCESO_H_INCLUDED
