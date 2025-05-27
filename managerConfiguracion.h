#ifndef MANAGERCONFIGURACION_H_INCLUDED
#define MANAGERCONFIGURACION_H_INCLUDED

class ManagerConfiguracion{
public:
    void mostrarSubmenuConfig();

    ///guardar
    bool guardarData();

    ///restaurar
    bool restaurarData();

    ///exportar
    bool exportarData();
};



#endif // MANAGERCONFIGURACION_H_INCLUDED
