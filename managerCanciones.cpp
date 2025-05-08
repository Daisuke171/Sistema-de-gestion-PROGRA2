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
        locate(tcols()/3,3);
        cout << "*****MENU CANCIONES*****" << endl;
        locate(tcols()/3,4);
        cout << "------------------------" << endl;
        locate(tcols()/3,5);
        cout << "1- Cargar Cancion" << endl;
        locate(tcols()/3,6);
        cout << "2- Mostrar Cancion" << endl;
        locate(tcols()/3,7);
        cout << "0- Volver atras" << endl;
        locate(tcols()/3,8);
        cout << "------------------------" << endl;
        locate(tcols()/3,11);
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
                if(y>2){
                    y=2;
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

    reg = Cancion(id, nombre, autor, interprete, Fecha(dia,mes,anio));

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
