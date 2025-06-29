#include <iostream>
#include <cstring>
#include "cancion.h"
#include "managerCanciones.h"
#include "fecha.h"
#include "rlutils.h"
#include "archivosCancion.h"
#include "artista.h"
#include "archivoArtista.h"
#include "managerArtista.h"
#include "arrayUtils.h"
#include "userAccess.h"
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
    FILE *pFile;

    Artista regArtistas;
    ManagerArtista manArtista;
    ArchivoArtista archivoArtistas("lista de artista.dat");

    int id, idArtista;
    string nombre, autor, interprete;
    int dia, mes, anio;

    id = _archivo.getNewID();
    cout << "ID Cancion: " << id << endl;

    cout << "Ingrese nombre de la cancion: ";
    getline(cin, nombre);

    bool yaExiste = _archivo.validarNombre(nombre);
    if(yaExiste){
        cout << "El nombre ya existe" << endl;
        system("pause>null");
        return;
    }

    cout << "Ingrese nombre del autor: ";
    getline(cin, autor);

    if(!archivoArtistas.validarNombreArtista(autor, regArtistas)){
        cout << "El artista no se encuentra en la base de datos" << endl;
        return;
    }
    else{
        pFile = fopen("lista de artista.dat", "rb");
        Artista regArt;
        int cantRegArt = archivoArtistas.getCantidadRegistros();

        for(int i=0; i<cantRegArt; i++){
            regArt = archivoArtistas.Leer(i);
            if(regArt.getNombre() == autor){
                idArtista = regArt.getIDArtista();
                break;
            }
        }

        fclose(pFile);
    }

    cout << "Ingrese nombre del interprete: ";
    getline(cin, interprete);

    cout << "Ingrese dia: ";
    cin >> dia;
    if(cin.fail()){
        cin.clear();
        cout << "Error: No se ingreso un numero" << endl;
        system("pause>null");
        fflush(stdin);
        return;
    }

    cout << "Ingrese mes: ";
    cin >> mes;
    if(cin.fail()){
        cin.clear();
        cout << "Error: No se ingreso un numero" << endl;
        system("pause>null");
        fflush(stdin);
        return;
    }

    cout << "Ingrese anio: ";
    cin >> anio;
    if(cin.fail()){
        cin.clear();
        cout << "Error: No se ingreso un numero" << endl;
        system("pause>null");
        fflush(stdin);
        return;
    }

    bool estado = true;

    reg = Cancion(id, idArtista, nombre, autor, interprete, Fecha(dia,mes,anio), estado);

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
        cout << "2- Por Genero" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3- Por Artista" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4- Por Anio" << endl;
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

        cls();
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
                _archivo.ordenarDefaultID(vectorCanciones, cantidad);
                for(int i=0; i<cantidad; i++){
                    cout << "Cancion ID:" << vectorCanciones[i].getID() << " info" << endl;
                    cout << "Nombre de la cancion: " << vectorCanciones[i].getNombre() << endl;
                    cout << "Autor: " << vectorCanciones[i].getAutor() << '\t' << "ID Autor: " << vectorCanciones[i].getIDArtista() << '\t';
                    cout << " | Interprete: " << vectorCanciones[i].getInterprete() << endl;
                    cout << "Genero: " << vectorCanciones[i].getGenero() << endl;
                    cout << "Fecha de publicacion: " << vectorCanciones[i].getFechaPublicacion() << endl;
                    cout << "--------------------------------------------" << endl;
                }
                system("pause");
                break;
            case 1:
                _archivo.ordenarCancionesPorGenero(vectorCanciones, cantidad);
                for(int i=0; i<cantidad; i++){
                    cout << "Cancion ID:" << vectorCanciones[i].getID() << " info" << endl;
                    cout << "Nombre de la cancion: " << vectorCanciones[i].getNombre() << endl;
                    cout << "Autor: " << vectorCanciones[i].getAutor() << '\t' << "ID Autor: " << vectorCanciones[i].getIDArtista() << '\t';
                    cout << " | Interprete: " << vectorCanciones[i].getInterprete() << endl;
                    cout << "Genero: " << vectorCanciones[i].getGenero() << endl;
                    cout << "Fecha de publicacion: " << vectorCanciones[i].getFechaPublicacion() << endl;
                    cout << "--------------------------------------------" << endl;
                }
                system("pause");
                break;
            case 2:
                _archivo.ordenarCancionesPorArtistas(vectorCanciones, cantidad);
                for(int i=0; i<cantidad; i++){
                    cout << "Cancion ID:" << vectorCanciones[i].getID() << " info" << endl;
                    cout << "Nombre de la cancion: " << vectorCanciones[i].getNombre() << endl;
                    cout << "Autor: " << vectorCanciones[i].getAutor() << '\t' << "ID Autor: " << vectorCanciones[i].getIDArtista() << '\t';
                    cout << " | Interprete: " << vectorCanciones[i].getInterprete() << endl;
                    cout << "Genero: " << vectorCanciones[i].getGenero() << endl;
                    cout << "Fecha de publicacion: " << vectorCanciones[i].getFechaPublicacion() << endl;
                    cout << "--------------------------------------------" << endl;
                }
                system("pause");
                break;
            case 3:
                _archivo.ordenarCancionesPorAnio(vectorCanciones, cantidad);
                for(int i=0; i<cantidad; i++){
                    cout << "Cancion ID:" << vectorCanciones[i].getID() << " info" << endl;
                    cout << "Nombre de la cancion: " << vectorCanciones[i].getNombre() << endl;
                    cout << "Autor: " << vectorCanciones[i].getAutor() << '\t' << "ID Autor: " << vectorCanciones[i].getIDArtista() << '\t';
                    cout << " | Interprete: " << vectorCanciones[i].getInterprete() << endl;
                    cout << "Genero: " << vectorCanciones[i].getGenero() << endl;
                    cout << "Fecha de publicacion: " << vectorCanciones[i].getFechaPublicacion() << endl;
                    cout << "--------------------------------------------" << endl;
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
    int cantidad = archivo.getCantidadRegistros();

    int key;
    bool exit = false;
    int y=0;
    hidecursor();

    Cancion *vectorCanciones = new Cancion[cantidad];
    if(vectorCanciones==nullptr){
        cout << "Error en la asignacion de memoria" << endl;
        return;
    }
    archivo.leerMuchos(vectorCanciones, cantidad);

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
        cout << "1- Por Nombre" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "2- Por ID" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3- Por Genero" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4- Por Artista" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "5- Por Interprete" << endl;
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
                if(y>5){
                    y=5;
                }
                break;
        case 1: /// 1 = ENTER
            switch(y){
            case 0:
                {
                cls();
                std::string searchSTR;

                cout << "Ingrese el nombre de la cancion que desea buscar: ";
                getline(cin, searchSTR);
                cout << endl;
                for(int i=0; i<cantidad; i++){
                    if(toLowerCase(searchSTR)==toLowerCase(vectorCanciones[i].getNombre())){
                        cout << "Cancion ID:" << vectorCanciones[i].getID() << " info" << endl;
                        cout << "Nombre de la cancion: " << vectorCanciones[i].getNombre() << endl;
                        cout << "Autor: " << vectorCanciones[i].getAutor() << '\t' << "ID Autor: " << vectorCanciones[i].getIDArtista() << '\t';
                        cout << " | Interprete: " << vectorCanciones[i].getInterprete() << endl;
                        cout << "Genero: " << vectorCanciones[i].getGenero() << endl;
                        cout << "Fecha de publicacion: " << vectorCanciones[i].getFechaPublicacion() << endl;
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
                int searchINT;
                cout << "Ingrese el ID de la cancion: ";
                cin >> searchINT;
                cout << endl;
                for(int i=0; i<cantidad; i++){
                    if(searchINT==vectorCanciones[i].getID()){
                        cout << "Cancion ID:" << vectorCanciones[i].getID() << " info" << endl;
                        cout << "Nombre de la cancion: " << vectorCanciones[i].getNombre() << endl;
                        cout << "Autor: " << vectorCanciones[i].getAutor() << '\t' << "ID Autor: " << vectorCanciones[i].getIDArtista() << '\t';
                        cout << " | Interprete: " << vectorCanciones[i].getInterprete() << endl;
                        cout << "Genero: " << vectorCanciones[i].getGenero() << endl;
                        cout << "Fecha de publicacion: " << vectorCanciones[i].getFechaPublicacion() << endl;
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
                std::string searchSTR;
                cout << "Ingrese el nombre del genero de las canciones que desea buscar: ";
                getline(cin, searchSTR);
                cout << endl;
                for(int i=0; i<cantidad; i++){
                    if(toLowerCase(searchSTR)==toLowerCase(vectorCanciones[i].getGenero())){
                        cout << "Cancion ID:" << vectorCanciones[i].getID() << " info" << endl;
                        cout << "Nombre de la cancion: " << vectorCanciones[i].getNombre() << endl;
                        cout << "Autor: " << vectorCanciones[i].getAutor() << '\t' << "ID Autor: " << vectorCanciones[i].getIDArtista() << '\t';
                        cout << " | Interprete: " << vectorCanciones[i].getInterprete() << endl;
                        cout << "Genero: " << vectorCanciones[i].getGenero() << endl;
                        cout << "Fecha de publicacion: " << vectorCanciones[i].getFechaPublicacion() << endl;
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
                cout << "Ingrese el nombre del artista de las canciones que desea buscar: ";
                getline(cin, searchSTR);
                cout << endl;
                for(int i=0; i<cantidad; i++){
                    if(toLowerCase(searchSTR)==toLowerCase(vectorCanciones[i].getAutor())){
                        cout << "Cancion ID:" << vectorCanciones[i].getID() << " info" << endl;
                        cout << "Nombre de la cancion: " << vectorCanciones[i].getNombre() << endl;
                        cout << "Autor: " << vectorCanciones[i].getAutor() << '\t' << "ID Autor: " << vectorCanciones[i].getIDArtista() << '\t';
                        cout << " | Interprete: " << vectorCanciones[i].getInterprete() << endl;
                        cout << "Genero: " << vectorCanciones[i].getGenero() << endl;
                        cout << "Fecha de publicacion: " << vectorCanciones[i].getFechaPublicacion() << endl;
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
                cout << "Ingrese el nombre del interprete de las canciones que desea buscar: ";
                getline(cin, searchSTR);
                cout << endl;
                for(int i=0; i<cantidad; i++){
                    if(toLowerCase(searchSTR)==toLowerCase(vectorCanciones[i].getInterprete())){
                        cout << "Cancion ID:" << vectorCanciones[i].getID() << " info" << endl;
                        cout << "Nombre de la cancion: " << vectorCanciones[i].getNombre() << endl;
                        cout << "Autor: " << vectorCanciones[i].getAutor() << '\t' << "ID Autor: " << vectorCanciones[i].getIDArtista() << '\t';
                        cout << " | Interprete: " << vectorCanciones[i].getInterprete() << endl;
                        cout << "Genero: " << vectorCanciones[i].getGenero() << endl;
                        cout << "Fecha de publicacion: " << vectorCanciones[i].getFechaPublicacion() << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                }
                fflush(stdin);
                cin.clear();
                system("pause");
                break;
                }
            case 5:
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

    delete []vectorCanciones;

    cls();
    fflush(stdin);
}

void ManagerCanciones::eliminarCancion(){
    fflush(stdin);
    int idSearch;
    ArchivoCancion archivo("lista de canciones.dat");
    Cancion reg;
    int cantRegistros = archivo.getCantidadRegistros();

    bool ok = confirmation();

    if(!ok){
        return;
    }

    cout << "Ingrese el ID de la cancion que desee dar de baja: ";
    cin >> idSearch;

    if(cin.fail()){
        cin.clear();
        cout << "Error: No se ingreso un numero" << endl;
        system("pause>null");
        fflush(stdin);
        return;
    }

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
    ManagerArtista manArtista;
    int cantRegistros = archivo.getCantidadRegistros();

    cout << "Ingrese el ID de la cancion que desee modificar: ";
    cin >> idSearch;

    if(cin.fail()){
        cin.clear();
        cout << "Error: No se ingreso un numero" << endl;
        system("pause>null");
        fflush(stdin);
        return;
    }

    if (!archivo.validarID(idSearch, reg)){
        cout << "La cancion con ID " << idSearch << " no existe." << endl;
        system("pause");
        return;
    }

    string nombre, autor, interprete;
    int dia, mes, anio, idArtista;

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
            fflush(stdin);
            cout << "Ingrese nombre de la cancion: ";
            getline(cin, nombre);
            reg.setNombre(nombre);
            break;
        }
    case 2:
        {
            fflush(stdin);
            cout << "Ingrese nombre del autor: ";
            getline(cin, autor);

            ArchivoArtista archivoArtistas("lista de artista.dat");
            Artista regArtistas;
            FILE *pfile;
            pfile = fopen("lista de artista.dat", "r");
            int cantReg = archivoArtistas.getCantidadRegistros();

            if(archivoArtistas.validarNombreArtista(autor, regArtistas)){
                for(int i=0; i<cantReg; i++){
                    regArtistas = archivoArtistas.Leer(i);
                    if(regArtistas.getNombre() == autor){
                        idArtista = regArtistas.getIDArtista();
                        break;
                    }
                }
            }
            else{
                cout << "El artista no se encuentra en la base de datos. Desea crearlo? (0= no, 1=si)" << endl;
                bool crearArtista = false;
                cin >> crearArtista;
                if(crearArtista){
                    manArtista.cargarArtista(autor);
                    idArtista = archivoArtistas.getCantidadRegistros(); ///como es un registro nuevo el ID es igual a la cantidad de registros
                }
                else{
                    return;
                }
            }
            reg.setIDArtista(idArtista);
            reg.setAutor(autor);
            break;
        }
    case 3:
        {
            fflush(stdin);
            cout << "Ingrese nombre del interprete: ";
            getline(cin, interprete);
            reg.setInterprete(interprete);
            break;
        }
    case 4:
        {
            cout << "Ingrese dia: ";
            cin >> dia;
            if(cin.fail()){
                cin.clear();
                cout << "Error: No se ingreso un numero" << endl;
                system("pause>null");
                fflush(stdin);
                return;
            }

            cout << "Ingrese mes: ";
            cin >> mes;
            if(cin.fail()){
                cin.clear();
                cout << "Error: No se ingreso un numero" << endl;
                system("pause>null");
                fflush(stdin);
                return;
            }

            cout << "Ingrese anio: ";
            cin >> anio;
            if(cin.fail()){
                cin.clear();
                cout << "Error: No se ingreso un numero" << endl;
                system("pause>null");
                fflush(stdin);
                return;
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
