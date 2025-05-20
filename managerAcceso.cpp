#include <iostream>
#include <cstring>
using namespace std;
#include "managerAcceso.h"
#include "rlutils.h"
#include "acceso.h"
#include "cancion.h"
#include "suscriptor.h"
#include "artista.h"
#include "archivosSuscriptor.h"
#include "archivoAcceso.h"
#include "archivosCancion.h"
#include "archivoArtista.h"
using namespace rlutil;

void ManagerAcceso::mostrarSubmenuAccess(){
    int key;
    setBackgroundColor(MAGENTA);
    setColor(WHITE);
    bool exit = false;
    int y=0;
    hidecursor();

    do{
        system("cls");
        int i=3;
        locate(tcols()/3,i);
        cout << "Red Note Acceso" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "------------------------" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "1- Cargar Acceso" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "2- Mostrar Accesos" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "3- Filtrar Listado de Accesos por Cancion" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "4- Filtrar Listado de Accesos por Artista" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "5- Eliminar Acceso" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "5- Modificar Acceso" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "0- Volver atras" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "------------------------" << endl;
        locate(tcols()/3,i+2);
        cout << "SELECCIONE UNA OPCION " << endl;


        ///PUNTERO PARA SELECCIONAR OPCION :P
        locate((tcols()/3)-2, 5+y);
        cout << (char)175;
        key = getkey();
        ///PUNTERO PARA SELECCIONAR OPCION :P

        switch (key){
            case 14: //up
                locate((tcols()/3)-2, 5+y);
                cout << " ";
                y--;
                if(y<0){
                    y=0;
                }
                break;
            case 15: //dwn
                locate((tcols()/3)-2, 5+y);
                cout << " ";
                y++;
                if(y>6){
                    y=6;
                }
                break;
        case 1: /// 1 = ENTER
            switch(y){
            case 0:
                cls();
                cargarAcceso();
                break;
            case 1:
                cls();
                mostrarAcceso();
                break;
            case 2:
                cls();
                filtrarAccesoPorCancion();
                break;
            case 3:
                cls();
                filtrarAccesoPorArtista();
                break;
            case 4:
                cls();
                eliminarAcceso();
                break;
            case 5:
                cls();
                modificarAcceso();
                break;
            case 6:
                cls();
                exit=true;
                break;
            default:
                cls();
                cout << "OPCION INCORRECTA. VUELVA A INGRESAR" << endl;
                cin.get();
                break;
            }
        }

    }
    while(!exit);
}

void ManagerAcceso::cargarAcceso(){
    int idUser, idSong, dia, mes, anio, hora;
    ArchivoCancion archivo("lista de canciones.dat");
    ArchivoSubscriptor archivo2("lista de subscriptores.dat");
    Cancion c;
    Subscriptor s;
    ArchivoAcceso archivo3("lista de accesos");

    int id = archivo3.getNewID();

    cout << "Ingrese el ID del usuario: ";
    cin >> idUser;

    ///FUNCION PARA VER SI EL ID EXISTE
    if (!archivo2.validarID(idUser, s)){
        cout << "El usuario con ID " << idUser << " no existe. No se puede crear el acceso" << endl;
        exit(-1);
    }

    cout << "Ingrese el ID de la cancion: ";
    cin >> idSong;

    ///FUNCION PARA VER SI EL ID EXISTE
    if (!archivo.buscarPorCancionID(idSong, c)){
        cout << "La cancion con ID " << idSong << " no existe. No se puede crear el acceso" << endl;
        exit(-1);
    }

    cout << "Ingrese dia: ";
    cin >> dia;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese dia: ";
            cin >> dia;

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
            }
            else{
                break;
            }
        }
    }
    cout << "Ingrese mes: ";
    cin >> mes;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese mes: ";
            cin >> mes;

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
            }
            else{
                break;
            }
        }
    }
    cout << "Ingrese anio: ";
    cin >> anio;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese anio: ";
            cin >> anio;

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
            }
            else{
                break;
            }
        }
    }
    cout << "Ingrese hora: ";
    cin >> hora;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese hora: ";
            cin >> hora;

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
            }
            else{
                break;
            }
        }
    }
    Acceso reg;
    bool estado = true;
    reg = Acceso(id, idSong, idUser, Fecha(dia,mes,anio), hora, estado);

    if(_archivo.guardarAcceso(reg)){
        cout << "Acceso guardado correctamente" << endl;
    }
    else{
        cout << "ERROR: El acceso no se pudo guardar" << endl;
        exit(-2);
    }
    system("pause");
    cls();
}

void ManagerAcceso::mostrarAcceso(){
    int cantidad = _archivo.getCantidadRegistros();
    Acceso *vectorAcceso;

    vectorAcceso = new Acceso[cantidad];

    if(vectorAcceso==nullptr){
        cout << "Error en la asignacion de memoria" << endl;
        exit(-1);
    }

    _archivo.leerMuchos(vectorAcceso, cantidad);

    for(int i=0; i<cantidad; i++){
        cout << "Acceso de usuario " << vectorAcceso[i].getIdSub() << endl;
        cout << "Cancion " << vectorAcceso[i].getIdSong() << endl;
        cout << "Fecha: " << vectorAcceso[i].getFecha() << " Hora: " << vectorAcceso[i].getHora() << endl;
        cout << "--------------------------------------------" << endl;
    }

    system("pause");
    delete []vectorAcceso;

    cls();
}

