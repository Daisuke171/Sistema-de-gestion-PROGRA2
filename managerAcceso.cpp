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
#include "arrayUtils.h"
using namespace rlutil;

void ManagerHistorial::mostrarSubmenuHistorial(){
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
        cout << "Velvet Note Register" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "------------------------" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "1- Cargar Historial" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "2- Mostrar Historial" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "3- Eliminar Historial" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "4- Modificar Historial" << endl;
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
                if(y>4){
                    y=4;
                }
                break;
        case 1: /// 1 = ENTER
            switch(y){
            case 0:
                cls();
                cargarHistorial();
                break;
            case 1:
                cls();
                mostrarHistorial();
                break;
            case 2:
                cls();
                eliminarHistorial();
                break;
            case 3:
                cls();
                modificarHistorial();
                break;
            case 4:
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

void ManagerHistorial::cargarHistorial(){
    fflush(stdin);
    cin.clear();
    int idUser, idSong, dia, mes, anio, hora;
    ArchivoCancion archivo("lista de canciones.dat");
    ArchivoSubscriptor archivo2("lista de subscriptores.dat");
    Cancion c;
    Subscriptor s;
    ArchivoHistorial archivo3("lista de accesos.dat");

    int id = archivo3.getNewID();

    cout << "Ingrese el ID del usuario: ";
    cin >> idUser;

    ///FUNCION PARA VER SI EL ID EXISTE
    if (!archivo2.validarID(idUser, s)){
        cout << "El usuario con ID " << idUser << " no existe. No se puede crear el acceso" << endl;
        system("pause");
        return;
    }

    cout << "Ingrese el ID de la cancion: ";
    cin >> idSong;

    ///FUNCION PARA VER SI EL ID EXISTE
    if (!archivo.buscarPorCancionID(idSong, c)){
        cout << "La cancion con ID " << idSong << " no existe. No se puede crear el acceso" << endl;
        system("pause");
        return;
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
    HistorialUsuario reg;
    bool estado = true;
    reg = HistorialUsuario(id, idSong, idUser, Fecha(dia,mes,anio), hora, estado);

    if(_archivo.guardarHistorial(reg)){
        cout << "Historial guardado correctamente" << endl;
        system("pause");
    }
    else{
        cout << "ERROR: El historial no se pudo guardar" << endl;
        system("pause");
        return;
    }

    cls();
    fflush(stdin);
}

void ManagerHistorial::mostrarHistorial(){
    fflush(stdin);
    int cantidad = _archivo.getCantidadRegistros();
    HistorialUsuario *vectorHistorial;
    vectorHistorial = new HistorialUsuario[cantidad];

    ArchivoSubscriptor archivo("lista de subscriptores.dat");
    Subscriptor regSub;
    ArchivoCancion archivo2("lista de canciones.dat");
    Cancion regCancion;

    if(vectorHistorial==nullptr){
        cout << "Error en la asignacion de memoria" << endl;
        exit(-1);
    }

    _archivo.leerMuchos(vectorHistorial, cantidad);



    int key;
    bool exit = false;
    int y=0;
    hidecursor();

    do{
        system("cls");
        int i=3;
        locate(tcols()/3,i);
        i++;
        cout << "Velvet Note Show" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "1- Por ID" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "2- Por Usuario" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3- Por Fecha" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4- Volver Atras" << endl;
        locate(tcols()/3,i);
        i++;

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
                if(y>3){
                    y=3;
                }
                break;
        case 1: /// 1 = ENTER
            switch(y){
            case 0:
                //POR ID DEFAULT
                for(int i=0; i<cantidad; i++){
                    regSub = archivo.Leer(vectorHistorial[i].getIdSub()-1);
                    regCancion = archivo2.Leer(vectorHistorial[i].getIdSong()-1);
                    cout << "ID HISTORIAL: " << vectorHistorial[i].getID() << endl;
                    cout << "Historial de usuario #" << vectorHistorial[i].getIdSub() << ": "  << regSub.getNombre() << " " << regSub.getApellido() << endl;
                    cout << "Cancion #" << vectorHistorial[i].getIdSong() << ": " << regCancion.getNombre() << endl;
                    cout << "Banda: " << regCancion.getAutor() << endl;
                    cout << "Fecha: " << vectorHistorial[i].getFecha() << " Hora: " << vectorHistorial[i].getHora() << endl;
                    std::string fecha = vectorHistorial[i].getFecha();
                    cout << "--------------------------------------------" << endl;
                }
                system("pause");
                break;
            case 1:
                _archivo.ordenarHistorialPorUsuario(vectorHistorial, cantidad);
                for(int i=0; i<cantidad; i++){
                    regSub = archivo.Leer(vectorHistorial[i].getIdSub()-1);
                    regCancion = archivo2.Leer(vectorHistorial[i].getIdSong()-1);
                    cout << "ID HISTORIAL: " << vectorHistorial[i].getID() << endl;
                    cout << "Historial de usuario #" << vectorHistorial[i].getIdSub() << ": "  << regSub.getNombre() << " " << regSub.getApellido() << endl;
                    cout << "Cancion #" << vectorHistorial[i].getIdSong() << ": " << regCancion.getNombre() << endl;
                    cout << "Banda: " << regCancion.getAutor() << endl;
                    cout << "Fecha: " << vectorHistorial[i].getFecha() << " Hora: " << vectorHistorial[i].getHora() << endl;
                    std::string fecha = vectorHistorial[i].getFecha();
                    cout << "--------------------------------------------" << endl;
                }
                system("pause");
                break;
            case 2:
                _archivo.ordenarHistorialPorFecha(vectorHistorial, cantidad);
                for(int i=0; i<cantidad; i++){
                    regSub = archivo.Leer(vectorHistorial[i].getIdSub()-1);
                    regCancion = archivo2.Leer(vectorHistorial[i].getIdSong()-1);
                    cout << "ID HISTORIAL: " << vectorHistorial[i].getID() << endl;
                    cout << "Historial de usuario #" << vectorHistorial[i].getIdSub() << ": "  << regSub.getNombre() << " " << regSub.getApellido() << endl;
                    cout << "Cancion #" << vectorHistorial[i].getIdSong() << ": " << regCancion.getNombre() << endl;
                    cout << "Banda: " << regCancion.getAutor() << endl;
                    cout << "Fecha: " << vectorHistorial[i].getFecha() << " Hora: " << vectorHistorial[i].getHora() << endl;
                    std::string fecha = vectorHistorial[i].getFecha();
                    cout << "--------------------------------------------" << endl;
                }
                system("pause");
                break;
            case 3:
                exit=true;
                break;
            default:
                cls();
                cout << "OPCION INCORRECTA. VUELVA A INGRESAR" << endl;
                system("pause");
                break;
            }
        }
    }
    while(!exit);


    delete []vectorHistorial;

    cls();
    fflush(stdin);
}

void ManagerHistorial::eliminarHistorial(){
    fflush(stdin);
    int idSearch;
    ArchivoHistorial archivo("lista de accesos.dat");
    HistorialUsuario reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID del historial que desee dar de baja: ";
    cin >> idSearch;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese el ID del historial que desee dar de baja: ";
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
        system("pause");
        return;
    }

    reg = archivo.Leer(idSearch-1);
    reg.setEstado(false);
    archivo.guardarHistorial(reg, idSearch-1);

    system("pause");
    fflush(stdin);
}

void ManagerHistorial::modificarHistorial(){
    fflush(stdin);
    int idSearch;
    ArchivoHistorial archivo("lista de accesos.dat");
    ArchivoCancion archivo2("lista de cancion.dat");
    ArchivoSubscriptor archivo3("lista de subscriptores.dat");

    HistorialUsuario reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID del historial que desee dar de baja: ";
    cin >> idSearch;

    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese el ID del historial que desee dar de baja: ";
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
        system("pause");
        return;
    }

    int idCancion;
    int dia, mes, anio;
    reg = archivo.Leer(idSearch-1);

    int id = idSearch;
    cout << "ID acceso: " << id << endl;

    HistorialUsuario reg2;

    cout << "Ingrese nombre de la cancion: ";
    cin >> idCancion;

    Cancion c;
    if(!archivo2.buscarPorCancionID(idCancion, c)){
        cout << "La cancion con nombre " << idCancion << " no existe." << endl;
        system("pause");
        return;
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
        system("pause");
        return;
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

    archivo.guardarHistorial(reg, idSearch-1);

    system("pause");
    fflush(stdin);
}

