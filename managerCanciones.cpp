#include <iostream>
#include <cstring>
#include "cancion.h"
#include "managerCanciones.h"
#include "fecha.h"
#include "rlutils.h"
#include "archivosCancion.h"
#include "archivoArtista.h"
#include "managerArtista.h"
using namespace std;
using namespace rlutil;


void ManagerCanciones::mostrarSubmenuCanciones(){
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
        i++;
        cout << "Velvet Note Songs" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "1- Cargar Cancion" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "2- Mostrar Canciones" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3- Buscar Cancion" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4- Dar de baja Cancion" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "5- Editar Cancion" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "0- Volver atras" << endl;
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
                if(y>5){
                    y=5;
                }
                break;
        case 1: /// 1 = ENTER
            switch(y){
            case 0:
                cls();
                cargarCancion();
                break;
            case 1:
                cls();
                mostrarCancion();
                break;
            case 2:
                cls();
                buscarCancion();
                break;
            case 3:
                cls();
                eliminarCancion();
                break;
            case 4:
                cls();
                modificarCancion();
                break;
            case 5:
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

void ManagerCanciones::cargarCancion(){
    fflush(stdin);
    Cancion reg;

    Artista regArtistas;
    ManagerArtista manArtista;
    ArchivoArtista archivoArtistas("lista de artista.dat");

    int id;
    string nombre, autor, interprete;
    int dia, mes, anio;

    id = _archivo.getNewID();
    cout << "ID Cancion: " << id << endl;

    cout << "Ingrese nombre de la cancion: ";
    getline(cin, nombre);
    cout << "Ingrese nombre del autor: ";
    getline(cin, autor);



    if(!archivoArtistas.validarNombreArtista(autor, regArtistas)){
        cout << "El artista no se encuentra en la base de datos. Desea crearlo? (0= no, 1=si)" << endl;
        bool crearArtista = false;
        cin >> crearArtista;
        if(crearArtista){
            manArtista.cargarArtista(autor);
        }
    } else cls();

    ///El if-else de arriba hace un cls() si o si
    cout << "ID Cancion: " << id << endl;
    cout << "Ingrese nombre de la cancion: ";
    cout << nombre << endl;
    cout << "Ingrese nombre del autor: ";
    cout << autor << endl;
    ///El if-else de arriba hace un cls() si o si

    cout << "Ingrese nombre del interprete: ";
    getline(cin, interprete);
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

    bool estado = true;

    reg = Cancion(id, nombre, autor, interprete, Fecha(dia,mes,anio), estado);

    if(_archivo.guardarCancion(reg)){
        cout << "Cancion guardada correctamente" << endl;
    }
    else{
        cout << "ERROR: La cancion no se pudo guardar" << endl;
    }

    system("pause");
    cls();
    fflush(stdin);
}

void ManagerCanciones::mostrarCancion(){
    fflush(stdin);
    int cantidad = _archivo.getCantidadRegistros();
    Cancion *vectorCanciones;

    vectorCanciones = new Cancion[cantidad];

    if(vectorCanciones==nullptr){
        cout << "Error en la asignacion de memoria" << endl;
        exit(-1);
    }

    _archivo.leerMuchos(vectorCanciones, cantidad);

    for(int i=0; i<cantidad; i++){
        cout << "Cancion ID:" << vectorCanciones[i].getID() << " info" << endl;
        cout << "Nombre de la cancion: " << vectorCanciones[i].getNombre() << endl;
        cout << "Autor: " << vectorCanciones[i].getAutor() << '\t';
        cout << " | Interprete: " << vectorCanciones[i].getInterprete() << endl;
        cout << "Fecha de publicacion: " << vectorCanciones[i].getFechaPublicacion() << endl;
        cout << "--------------------------------------------" << endl;
    }

    system("pause");
    delete []vectorCanciones;

    cls();
    fflush(stdin);
}

void ManagerCanciones::buscarCancion(){
    fflush(stdin);
    int idSearch;
    ArchivoCancion archivo("lista de canciones.dat");
    Cancion reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID que desea buscar: ";
    cin >> idSearch;
    if(std::cin.fail()) {
    std::cin.clear();
    std::cin.ignore();
    std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
    while(true){
        cout << "Ingrese el ID que desea buscar: ";
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
        cout << "La cancion con ID " << idSearch << " no existe." << endl;
        system("pause");
        return;
    }

    int posicion=0;
    bool found = false;
    for(int i=0; i<cantRegistros; i++){
        reg = archivo.Leer(i);

        if(reg.getID()==idSearch){
            if(reg.getEstado()==false){
                cout << "La cancion fue dada de baja" << endl;
                system("pause");
                found=true;
            }
            else{
                cout << "Cancion ID:" << reg.getID() << " info" << endl;
                cout << "Autor: " << reg.getAutor() << '\t';
                cout << " | Interprete: " << reg.getInterprete() << endl;
                cout << "Fecha de publicacion: " << reg.getFechaPublicacion() << endl;
                cout << "--------------------------------------------" << endl;
                found=true;
            }
        }
        if(found) break;
    }




    system("pause");
    cls();
    fflush(stdin);
}

void ManagerCanciones::eliminarCancion(){
    fflush(stdin);
    int idSearch;
    ArchivoCancion archivo("lista de subscriptores.dat");
    Cancion reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID del subscriptor que desee dar de baja: ";
    cin >> idSearch;

    if (!archivo.validarID(idSearch, reg)){
        cout << "La cancion con ID " << idSearch << " no existe." << endl;
        system("pause");
        return;
    }

    reg = archivo.Leer(idSearch-1);
    reg.setEstado(false);
    archivo.guardarCancion(reg, idSearch-1);

    system("pause");
    fflush(stdin);
}

void ManagerCanciones::modificarCancion(){
    fflush(stdin);
    int idSearch;
    ArchivoCancion archivo("lista de canciones.dat");
    ArchivoArtista archivo2("lista de artista.dat");
    Cancion reg;
    Artista reg2;
    ManagerArtista manArtista;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID de la cancion que desee modificar: ";
    cin >> idSearch;

    if (!archivo.validarID(idSearch, reg)){
        cout << "La cancion con ID " << idSearch << " no existe." << endl;
        system("pause");
        return;
    }

    string nombre, autor, interprete;
    int dia, mes, anio;

    cout << "ID Cancion: " << idSearch << endl;

    int option;
    cout << "Ingrese que quiere modificar: " << endl;
    cout << "1- Nombre" << endl;
    cout << "2- Autor" << endl;
    cout << "3- Interprete" << endl;
    cout << "4- Fecha" << endl;
    cin >> option;
    switch(option){
    case 1:
        {
            cin.ignore();
            cout << "Ingrese nombre de la cancion: ";
            getline(cin, nombre);
            reg.setNombre(nombre);
            break;
        }
    case 2:
        {
            cin.ignore();
            cout << "Ingrese nombre del autor: ";
            getline(cin, autor);

            if(!archivo2.validarNombreArtista(autor, reg2)){
                cout << "El artista no se encuentra en la base de datos. Desea crearlo? (0= no, 1=si)" << endl;
                bool crearArtista = false;
                cin >> crearArtista;
                if(crearArtista){
                    manArtista.cargarArtista(autor);
                }
            }
            reg.setAutor(autor);
            break;
        }
    case 3:
        {
            cin.ignore();
            cout << "Ingrese nombre del interprete: ";
            getline(cin, interprete);
            reg.setInterprete(interprete);
            break;
        }
    case 4:
        {
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
            reg.setFechaPublicacion(Fecha(dia,mes,anio));
            break;
        }
    default:
        break;
    }

    archivo.guardarCancion(reg, idSearch);

    system("pause");
    fflush(stdin);
}
