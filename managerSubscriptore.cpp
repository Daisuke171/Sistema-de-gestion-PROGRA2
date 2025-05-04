#include "fecha.h"
#include "suscriptor.h"
#include "managerSubscriptore.h"
#include <iostream>
#include <cstring>
#include "rlutils.h"
using namespace std;
using namespace rlutil;

void ManagerSubscriptores::mostrarSubmenuSubs(){
    int key;
    setBackgroundColor(MAGENTA);
    setColor(WHITE);
    bool exit = false;
    int y=0;
    hidecursor();

    do{
        system("cls");
        locate(tcols()/3,3);
        cout << "*****MENU SUSCRIPTORES*****" << endl;
        locate(tcols()/3,4);
        cout << "------------------------" << endl;
        locate(tcols()/3,5);
        cout << "1- Cargar Subscriptor" << endl;
        locate(tcols()/3,6);
        cout << "2- Mostrar Subscriptores" << endl;
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
                cargarSubscriptor();
                break;
            case 1:
                cls();
                mostrarSubscriptores();
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

void ManagerSubscriptores::cargarSubscriptor(){
    Subscriptor reg;

    int id, dni;
    string nombre, apellido, telefono, email;
    int dia, mes, anio;

    id = _archivo.getNewID();
    cout << "ID Subscriptor: " << id << endl;

    cout << "Ingrese DNI: ";
    cin >> dni;

    cout << "Ingrese nombre: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese apellido: ";
    getline(cin, apellido);

    cout << "Ingrese telefono: ";
    getline(cin, telefono);

    cout << "Ingrese email: ";
    getline(cin, email);

    cout << "Ingrese dia de nacimiento: ";
    cin >> dia;
    cout << "Ingrese mes de nacimiento: ";
    cin >> mes;
    cout << "Ingrese anio de nacimiento: ";
    cin >> anio;

    reg = Subscriptor(id, dni, nombre, apellido, telefono, email, Fecha(dia,mes,anio));

    if(_archivo.guardarSubscriptor(reg)){
        cout << "Subscriptor guardado correctamente" << endl;
    }
    else{
        cout << "ERROR: El subscriptor no se pudo guardar" << endl;

    }
    system("pause");
    cls();
}

void ManagerSubscriptores::mostrarSubscriptores(){
    int cantidad = _archivo.getCantidadRegistros();
    Subscriptor *vectorSubscriptores;

    vectorSubscriptores = new Subscriptor[cantidad];

    if(vectorSubscriptores==nullptr){
        cout << "Error en la asignacion de memoria" << endl;
        exit(-1);
    }

    _archivo.leerMuchos(vectorSubscriptores, cantidad);

    for(int i=0; i<cantidad; i++){
        cout << "Subscriptor ID:" << vectorSubscriptores[i].getId() << " info" << endl;
        cout << vectorSubscriptores[i].getNombre() << " " << vectorSubscriptores[i].getApellido() << endl;
        cout << "Fecha de nacimiento: " << vectorSubscriptores[i].getFechaNacimiento() << endl;
        cout << "DNI: " << vectorSubscriptores[i].getDni() << endl;
        cout << "Email: " << vectorSubscriptores[i].getEmail() << endl;
        cout << "Telefono: " << vectorSubscriptores[i].getTelefono() << endl;
        cout << "--------------------------------------------" << endl;
    }

    system("pause");
    delete []vectorSubscriptores;

    cls();
}
