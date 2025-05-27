#ifndef ACCESO_H_INCLUDED
#define ACCESO_H_INCLUDED

#include "cancion.h"
#include "suscriptor.h"
#include "fecha.h"

class HistorialUsuario{
private:
    int _idHistorial;
    int _idCancion;                   /// id cancion escuchada
    int _idUsuario;                   /// id usuario que escucho la cancion
    Fecha _fecha;                   /// fecha de acceso a la cancion (dd/mm/yy)
    int _hora;                      /// hora de acceso a la cancion (24hrs)
    bool _estado;
public:
    HistorialUsuario();
    HistorialUsuario(int id, int idSong, int idSub, Fecha fecha, int hora, bool estado);

    ///setters
    void setID(int id);
    void setIdSong(int idSong);
    void setIdSub(int idSub);
    void setFecha(const Fecha &fecha);
    void setHora(int hora);
    void setEstado(bool estado);

    ///getters
    int getID() const;
    int getIdSong() const;
    int getIdSub() const;
    std::string getFecha();
    int getHora() const;
    bool getEstado() const;
};

#endif // ACCESO_H_INCLUDED
