#include <iostream>
#include <cstring>
#include "cancion.h"
#include "managerCanciones.h"
#include "fecha.h"
#include "rlutils.h"
#include "archivosCancion.h"
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
        cout << "Velvet Note Cancion" << endl;
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
    Cancion reg;

    int id;
    string nombre, autor, interprete;
    int dia, mes, anio;

    id = _archivo.getNewID();
    cout << "ID Cancion: " << id << endl;

    cin.ignore();
    cout << "Ingrese nombre de la cancion: ";
    getline(cin, nombre);
    cout << "Ingrese nombre del autor: ";
    getline(cin, autor);
    cout << "Ingrese nombre del interprete: ";
    getline(cin, interprete);
    cout << "Ingrese dia de publicacion: ";
    cin >> dia;
    cout << "Ingrese mes de publicacion: ";
    cin >> mes;
    cout << "Ingrese anio de publicacion: ";
    cin >> anio;

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
}

void ManagerCanciones::mostrarCancion(){
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
        cout << "Autor: " << vectorCanciones[i].getAutor() << '\t';
        cout << " | Interprete: " << vectorCanciones[i].getInterprete() << endl;
        cout << "Fecha de publicacion: " << vectorCanciones[i].getFechaPublicacion() << endl;
        cout << "--------------------------------------------" << endl;
    }

    system("pause");
    delete []vectorCanciones;

    cls();
}

void ManagerCanciones::buscarCancion(){
    int idSearch;
    ArchivoCancion archivo("lista de subscriptores.dat");
    Cancion reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID que desea buscar: ";
    cin >> idSearch;

    if (!archivo.validarID(idSearch, reg)){
        cout << "La cancion con ID " << idSearch << " no existe." << endl;
        exit(-1);
    }

    int posicion=0;
    bool found = false;
    for(int i=0; i<cantRegistros; i++){
        reg = archivo.Leer(i);

        if(reg.getID()==idSearch){
            if(reg.getEstado()==false){
                cout << "La cancion fue dada de baja" << endl;
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
}

void ManagerCanciones::eliminarCancion(){
    int idSearch;
    ArchivoCancion archivo("lista de subscriptores.dat");
    Cancion reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID del subscriptor que desee dar de baja: ";
    cin >> idSearch;

    if (!archivo.validarID(idSearch, reg)){
        cout << "La cancion con ID " << idSearch << " no existe." << endl;
        exit(-1);
    }

    reg = archivo.Leer(idSearch-1);
    reg.setEstado(false);
    archivo.guardarCancion(reg, idSearch-1);

    system("pause");
}

void ManagerCanciones::modificarCancion(){
   int idSearch;
    ArchivoCancion archivo("lista de subscriptores.dat");
    Cancion reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID del subscriptor que desee modificar: ";
    cin >> idSearch;

    if (!archivo.validarID(idSearch, reg)){
        cout << "La cancion con ID " << idSearch << " no existe." << endl;
        exit(-1);
    }

    string nombre, autor, interprete;
    int dia, mes, anio;


    cout << "ID Cancion: " << idSearch << endl;

    cin.ignore();
    cout << "Ingrese nombre de la cancion: ";
    getline(cin, nombre);
    reg.setNombre(nombre);
    cout << "Ingrese nombre del autor: ";
    getline(cin, autor);
    reg.setAutor(autor);
    cout << "Ingrese nombre del interprete: ";
    getline(cin, interprete);
    reg.setInterprete(interprete);
    cout << "Ingrese dia de publicacion: ";
    cin >> dia;
    cout << "Ingrese mes de publicacion: ";
    cin >> mes;
    cout << "Ingrese anio de publicacion: ";
    cin >> anio;
    reg.setFechaPublicacion(Fecha(dia,mes,anio));
    bool estado = true;
    reg.setEstado(estado);

    archivo.guardarCancion(reg, idSearch);


    system("pause");
}
