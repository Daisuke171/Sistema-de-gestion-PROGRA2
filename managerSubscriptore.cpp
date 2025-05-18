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
        int i=3;
        locate(tcols()/3,i);
        i++;
        cout << "*****MENU SUSCRIPTORES*****" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "1- Cargar Subscriptor" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "2- Mostrar Subscriptores" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3- Buscar Subscriptor" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4- Dar de baja Subscriptor" << endl;
        locate(tcols()/3,i+2);
        i++;
        cout << "0- Volver atras" << endl;
        locate(tcols()/3,i+2);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i+3);
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
                cargarSubscriptor();
                break;
            case 1:
                cls();
                mostrarSubscriptores();
                break;
            case 2:
                cls();
                buscarSubscriptor();
                break;
            case 3:
                cls();
                eliminarSubscriptor();
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

    bool estado = true;

    reg = Subscriptor(id, dni, nombre, apellido, telefono, email, Fecha(dia,mes,anio), estado);

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
        cout << "Subscriptor ID:" << vectorSubscriptores[i].getIDSub() << " info" << endl;
        cout << vectorSubscriptores[i].getNombre() << " " << vectorSubscriptores[i].getApellido() << endl;
        cout << "Fecha de alta: " << vectorSubscriptores[i].getFechaAlta() << endl;
        cout << "DNI: " << vectorSubscriptores[i].getDni() << endl;
        cout << "Email: " << vectorSubscriptores[i].getEmail() << endl;
        cout << "Telefono: " << vectorSubscriptores[i].getTelefono() << endl;
        cout << "--------------------------------------------" << endl;
    }

    system("pause");
    delete []vectorSubscriptores;

    cls();
}

void ManagerSubscriptores::buscarSubscriptor(){
    int idSearch;
    ArchivoSubscriptor archivo("lista de subscriptores.dat");
    Subscriptor reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID que desea buscar: ";
    cin >> idSearch;

    if (!archivo.validarID(idSearch, reg)){
        cout << "El usuario con ID " << idSearch << " no existe. No se puede crear el acceso" << endl;
        exit(-1);
    }

    int posicion=0;
    bool found = false;
    for(int i=0; i<cantRegistros; i++){
        reg = archivo.Leer(i);

        if(reg.getIDSub()==idSearch){
            cout << "Subscriptor ID:" << reg.getIDSub() << " info" << endl;
            cout << reg.getNombre() << " " << reg.getApellido() << endl;
            cout << "Fecha de alta: " << reg.getFechaAlta() << endl;
            cout << "DNI: " << reg.getDni() << endl;
            cout << "Email: " << reg.getEmail() << endl;
            cout << "Telefono: " << reg.getTelefono() << endl;
            cout << "--------------------------------------------" << endl;
            found=true;
        }
        if(found) break;
    }




    system("pause");
    cls();
}

void ManagerSubscriptores::eliminarSubscriptor(){
    int idSearch;
    ArchivoSubscriptor archivo("lista de subscriptores.dat");
    Subscriptor reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID del subscriptor que desee dar de baja: ";
    cin >> idSearch;

    if (!archivo.validarID(idSearch, reg)){
        cout << "El usuario con ID " << idSearch << " no existe. No se puede crear el acceso" << endl;
        exit(-1);
    }





    system("pause");
}
