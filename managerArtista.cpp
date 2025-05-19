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

                break;
            case 2:
                cls();

                break;
            case 3:
                cls();

                break;
            case 4:
                cls();

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
    Artista reg;

    int idArtista = _archivo.getNewID();
    cout << "ID Artista: " << idArtista << endl;

    string nombreArtista, genero, email, pais;

    cout << "Ingrese nombre de la banda: ";
    cin.ignore();
    getline(cin, nombreArtista);

    cout << "Ingrese genero musical: ";
    getline(cin, genero);

    cout << "Ingrese email: ";
    getline(cin, email);

    cout << "Ingrese pais: ";
    getline(cin, pais);

    bool estado = true;

    reg = Artista(nombreArtista, idArtista, genero, email, pais, estado);

    if(_archivo.guardarArtista(reg)){
        cout << "Subscriptor guardado correctamente" << endl;
    }
    else{
        cout << "ERROR: El subscriptor no se pudo guardar" << endl;
    }

    system("pause");
    cls();
}

void ManagerArtista::mostrarArtista(){

}

void ManagerArtista::buscarArtista(){}

void ManagerArtista::eliminarArtista(){}

void ManagerArtista::modificarArtista(){}
