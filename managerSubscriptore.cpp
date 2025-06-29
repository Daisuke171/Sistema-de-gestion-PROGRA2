#include "fecha.h"
#include "suscriptor.h"
#include "managerSubscriptore.h"
#include <iostream>
#include <cstring>
#include "rlutils.h"
#include "userAccess.h"
#include "arrayUtils.h"
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
        cout << "Velvet Note Subscriptor" << endl;
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
        locate(tcols()/3,i);
        i++;
        cout << "5- Editar subscriptor" << endl;
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
            case 4:
                cls();
                modificarSubscriptor();
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
    fflush(stdin);
    Subscriptor reg;

    int id;
    string nombre, apellido, telefono, email, dni;
    int dia, mes, anio;

    id = _archivo.getNewID();
    cout << "ID Subscriptor: " << id << endl;

    cout << "Ingrese DNI: ";
    getline(cin, dni);

    bool yaExiste = _archivo.validarDNI(dni);
    if(yaExiste){
        cout << "El DNI ya existe" << endl;
        system("pause>null");
        return;
    }

    cout << "Ingrese nombre: ";
    getline(cin, nombre);

    cout << "Ingrese apellido: ";
    getline(cin, apellido);

    cout << "Ingrese telefono: ";
    getline(cin, telefono);

    cout << "Ingrese email: ";
    getline(cin, email);

    cout << "Ingrese dia de nacimiento: ";
    cin >> dia;
    if(cin.fail()){
        cin.clear();
        cout << "Error: No se ingreso un numero" << endl;
        system("pause>null");
        fflush(stdin);
        return;
    }

    cout << "Ingrese mes de nacimiento: ";
    cin >> mes;
    if(cin.fail()){
        cin.clear();
        cout << "Error: No se ingreso un numero" << endl;
        system("pause>null");
        fflush(stdin);
        return;
    }

    cout << "Ingrese anio de nacimiento: ";
    cin >> anio;
    if(cin.fail()){
        cin.clear();
        cout << "Error: No se ingreso un numero" << endl;
        system("pause>null");
        fflush(stdin);
        return;
    }

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
    fflush(stdin);
}

