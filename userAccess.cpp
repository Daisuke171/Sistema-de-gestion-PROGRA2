#include <iostream>
#include <cstring>
#include "userAccess.h"
#include "admin.h"
using namespace std;


bool logon(){
    Admin credentials;
    string user, password;

    msg("INGRESE NOMBRE DEL ADMIN:");
    cin>>user;

    msg("INGRESE CONTRASENIA: ");
    cin>>password;

    if(user!=credentials.getAdmin() || password!=credentials.getPassword()){
        return false;
    }
    else if(user==credentials.getAdmin() && password==credentials.getPassword()){
        return true;
    }
}

bool confirmation(){
    int select;
    bool ok;

    cout << "Usted esta seguro de seguir con la operacion? (0=no  1=si)" << endl;
    cin >> select;

    if(cin.fail()){
        cout << "Error: No se ingreso un numero" << endl;
        system("pause>null");
        ok = false;
        cin.clear();
    }
    else if(select==1){
        ok = true;
    }
    else if(select==0){
        ok = false;
    }
    else{
        cout << "Error: Solo se aceptan 0 o 1" << endl;
        system("pause>null");
        ok = false;
    }

    fflush(stdin);
    return ok;
}
