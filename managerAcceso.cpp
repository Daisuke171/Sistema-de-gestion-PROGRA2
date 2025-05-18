#include <iostream>
#include <cstring>
using namespace std;
#include "managerAcceso.h"
#include "rlutils.h"
#include "acceso.h"
#include "cancion.h"
#include "suscriptor.h"
#include "archivosSuscriptor.h"
#include "archivoAcceso.h"
#include "archivosCancion.h"
using namespace rlutil;

void ManagerAcceso::mostrarSubmenuAccess(){
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
        cout << "*****MENU ACCESOS*****" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "------------------------" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "1- Cargar Acceso" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "2- Mostrar Accesos" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "3- Modificar Accesos" << endl;
        i++;
        locate(tcols()/3,i);
        cout << "0- Volver atras" << endl;
        i++;
        locate(tcols()/3,i);
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
                cargarAcceso();
                break;
            case 1:
                cls();
                mostrarAcceso();
                break;
            case 2:
                cls();
            /// MODIFICAR ACCESO
                break;
            case 3:
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

void ManagerAcceso::cargarAcceso(){
    int idUser, idSong, dia, mes, anio, hora;
    ArchivoCancion archivo("lista de canciones.dat");
    ArchivoSubscriptor archivo2("lista de subscriptores.dat");
    Cancion c;
    Subscriptor s;

    cout << "Ingrese el ID del usuario: ";
    cin >> idUser;

    ///FUNCION PARA VER SI EL ID EXISTE
    if (!archivo2.validarID(idUser, s)){
        cout << "El usuario con ID " << idUser << " no existe. No se puede crear el acceso" << endl;
        exit(-1);
    }

    cout << "Ingrese el ID de la cancion: ";
    cin >> idSong;

    ///FUNCION PARA VER SI EL ID EXISTE
    if (!archivo.buscarPorID(idSong, c)){
        cout << "La cancion con ID " << idSong << " no existe. No se puede crear el acceso" << endl;
        exit(-1);
    }

    cout << "Ingrese dia: ";
    cin >> dia;
    cout << "Ingrese mes: ";
    cin >> mes;
    cout << "Ingrese anio: ";
    cin >> anio;
    cout << "Ingrese hora: ";
    cin >> hora;

    Acceso reg;

    reg = Acceso(idSong, idUser, Fecha(dia,mes,anio), hora);

    if(_archivo.guardarAcceso(reg)){
        cout << "Acceso guardado correctamente" << endl;
    }
    else{
        cout << "ERROR: El acceso no se pudo guardar" << endl;
        exit(-2);
    }
    system("pause");
    cls();
}

void ManagerAcceso::mostrarAcceso(){
    int cantidad = _archivo.getCantidadRegistros();
    Acceso *vectorAcceso;

    vectorAcceso = new Acceso[cantidad];

    if(vectorAcceso==nullptr){
        cout << "Error en la asignacion de memoria" << endl;
        exit(-1);
    }

    _archivo.leerMuchos(vectorAcceso, cantidad);

    for(int i=0; i<cantidad; i++){
        cout << "Acceso de usuario " << vectorAcceso[i].getIdSub() << endl;
        cout << "Cancion " << vectorAcceso[i].getIdSong() << endl;
        cout << "Fecha: " << vectorAcceso[i].getFecha() << " Hora: " << vectorAcceso[i].getHora() << endl;
        cout << "--------------------------------------------" << endl;
    }

    system("pause");
    delete []vectorAcceso;

    cls();
}