void ManagerSubscriptores::mostrarSubscriptores(){
    fflush(stdin);
    cin.clear();
    int cantidad = _archivo.getCantidadRegistros();
    Subscriptor *vectorSubscriptores;

    vectorSubscriptores = new Subscriptor[cantidad];

    if(vectorSubscriptores==nullptr){
        cout << "Error en la asignacion de memoria" << endl;
        exit(-1);
    }

    _archivo.leerMuchos(vectorSubscriptores, cantidad);
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
        cout << "2- Por DNI" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3- Por Nombre" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4- Por Apellido" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "0- Volver Atras" << endl;
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
                if(y>4){
                    y=4;
                }
                break;
        case 1: /// 1 = ENTER
            switch(y){
            case 0:
                //POR ID DEFAULT
                cls();
                _archivo.ordenarDefaultID(vectorSubscriptores, cantidad);
                for(int i=0; i<cantidad; i++){
                    if(vectorSubscriptores[i].getEstado()){
                        cout << "Subscriptor ID:" << vectorSubscriptores[i].getIDSub() << " info" << endl;
                        cout << vectorSubscriptores[i].getNombre() << " " << vectorSubscriptores[i].getApellido() << endl;
                        cout << "Fecha de nacimiento: " << vectorSubscriptores[i].getFechaNacimiento() << endl;
                        cout << "DNI: " << vectorSubscriptores[i].getDni() << endl;
                        cout << "Email: " << vectorSubscriptores[i].getEmail() << endl;
                        cout << "Telefono: " << vectorSubscriptores[i].getTelefono() << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                }
                system("pause");
                break;
            case 1:
                cls();
                _archivo.ordenarSubscriptoresPorDNI(vectorSubscriptores, cantidad);
                for(int i=0; i<cantidad; i++){
                    if(vectorSubscriptores[i].getEstado()){
                        cout << "Subscriptor ID:" << vectorSubscriptores[i].getIDSub() << " info" << endl;
                        cout << vectorSubscriptores[i].getNombre() << " " << vectorSubscriptores[i].getApellido() << endl;
                        cout << "Fecha de nacimiento: " << vectorSubscriptores[i].getFechaNacimiento() << endl;
                        cout << "DNI: " << vectorSubscriptores[i].getDni() << endl;
                        cout << "Email: " << vectorSubscriptores[i].getEmail() << endl;
                        cout << "Telefono: " << vectorSubscriptores[i].getTelefono() << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                }
                system("pause");
                break;
            case 2:
                cls();
                _archivo.ordenarSubscriptoresPorNombre(vectorSubscriptores, cantidad);
                for(int i=0; i<cantidad; i++){
                    if(vectorSubscriptores[i].getEstado()){
                        cout << "Subscriptor ID:" << vectorSubscriptores[i].getIDSub() << " info" << endl;
                        cout << vectorSubscriptores[i].getNombre() << " " << vectorSubscriptores[i].getApellido() << endl;
                        cout << "Fecha de nacimiento: " << vectorSubscriptores[i].getFechaNacimiento() << endl;
                        cout << "DNI: " << vectorSubscriptores[i].getDni() << endl;
                        cout << "Email: " << vectorSubscriptores[i].getEmail() << endl;
                        cout << "Telefono: " << vectorSubscriptores[i].getTelefono() << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                }
                system("pause");
                break;
            case 3:
                cls();
                _archivo.ordenarSubscriptoresPorApellido(vectorSubscriptores, cantidad);
                for(int i=0; i<cantidad; i++){
                    if(vectorSubscriptores[i].getEstado()){
                        cout << "Subscriptor ID:" << vectorSubscriptores[i].getIDSub() << " info" << endl;
                        cout << vectorSubscriptores[i].getNombre() << " " << vectorSubscriptores[i].getApellido() << endl;
                        cout << "Fecha de nacimiento: " << vectorSubscriptores[i].getFechaNacimiento() << endl;
                        cout << "DNI: " << vectorSubscriptores[i].getDni() << endl;
                        cout << "Email: " << vectorSubscriptores[i].getEmail() << endl;
                        cout << "Telefono: " << vectorSubscriptores[i].getTelefono() << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                }
                system("pause");
                break;
            case 4:
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


    delete []vectorSubscriptores;

    cls();
    fflush(stdin);
}

void ManagerSubscriptores::buscarSubscriptor(){
    fflush(stdin);
    cin.clear();
    int idSearch;
    ArchivoSubscriptor archivo("lista de subscriptores.dat");
    Subscriptor reg;
    int cantidad = archivo.getCantidadRegistros();

    int key;
    bool exit = false;
    int y=0;
    hidecursor();

    Subscriptor *vectorSubscriptores = new Subscriptor[cantidad];
    if(vectorSubscriptores==nullptr){
        cout << "Error en la asignacion de memoria" << endl;
        return;
    }
    archivo.leerMuchos(vectorSubscriptores, cantidad);

    do{
        system("cls");
        int i=3;
        locate(tcols()/3,i);
        i++;
        cout << "Velvet Note Search" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "1- Por nombre" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "2- Por apellido" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3- Por ID" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4- Por DNI" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "5- Por email" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "6- Por anio de nacimiento" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "0- Volver Atras" << endl;
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
                if(y>6){
                    y=6;
                }
                break;
        case 1: /// 1 = ENTER
            switch(y){
            case 0:
                {
                cls();
                std::string searchSTR;
                cout << "Ingrese el nombre del subscriptor que desea buscar: ";
                getline(cin, searchSTR);
                cout << endl;
                for(int i=0; i<cantidad; i++){
                    if(toLowerCase(searchSTR)==toLowerCase(vectorSubscriptores[i].getNombre())){
                        cout << "Subscriptor ID:" << vectorSubscriptores[i].getIDSub() << " info" << endl;
                        cout << vectorSubscriptores[i].getNombre() << " " << vectorSubscriptores[i].getApellido() << endl;
                        cout << "Fecha de nacimiento: " << vectorSubscriptores[i].getFechaNacimiento() << endl;
                        cout << "DNI: " << vectorSubscriptores[i].getDni() << endl;
                        cout << "Email: " << vectorSubscriptores[i].getEmail() << endl;
                        cout << "Telefono: " << vectorSubscriptores[i].getTelefono() << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                }
                fflush(stdin);
                cin.clear();
                system("pause");
                break;
                }
            case 1:
                {
                cls();
                std::string searchSTR;
                cout << "Ingrese el apellido del subscriptor que desea buscar: ";
                cin >> searchSTR;
                cout << endl;
                for(int i=0; i<cantidad; i++){
                    if(toLowerCase(searchSTR)==toLowerCase(vectorSubscriptores[i].getApellido())){
                        cout << "Subscriptor ID:" << vectorSubscriptores[i].getIDSub() << " info" << endl;
                        cout << vectorSubscriptores[i].getNombre() << " " << vectorSubscriptores[i].getApellido() << endl;
                        cout << "Fecha de nacimiento: " << vectorSubscriptores[i].getFechaNacimiento() << endl;
                        cout << "DNI: " << vectorSubscriptores[i].getDni() << endl;
                        cout << "Email: " << vectorSubscriptores[i].getEmail() << endl;
                        cout << "Telefono: " << vectorSubscriptores[i].getTelefono() << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                }
                fflush(stdin);
                cin.clear();
                system("pause");
                break;
                }
            case 2:
                {
                cls();
                int searchINT;
                cout << "Ingrese el ID del subscriptor que desee buscar: ";
                cin >> searchINT;
                cout << endl;
                for(int i=0; i<cantidad; i++){
                    if(searchINT == vectorSubscriptores[i].getIDSub()){
                        cout << "Subscriptor ID:" << vectorSubscriptores[i].getIDSub() << " info" << endl;
                        cout << vectorSubscriptores[i].getNombre() << " " << vectorSubscriptores[i].getApellido() << endl;
                        cout << "Fecha de nacimiento: " << vectorSubscriptores[i].getFechaNacimiento() << endl;
                        cout << "DNI: " << vectorSubscriptores[i].getDni() << endl;
                        cout << "Email: " << vectorSubscriptores[i].getEmail() << endl;
                        cout << "Telefono: " << vectorSubscriptores[i].getTelefono() << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                }
                fflush(stdin);
                cin.clear();
                system("pause");
                break;
                }
            case 3:
                {
                cls();
                std::string searchSTR;
                cout << "Ingrese el DNI del subscriptor que desea buscar: ";
                getline(cin, searchSTR);
                cout << endl;
                for(int i=0; i<cantidad; i++){
                    if(toLowerCase(searchSTR)==toLowerCase(vectorSubscriptores[i].getDni())){
                        cout << "Subscriptor ID:" << vectorSubscriptores[i].getIDSub() << " info" << endl;
                        cout << vectorSubscriptores[i].getNombre() << " " << vectorSubscriptores[i].getApellido() << endl;
                        cout << "Fecha de nacimiento: " << vectorSubscriptores[i].getFechaNacimiento() << endl;
                        cout << "DNI: " << vectorSubscriptores[i].getDni() << endl;
                        cout << "Email: " << vectorSubscriptores[i].getEmail() << endl;
                        cout << "Telefono: " << vectorSubscriptores[i].getTelefono() << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                }
                fflush(stdin);
                cin.clear();
                system("pause");
                break;
                }
            case 4:
                {
                cls();
                std::string searchSTR;
                cout << "Ingrese el email del subscriptor que desea buscar: ";
                getline(cin, searchSTR);
                cout << endl;
                for(int i=0; i<cantidad; i++){
                    if(toLowerCase(searchSTR)==toLowerCase(vectorSubscriptores[i].getEmail())){
                        cout << "Subscriptor ID:" << vectorSubscriptores[i].getIDSub() << " info" << endl;
                        cout << vectorSubscriptores[i].getNombre() << " " << vectorSubscriptores[i].getApellido() << endl;
                        cout << "Fecha de nacimiento: " << vectorSubscriptores[i].getFechaNacimiento() << endl;
                        cout << "DNI: " << vectorSubscriptores[i].getDni() << endl;
                        cout << "Email: " << vectorSubscriptores[i].getEmail() << endl;
                        cout << "Telefono: " << vectorSubscriptores[i].getTelefono() << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                }
                fflush(stdin);
                cin.clear();
                system("pause");
                break;
                }
            case 5:
                {
                cls();
                int searchINT;
                cout << "Ingrese el anio de nacimiento del subscriptor que desea buscar: ";
                cin >> searchINT;
                cout << endl;
                for(int i=0; i<cantidad; i++){
                    std::string anioSTR = vectorSubscriptores[i].getFechaNacimiento();
                    int anioINT = getAnioDesdeSTR(anioSTR);

                    if(searchINT == anioINT){
                        cout << "Subscriptor ID:" << vectorSubscriptores[i].getIDSub() << " info" << endl;
                        cout << vectorSubscriptores[i].getNombre() << " " << vectorSubscriptores[i].getApellido() << endl;
                        cout << "Fecha de nacimiento: " << vectorSubscriptores[i].getFechaNacimiento() << endl;
                        cout << "DNI: " << vectorSubscriptores[i].getDni() << endl;
                        cout << "Email: " << vectorSubscriptores[i].getEmail() << endl;
                        cout << "Telefono: " << vectorSubscriptores[i].getTelefono() << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                }
                fflush(stdin);
                cin.clear();
                system("pause");
                break;
                }
            case 6:
                exit=true;
                break;
            default:
                cls();
                cout << "OPCION INCORRECTA. VUELVA A INGRESAR" << endl;
                system("pause");
                break;
            }
        }
        fflush(stdin);
        cin.clear();
    }
    while(!exit);

    cls();
    fflush(stdin);
}

void ManagerSubscriptores::eliminarSubscriptor(){
    fflush(stdin);
    cin.clear();
    int idSearch;
    ArchivoSubscriptor archivo("lista de subscriptores.dat");
    Subscriptor reg;
    int cantRegistros = archivo.getCantidadRegistros();

    bool ok = confirmation();

    if(!ok){
        return;
    }

    cout << "Ingrese el ID del subscriptor que desee dar de baja: ";
    cin >> idSearch;

    if(cin.fail()){
        cin.clear();
        cout << "Error: No se ingreso un numero" << endl;
        system("pause>null");
        fflush(stdin);
        return;
    }

    if (!archivo.validarID(idSearch, reg)){
        cout << "El usuario con ID " << idSearch << " no existe." << endl;
        system("pause");
        return;
    }

    reg = archivo.Leer(idSearch-1);
    reg.setEstado(false);
    archivo.guardarSubscriptor(reg, idSearch-1);

    system("pause");
    fflush(stdin);
}

void ManagerSubscriptores::modificarSubscriptor(){
    fflush(stdin);
    std::string dniSearch;
    ArchivoSubscriptor archivo("lista de subscriptores.dat");
    Subscriptor reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el DNI del subscriptor que desee modificar: ";
    getline(cin, dniSearch);

    if(cin.fail()){
        cin.clear();
        cout << "Error: No se ingreso un numero" << endl;
        system("pause>null");
        fflush(stdin);
        return;
    }

    if (!archivo.validarDNI(dniSearch)){
        cout << "El usuario con DNI " << dniSearch << " no existe." << endl;
        system("pause");
        return;
    }

    int id;
    string nombre, apellido, telefono, email, dni;
    int dia, mes, anio;

    int idSub = archivo.devolverIDmediandeDNI(dniSearch);

    cout << "ID Subscriptor: " << idSub << endl;
    reg = archivo.Leer(idSub-1);

    int option;

    do{
        cls();
        cout << "Ingrese que atributo desea modificar" << endl;
        cout << "1- DNI" << endl;
        cout << "2- Nombre" << endl;
        cout << "3- Apellido" << endl;
        cout << "4- Telefono" << endl;
        cout << "5- Email" << endl;
        cout << "6- Fecha de nacimiento" << endl;
        cout << "7- Estado (1-Alta | 0-Baja)" << endl;
        cout << "0- Salir" << endl;
        cin >> option;

        switch(option){
            case 1:
                {
                    fflush(stdin);
                    cout << "Ingrese DNI: ";
                    getline(cin, dni);

                    bool yaExiste = _archivo.validarDNI(dni);
                    if(yaExiste){
                        cout << "El DNI ya existe" << endl;
                        system("pause>null");
                        return;
                    }

                    reg.setDni(dni);
                    cls();
                    break;
                }
            case 2:
                {
                    fflush(stdin);
                    cout << "Ingrese nombre: ";
                    getline(cin, nombre);
                    reg.setNombre(nombre);
                    cls();
                    break;
                }
            case 3:
                {
                    fflush(stdin);
                    cout << "Ingrese apellido: ";
                    getline(cin, apellido);
                    reg.setApellido(apellido);
                    cls();
                    break;
                }
            case 4:
                {
                    fflush(stdin);
                    cout << "Ingrese telefono: ";
                    getline(cin, telefono);
                    reg.setTelefono(telefono);
                    cls();
                    break;
                }
            case 5:
                {
                    fflush(stdin);
                    cout << "Ingrese email: ";
                    getline(cin, email);
                    reg.setEmail(email);
                    cls();
                    break;
                }
            case 6:
                {
                    fflush(stdin);

                    cout << "Ingrese dia de nacimiento: ";
                    cin >> dia;
                    if(cin.fail()){
                        cin.clear();
                        cout << "Error: No se ingreso un numero" << endl;
                        system("pause>null");
                        fflush(stdin);
                        return;
                    }

                    cout << "Ingrese mes de nacimiento: ";
                    cin >> mes;
                    if(cin.fail()){
                        cin.clear();
                        cout << "Error: No se ingreso un numero" << endl;
                        system("pause>null");
                        fflush(stdin);
                        return;
                    }

                    cout << "Ingrese anio de nacimiento: ";
                    cin >> anio;
                    if(cin.fail()){
                        cin.clear();
                        cout << "Error: No se ingreso un numero" << endl;
                        system("pause>null");
                        fflush(stdin);
                        return;
                    }

                    reg.setFechaNacimiento(Fecha(dia,mes,anio));
                    cls();
                    break;
                }
            case 7:
                {
                    fflush(stdin);
                    bool estado;
                    cout << "Ingrese si esta dado de alta o baja (1-Alta | 0-Baja)" << endl;
                    cin >> estado;
                    reg.setEstado(estado);
                    cls();
                    break;
                }
            case 0:
                break;
            default:
                {
                    cout << "Error: Ingrese una opcion valida" << endl;
                    cls();
                    break;
                }
        }
    }while(option!=0);

    if(!archivo.guardarSubscriptor(reg, idSub-1)){
        cout << "El archivo no se pudo modifico" << endl;
    }
    else{
        cout << "El archivo se modifico satisfactoriamente" << endl;
    }



    system("pause");
    fflush(stdin);
}
