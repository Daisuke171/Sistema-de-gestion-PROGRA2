#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <iostream>

class Admin{
private:
    const char *_name = "agus23";
    const char *_password = "admin";
public:
    std::string getAdmin(){
        return _name;
    }

    std::string getPassword(){
        return _password;
    }
};

#endif // ADMIN_H_INCLUDED