void ManagerAcceso::filtrarAccesoPorCancion(){
    std::string nombreCancion;
    Cancion reg;
    ArchivoCancion archivo("lista de canciones.dat");
    ArchivoAcceso archivo2("lista de accesos.dat");
    int cantRegistros = archivo.getCantidadRegistros();
    Acceso regAcceso;

    cout << "Ingrese el nombre de la cancion que desee buscar en los accesos: ";
    cin >> nombreCancion;

    if(!archivo.buscarPorCancionNombre(nombreCancion, reg)){
        cout << "La cancion con nombre " << nombreCancion << " no existe. No se puede crear el acceso" << endl;
        exit(-1);
    }

    int j=0;
    for(int i=0; i<cantRegistros; i++){
        regAcceso = archivo2.Leer(i);

        if(regAcceso.getEstado()){
            if(reg.getNombre()==nombreCancion){
                cout << "Acceso de usuario " << regAcceso.getIdSub() << endl;
                cout << "Cancion " << regAcceso.getIdSong() << endl;
                cout << "Fecha: " <<regAcceso.getFecha() << " Hora: " << regAcceso.getHora() << endl;
                cout << "--------------------------------------------" << endl;
                j++;
            }
        }
    }

    if(j==0){
        cout << "No se encontraron accesos a la cancion indicada" << endl;
    }

    system("pause");
    cls();
}

void ManagerAcceso::filtrarAccesoPorArtista(){
    std::string nombreArtista;
    Artista reg;
    ArchivoArtista archivo("lista de canciones.dat");
    ArchivoAcceso archivo2("lista de accesos.dat");
    int cantRegistros = archivo.getCantidadRegistros();
    Acceso regAcceso;

    cout << "Ingrese el artista de la cancion que desee buscar en los accesos: ";
    cin >> nombreArtista;

    if(!archivo.validarNombreArtista(nombreArtista, reg)){
        cout << "La cancion con nombre " << nombreArtista << " no existe. No se puede crear el acceso" << endl;
        exit(-1);
    }

    int j=0;
    for(int i=0; i<cantRegistros; i++){
        regAcceso = archivo2.Leer(i);

        if(regAcceso.getEstado()){
            if(reg.getNombre()==nombreArtista){
                cout << "Acceso de usuario " << regAcceso.getIdSub() << endl;
                cout << "Cancion " << regAcceso.getIdSong() << endl;
                cout << "Fecha: " <<regAcceso.getFecha() << " Hora: " << regAcceso.getHora() << endl;
                cout << "--------------------------------------------" << endl;
                j++;
            }
        }
    }

    if(j==0){
        cout << "No se encontraron accesos con el artista indicado" << endl;
    }

    system("pause");
    cls();
}

void ManagerAcceso::eliminarAcceso(){
    int idSearch;
    ArchivoAcceso archivo("lista de accesos.dat");
    Acceso reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID del acceso que desee dar de baja: ";
    cin >> idSearch;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese el ID del acceso que desee dar de baja: ";
            cin >> idSearch;

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
            }
            else{
                break;
            }
        }
    }

    if (!archivo.validarID(idSearch, reg)){
        cout << "El usuario con ID " << idSearch << " no existe." << endl;
        exit(-1);
    }

    reg = archivo.Leer(idSearch-1);
    reg.setEstado(false);
    archivo.guardarAcceso(reg, idSearch-1);

    system("pause");
}

void ManagerAcceso::modificarAcceso(){
    int idSearch;
    ArchivoAcceso archivo("lista de accesos.dat");
    ArchivoCancion archivo2("lista de cancion.dat");
    ArchivoSubscriptor archivo3("lista de subscriptores.dat");

    Acceso reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID del acceso que desee dar de baja: ";
    cin >> idSearch;

    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese el ID del acceso que desee dar de baja: ";
            cin >> idSearch;

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
            }
            else{
                break;
            }
        }
    }

    if (!archivo.validarID(idSearch, reg)){
        cout << "El acceso con ID " << idSearch << " no existe." << endl;
        exit(-1);
    }

    int idCancion;
    int dia, mes, anio;
    reg = archivo.Leer(idSearch-1);

    int id = idSearch;
    cout << "ID acceso: " << id << endl;

    Acceso reg2;

    cout << "Ingrese nombre de la cancion: ";
    cin >> idCancion;

    Cancion c;
    if(!archivo2.buscarPorCancionID(idCancion, c)){
        cout << "La cancion con nombre " << idCancion << " no existe." << endl;
        exit(-1);
    }
    reg.setIdSong(idCancion);
    int idSubscriptor;
    cout << "Ingrese ID del subscriptor: ";
    cin >> idSubscriptor;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese ID del subscriptor: ";
            cin >> idSubscriptor;

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
            }
            else{
                break;
            }
        }
    }
    Subscriptor s;
    if(!archivo3.validarID(idSubscriptor, s)){
        cout << "El Usuario con ID " << idSubscriptor << " no existe." << endl;
        exit(-1);
    }
    reg.setIdSub(idSubscriptor);
    cout << "Ingrese dia: ";
    cin >> dia;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese dia: ";
            cin >> dia;

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
            }
            else{
                break;
            }
        }
    }
    cout << "Ingrese mes: ";
    cin >> mes;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese mes: ";
            cin >> mes;

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
            }
            else{
                break;
            }
        }
    }
    cout << "Ingrese anio: ";
    cin >> anio;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese anio: ";
            cin >> anio;

            if(std::cin.fail()){
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
            }
            else{
                break;
            }
        }
    }
    reg.setFecha(Fecha(dia,mes,anio));
    bool estado = true;
    reg.setEstado(estado);

    archivo.guardarAcceso(reg, idSearch-1);

    system("pause");
}

