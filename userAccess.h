#ifndef USERACCESS_H_INCLUDED
#define USERACCESS_H_INCLUDED
using namespace std;
#define msg(str) std::cout<<str<<std::endl;

const char *admin = "agus23";
const char *passwordAdmin = "admin";

bool logon(){
    string user, password;

    msg("INGRESE NOMBRE DEL ADMIN:");
    cin>>user;

    msg("INGRESE CONTRASENIA: ");
    cin>>password;

    if(user!=admin || password!=passwordAdmin){
        return false;
    }
    else if(user==admin && password==password){
        return true;
    }
}

#endif // USERACCESS_H_INCLUDED
