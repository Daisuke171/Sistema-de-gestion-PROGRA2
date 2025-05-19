#include <iostream>
using namespace std;
#include "menu.h"
#include "rlutils.h"
#include "managerSubscriptore.h"
#include "managerCanciones.h"
#include "managerAcceso.h"
#include "managerArtista.h"
using namespace rlutil;


int Menu::mostrar(){
    int key;
    ManagerSubscriptores m;
    ManagerCanciones n;
    ManagerAcceso l;
    ManagerArtista p;
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
        cout << "3. GESTION DE ACCESOS" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4. GESTION DE ARTISTAS" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "5. REPORTES" << endl;
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
                if(y>5){
                    y=5;
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
                l.mostrarSubmenuAccess();
                break;
            case 3:
                cls();
                p.mostrarSubmenuArtista();
                break;
            case 4:
                cls();
                cout << "REPORTES" << endl;
                cin.get();
                break;
            case 5:
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
