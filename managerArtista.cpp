#include <iostream>
#include <cstring>
using namespace std;
#include "artista.h"
#include "archivoArtista.h"
#include "managerArtista.h"
#include "rlutils.h"
using namespace rlutil;

void ManagerArtista::mostrarSubmenuArtista(){
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
        cout << "Velvet Note Artistas" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "1- Cargar Artista" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "2- Mostrar Artista" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3- Buscar Artista" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4- Dar de baja Artista" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "5- Editar Artista" << endl;
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
                cargarArtista();
                break;
            case 1:
                cls();
                mostrarArtista();
                break;
            case 2:
                cls();
                buscarArtista();
                break;
            case 3:
                cls();
                eliminarArtista();
                break;
            case 4:
                cls();
                modificarArtista();
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

void ManagerArtista::cargarArtista(){
    fflush(stdin);
    Artista reg;
    ArchivoArtista archivo("lista de artista.dat");

    int idArtista = _archivo.getNewID();
    cout << "ID Artista: " << idArtista << endl;

    string nombreArtista, genero, email, pais;

    cout << "Ingrese nombre de la banda: ";
    getline(cin, nombreArtista);

    ///Para ver si ya hay un registro con ese nombre
    if(archivo.validarNombreArtista(nombreArtista, reg)){
        cout << "El artista ya se encuentra en la base de datos." << endl;
        system("pause");
        return;
    }

    cout << "Ingrese genero musical: ";
    getline(cin, genero);

    cout << "Ingrese email: ";
    getline(cin, email);

    cout << "Ingrese pais de origen: ";
    getline(cin, pais);

    bool estado = true;

    reg = Artista(nombreArtista, idArtista, genero, email, pais, estado);

    if(_archivo.guardarArtista(reg)){
        cout << "Artista guardado correctamente" << endl;
    }
    else{
        cout << "ERROR: El subscriptor no se pudo guardar" << endl;
    }

    fflush(stdin);
    system("pause");
    cls();
}

void ManagerArtista::mostrarArtista(){
    fflush(stdin);
    int cantidad = _archivo.getCantidadRegistros();
    Artista *vectorArtista;

    vectorArtista = new Artista[cantidad];

    if(vectorArtista==nullptr){
        cout << "Error en la asignacion de memoria" << endl;
        exit(-1);
    }

    _archivo.leerMuchos(vectorArtista, cantidad);

    for(int i=0; i<cantidad; i++){
        if(vectorArtista[i].getEstado()){
            cout << "Artista ID:" << vectorArtista[i].getIDArtista() << " info" << endl;
            cout << "Nombre de la banda: " << vectorArtista[i].getNombre() << endl;
            cout << "Genero musicial: " << vectorArtista[i].getGenero() << endl;
            cout << "Pais de origen: " << vectorArtista[i].getPais() << endl;
            cout << "Email: " << vectorArtista[i].getEmail() << endl;
            cout << "--------------------------------------------" << endl;
        }
    }

    system("pause");
    delete []vectorArtista;

    cls();
    fflush(stdin);
}

void ManagerArtista::buscarArtista(){
    fflush(stdin);
    int idSearch;
    ArchivoArtista archivo("lista de artista.dat");
    Artista reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID que desea buscar: ";
    cin >> idSearch;

    if (!archivo.validarID(idSearch, reg)){
        cout << "El artista con ID " << idSearch << " no existe." << endl;
        exit(-1);
    }

    int posicion=0;
    bool found = false;
    for(int i=0; i<cantRegistros; i++){
        reg = archivo.Leer(i);

        if(reg.getIDArtista()==idSearch){
            if(reg.getEstado()==false){
                cout << "El artista fue dado de baja" << endl;
                found=true;
            }
            else{
                cout << "Artista ID:" << reg.getIDArtista() << " info" << endl;
                cout << "Nombre de la banda: " << reg.getNombre() << endl;
                cout << "Genero musicial: " << reg.getGenero() << endl;
                cout << "Pais de origen: " << reg.getPais() << endl;
                cout << "Email: " << reg.getEmail() << endl;
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

void ManagerArtista::eliminarArtista(){
    fflush(stdin);
    int idSearch;
    ArchivoArtista archivo("lista de artista.dat");
    Artista reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID del subscriptor que desee dar de baja: ";
    cin >> idSearch;

    if (!archivo.validarID(idSearch, reg)){
        cout << "El artista con ID " << idSearch << " no existe." << endl;
        exit(-1);
    }

    reg = archivo.Leer(idSearch-1);
    reg.setEstado(false);
    archivo.guardarArtista(reg, idSearch-1);

    system("pause");
    fflush(stdin);
}

void ManagerArtista::modificarArtista(){
    fflush(stdin);
    int idSearch;
    ArchivoArtista archivo("lista de artista.dat");
    Artista reg;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID del subscriptor que desee modificar: ";
    cin >> idSearch;
    if(std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Entrada invalida. Por favor, ingrese un numero." << std::endl;
        while(true){
            cout << "Ingrese el ID del subscriptor que desee modificar: ";
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
    cin.ignore();
    if (!archivo.validarID(idSearch, reg)){
        cout << "El artista con ID " << idSearch << " no existe." << endl;
        return;
    }

    string nombreArtista, genero, pais, email;

    reg = archivo.Leer(idSearch-1);

    int id = idSearch;
    cout << "ID Subscriptor: " << id << endl;

    cout << "Ingrese nombre de la banda: ";
    getline(cin, nombreArtista);

    ///Para ver si ya hay un registro con ese nombre
    if(archivo.validarNombreArtista(nombreArtista, reg)){
        cout << "El artista ya se encuentra en la base de datos." << endl;
        system("pause");
        return;
    }
    reg.setNombre(nombreArtista);

    cout << "Ingrese genero musical: ";
    getline(cin, genero);
    reg.setGenero(genero);

    cout << "Ingrese email: ";
    getline(cin, email);
    reg.setEmail(email);

    cout << "Ingrese pais de origen: ";
    getline(cin, pais);
    reg.setPais(pais);

    bool estado = true;
    reg.setEstado(estado);

    archivo.guardarArtista(reg, idSearch-1);

    system("pause");
    fflush(stdin);
}

void ManagerArtista::cargarArtista(std::string nombre){
    fflush(stdin);
    Artista reg;

    int idArtista = _archivo.getNewID();
    cout << "ID Artista: " << idArtista << endl;

    string nombreArtista=nombre, genero, email, pais;

    cout << endl;
    cout << "CREACION ARTISTA" << endl;
    cout << "Ingrese genero musical: ";
    getline(cin, genero);

    cout << "Ingrese email: ";
    getline(cin, email);

    cout << "Ingrese pais de origen: ";
    getline(cin, pais);

    bool estado = true;

    reg = Artista(nombreArtista, idArtista, genero, email, pais, estado);

    if(_archivo.guardarArtista(reg)){
        cout << "Artista guardado correctamente" << endl;
    }
    else{
        cout << "ERROR: El subscriptor no se pudo guardar" << endl;
    }
    cout << endl;
    fflush(stdin);
    system("pause");
    cls();
}
