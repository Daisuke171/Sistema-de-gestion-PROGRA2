#include <iostream>
using namespace std;
#include "menu.h"
#include "rlutils.h"
#include "managerSubscriptore.h"
#include "managerCanciones.h"
#include "managerAcceso.h"
#include "managerArtista.h"
#include "managerConfiguracion.h"
#include "reporte.h"
#include "userAccess.h"
using namespace rlutil;


int Menu::mostrar(){
    int key;
    ManagerSubscriptores m;
    ManagerCanciones n;
    ManagerHistorial l;
    ManagerArtista p;
    ManagerConfiguracion q;
    ManagerReporte r;
    setBackgroundColor(MAGENTA);
    setColor(WHITE);

    int y=0;
    hidecursor();

    do{
        system("cls");
        int i=2;
        locate(tcols()/3,i);
        i++;
        cout << "Velvet Note Management" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "1. GESTION DE SUSCRIPTORES" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "2. GESTION DE CANCIONES" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3. GESTION DE HISTORIALES" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4. GESTION DE ARTISTAS" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "5. REPORTES" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "6. CONFIGURACIONES" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "0. FIN DEL PROGRAMA" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i+1);
        cout << "SELECCIONE UNA OPCION " << endl;


        ///PUNTERO PARA SELECCIONAR OPCION :P
        locate((tcols()/3)-2, 4+y);
        cout << (char)175;
        key = getkey();

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
                m.mostrarSubmenuSubs();
                break;
            case 1:
                cls();
                n.mostrarSubmenuCanciones();
                break;
            case 2:
                cls();
                l.mostrarSubmenuHistorial();
                break;
            case 3:
                cls();
                p.mostrarSubmenuArtista();
                break;
            case 4:
                cls();
                r.mostrarSubmenuReportes();
                break;
            case 5:
                {
                cls();
               ///ADMIN VALIDATION
                bool isAdmin = logon();
                if(!isAdmin){
                    cout << "Usuario o contrasenia incorrecta" << endl;
                    system("pause");
                    break;
                }
                else{
                    cout << "Bienvenido Administrador" << endl;
                    system("pause");
                }
                q.mostrarSubmenuConfig();
                break;
                }
            case 6:
                cls();
                cout << "GRACIAS POR ELEGIR NUESTRO PROGRAMA :)" << endl;
                cin.get();
                return 0;
            default:
                cls();
                cout << "OPCION INCORRECTA. VUELVA A INGRESAR" << endl;
                cin.get();
                break;
            }
        }

    }
    while (true);
}

void Menu::logo(){
    setBackgroundColor(MAGENTA);
    setColor(WHITE);
    hidecursor();
    int coordinates = (trows()/3)-7;
    system("cls");

    int marcoX = coordinates+16;
    int marcoY = coordinates+11;
    int ancho = 61;
    ///Marco superior
    locate(marcoX-3, coordinates);
    cout << (char)201;
    for(int i=0; i<ancho; i++){
        cout << (char)205;
    }
    cout << (char)187 <<endl;

    ///marco inferior
    locate(marcoX-3, marcoY);
    cout << (char)200;
    for(int i=0; i<ancho; i++){
        cout << (char)205;
    }
    cout << (char)188;

    locate(coordinates, coordinates);
    std::cout << R"(

                     _    __     __           __     _   __      __
                    | |  / /__  / /   _____  / /_   / | / /___  / /____
                    | | / / _ \/ / | / / _ \/ __/  /  |/ / __ \/ __/ _ \
                    | |/ /  __/ /| |/ /  __/ /_   / /|  / /_/ / /_/  __/
                    |___/\___/_/ |___/\___/\__/  /_/ |_/\____/\__/\___/


    )" << '\n';

    ///lateral izquierdo
    for(int i=1; i<11; i++){
        locate(marcoX-3, coordinates+i);
        cout << (char)186 << endl;
    }
    ///lateral derecho
    for(int i=1; i<11; i++){
        locate(marcoX+59, coordinates+i);
        cout << (char)186 << endl;
    }


    locate(tcols()/3-8, 12);
    std::cout << "Bienvenido a Velvet Note Manager" << std::endl;
    locate(tcols()/3-12, 16);
    std::cout << "Presione cualquier tecla para continuar" << std::endl;

    system("pause > null");
    cls();
}
