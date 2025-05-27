#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#include "managerConfiguracion.h"
#include "rlutils.h"
#include "archivoAcceso.h"
#include "archivoArtista.h"
#include "archivosCancion.h"
#include "archivosSuscriptor.h"
#include "artista.h"
#include "acceso.h"
#include "cancion.h"
#include "suscriptor.h"
#include "userAccess.h"
using namespace rlutil;

void ManagerConfiguracion::mostrarSubmenuConfig(){
    int y=0;
    int key;
    ManagerConfiguracion a;

    do{
        system("cls");
        int i=2;
        locate(tcols()/3,i);
        i++;
        cout << "Velvet Note Configurations" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "1. Realizar copia de seguridad" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "2. Restaurar copia de seguridad" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3. Exportar datos" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "0. Salir" << endl;
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
                if(y>3){
                    y=3;
                }
                break;
        case 1: /// 1 = ENTER
            switch(y){
            case 0:
                cls();
                a.guardarData();
                break;
            case 1:
                cls();

                break;
            case 2:
                cls();
                a.exportarData();
                break;
            case 3:
                cls();
                return;
                break;
            default:
                cls();
                cout << "OPCION INCORRECTA. VUELVA A INGRESAR" << endl;
                cin.get();
                break;
            }
        }

    }
    while (true);

    system("pause");
}

bool ManagerConfiguracion::guardarData(){
    cls();
    fflush(stdin);
    bool result = false;
    ArchivoArtista archivoArt("lista de artista.dat");
    ArchivoCancion archivoCan("lista de canciones.dat");
    ArchivoHistorial archivoHis("lista de accesos.dat");
    ArchivoSubscriptor archivoSub("lista de subscriptores.dat");

    int y=0;
    int key;

    do{
        system("cls");
        int i=2;
        locate(tcols()/3,i);
        i++;
        cout << "Velvet Note Back-Up" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "1. Hacer Backup Artistas" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "2. Hacer Backup Canciones" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3. Hacer Backup Historiales" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4. Hacer Backup Subscriptores" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "5. Hacer Backup Todos" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "0. Salir" << endl;
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
                {
                    cls();
                    bool isAdmin = logon();
                    if(!isAdmin){
                        cout << "Usuario o contraseña incorrecta" << endl;
                        system("pause");
                        break;
                    }
                    else{
                        cout << "Bienvenido Administrador" << endl;
                    }

                    FILE *pFile;
                    pFile = fopen(".\\backups\\lista de artistas.bak", "wb+");
                    if (pFile == nullptr) {
                        perror("Error al abrir archivo");
                        system("pause");
                        return false;
                    }

                    Artista regArt;
                    int cantReg = archivoArt.getCantidadRegistros();
                    for(int i=0; i<cantReg; i++){
                        regArt = archivoArt.Leer(i);
                        fwrite(&regArt, sizeof(Artista), 1, pFile);
                    }


                    fclose(pFile);
                    cout << "Se creo el BackUp exitosamente" << endl;
                    system("pause");
                    break;
                }
            case 1:
                {
                    break;
                }
            case 2:
                {
                    break;
                }
            case 3:
                {
                    break;
                }
            case 4:
                {
                    break;
                }
            case 5:
                {
                    break;
                }
            case 6:
                {
                    result=true;
                    break;
                }
            default:
                cls();
                cout << "OPCION INCORRECTA. VUELVA A INGRESAR" << endl;
                cin.get();
            }
        }
    }while(!result);

    system("pause");
}

bool ManagerConfiguracion::restaurarData(){

}

bool ManagerConfiguracion::exportarData(){
    cls();
    fflush(stdin);
    bool result = false;

    ArchivoArtista archivoArt("lista de artista.dat");
    ArchivoCancion archivoCan("lista de canciones.dat");
    ArchivoHistorial archivoHis("lista de accesos.dat");
    ArchivoSubscriptor archivoSub("lista de subscriptores.dat");

    int y=0;
    int key;

    do{
        system("cls");
        int i=2;
        locate(tcols()/3,i);
        i++;
        cout << "Velvet Note Export" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "1. Exportar Artistas" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "2. Exportar Canciones" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3. Exportar Historiales" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4. Exportar Subscriptores" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "5. Exportar Todos" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "0. Salir" << endl;
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
                {
                cls();
                ///ADMIN VALIDATION
                bool isAdmin = logon();
                if(!isAdmin){
                    cout << "Usuario o contraseña incorrecta" << endl;
                    system("pause");
                    break;
                }
                else{
                    cout << "Bienvenido Administrador" << endl;
                }

                FILE *pFile;
                pFile = fopen(".\\exports\\artistas.csv", "wb+"); // "w" para escribir nuevo archivo
                if (pFile == nullptr) {
                    perror("Error al abrir archivo");
                    system("pause");
                    return false;
                }

                int regCant = archivoArt.getCantidadRegistros();
                if (regCant == 0) {
                    cout << "No hay registros para exportar." << endl;
                    fclose(pFile);
                    system("pause");
                    break;
                }

                // Escribir encabezados
                fprintf(pFile, "ID,Nombre,Genero,Email,Pais\n");
                Artista reg;

                for (int i = 0; i < regCant; i++) {
                    reg = archivoArt.Leer(i);

                    fprintf(pFile, "%d,%s,%s,%s,%s\n",
                            reg.getIDArtista(),
                            reg.getNombre().c_str(),
                            reg.getGenero().c_str(),
                            reg.getEmail().c_str(),
                            reg.getPais().c_str()
                            );
                }

                fclose(pFile);
                cout << "Exportacion a CSV exitosa." << endl;
                system("pause");

                break;
                }
            case 1:
                {
                cls();
                ///ADMIN VALIDATION
                bool isAdmin = logon();
                if(!isAdmin){
                    cout << "Usuario o contraseña incorrecta" << endl;
                    system("pause");
                    break;
                }
                else{
                    cout << "Bienvenido Administrador" << endl;
                }

                FILE *pFile;
                pFile = fopen(".\\exports\\canciones.csv", "wb+"); // "w" para escribir nuevo archivo
                if (pFile == nullptr) {
                    perror("Error al abrir archivo");
                    system("pause");
                    return false;
                }

                int regCant = archivoCan.getCantidadRegistros();
                if (regCant == 0) {
                    cout << "No hay registros para exportar." << endl;
                    fclose(pFile);
                    system("pause");
                    break;
                }

                // Escribir encabezados
                fprintf(pFile, "ID,Nombre,Autor,Interprete,Fecha publicacion\n");
                Cancion reg;

                for (int i = 0; i < regCant; i++) {
                    reg = archivoCan.Leer(i);

                    fprintf(pFile, "%d,%s,%s,%s,%s\n",
                            reg.getID(),
                            reg.getNombre().c_str(),
                            reg.getAutor().c_str(),
                            reg.getInterprete().c_str(),
                            reg.getFechaPublicacion().c_str()
                            );
                }

                fclose(pFile);
                cout << "Exportacion a CSV exitosa." << endl;
                system("pause");
                break;
                }
            case 2:
                {
                cls();
                ///ADMIN VALIDATION
                bool isAdmin = logon();
                if(!isAdmin){
                    cout << "Usuario o contraseña incorrecta" << endl;
                    system("pause");
                    break;
                }
                else{
                    cout << "Bienvenido Administrador" << endl;
                }

                FILE *pFile;
                pFile = fopen(".\\exports\\historiales.csv", "wb+"); // "w" para escribir nuevo archivo
                if (pFile == nullptr) {
                    perror("Error al abrir archivo");
                    system("pause");
                    return false;
                }

                int regCant = archivoCan.getCantidadRegistros();
                if (regCant == 0) {
                    cout << "No hay registros para exportar." << endl;
                    fclose(pFile);
                    system("pause");
                    break;
                }

                // Escribir encabezados
                fprintf(pFile, "ID Historial,ID Cancion,ID Usuario,Fecha,Hora\n");
                HistorialUsuario reg;

                for (int i = 0; i < regCant; i++) {
                    reg = archivoHis.Leer(i);

                    fprintf(pFile, "%d,%d,%d,%d,%d\n",
                            reg.getID(),
                            reg.getIdSong(),
                            reg.getIdSub(),
                            reg.getFecha(),
                            reg.getHora()
                            );
                }

                fclose(pFile);
                cout << "Exportacion a CSV exitosa." << endl;
                system("pause");
                break;
                }
            case 3:
                {
                cls();
                ///ADMIN VALIDATION
                bool isAdmin = logon();
                if(!isAdmin){
                    cout << "Usuario o contraseña incorrecta" << endl;
                    system("pause");
                    break;
                }
                else{
                    cout << "Bienvenido Administrador" << endl;
                }

                FILE *pFile;
                pFile = fopen(".\\exports\\subscriptores.csv", "wb+"); // "w" para escribir nuevo archivo
                if (pFile == nullptr) {
                    perror("Error al abrir archivo");
                    system("pause");
                    return false;
                }

                int regCant = archivoSub.getCantidadRegistros();
                if (regCant == 0) {
                    cout << "No hay registros para exportar." << endl;
                    fclose(pFile);
                    system("pause");
                    break;
                }

                // Escribir encabezados
                fprintf(pFile, "ID,DNI,Nombre,Apellido,telefono,email,Fecha de nacimiento\n");
                Subscriptor reg;

                for (int i = 0; i < regCant; i++) {
                    reg = archivoSub.Leer(i);

                    fprintf(pFile, "%d,%s,%s,%s,%s,%s,%s\n",
                            reg.getIDSub(),
                            reg.getDni().c_str(),
                            reg.getNombre().c_str(),
                            reg.getApellido().c_str(),
                            reg.getTelefono().c_str(),
                            reg.getEmail().c_str(),
                            reg.getFechaNacimiento().c_str()
                            );
                }

                fclose(pFile);
                cout << "Exportacion a CSV exitosa." << endl;
                system("pause");

                break;
                }
            case 4:
                {
cls();
                ///ADMIN VALIDATION
                bool isAdmin = logon();
                if(!isAdmin){
                    cout << "Usuario o contraseña incorrecta" << endl;
                    system("pause");
                    break;
                }
                else{
                    cout << "Bienvenido Administrador" << endl;
                }

                FILE *pFile;
                pFile = fopen(".\\exports\\artistas.csv", "wb+"); // "w" para escribir nuevo archivo
                if (pFile == nullptr) {
                    perror("Error al abrir archivo");
                    system("pause");
                    return false;
                }

                int regCant = archivoArt.getCantidadRegistros();
                if (regCant == 0) {
                    cout << "No hay registros para exportar." << endl;
                    fclose(pFile);
                    system("pause");
                    break;
                }

                // Escribir encabezados
                fprintf(pFile, "ID,Nombre,Genero,Email,Pais\n");
                Artista regArt;

                for (int i = 0; i < regCant; i++) {
                    regArt = archivoArt.Leer(i);

                    fprintf(pFile, "%d,%s,%s,%s,%s\n",
                            regArt.getIDArtista(),
                            regArt.getNombre().c_str(),
                            regArt.getGenero().c_str(),
                            regArt.getEmail().c_str(),
                            regArt.getPais().c_str()
                            );
                }

                fclose(pFile);

                pFile = fopen(".\\exports\\canciones.csv", "wb+"); // "w" para escribir nuevo archivo
                if (pFile == nullptr) {
                    perror("Error al abrir archivo");
                    system("pause");
                    return false;
                }

                regCant = archivoCan.getCantidadRegistros();
                if (regCant == 0) {
                    cout << "No hay registros para exportar." << endl;
                    fclose(pFile);
                    system("pause");
                    break;
                }

                // Escribir encabezados
                fprintf(pFile, "ID,Nombre,Autor,Interprete,Fecha publicacion\n");
                Cancion regCan;

                for (int i = 0; i < regCant; i++) {
                    regCan = archivoCan.Leer(i);

                    fprintf(pFile, "%d,%s,%s,%s,%s\n",
                            regCan.getID(),
                            regCan.getNombre().c_str(),
                            regCan.getAutor().c_str(),
                            regCan.getInterprete().c_str(),
                            regCan.getFechaPublicacion().c_str()
                            );
                }

                fclose(pFile);

                pFile = fopen(".\\exports\\historiales.csv", "wb+"); // "w" para escribir nuevo archivo
                if (pFile == nullptr) {
                    perror("Error al abrir archivo");
                    system("pause");
                    return false;
                }

                regCant = archivoCan.getCantidadRegistros();
                if (regCant == 0) {
                    cout << "No hay registros para exportar." << endl;
                    fclose(pFile);
                    system("pause");
                    break;
                }

                // Escribir encabezados
                fprintf(pFile, "ID Historial,ID Cancion,ID Usuario,Fecha,Hora\n");
                HistorialUsuario regHist;

                for (int i = 0; i < regCant; i++) {
                    regHist = archivoHis.Leer(i);

                    fprintf(pFile, "%d,%d,%d,%d,%d\n",
                            regHist.getID(),
                            regHist.getIdSong(),
                            regHist.getIdSub(),
                            regHist.getFecha(),
                            regHist.getHora()
                            );
                }

                fclose(pFile);

                pFile = fopen(".\\exports\\subscriptores.csv", "wb+"); // "w" para escribir nuevo archivo
                if (pFile == nullptr) {
                    perror("Error al abrir archivo");
                    system("pause");
                    return false;
                }

                regCant = archivoSub.getCantidadRegistros();
                if (regCant == 0) {
                    cout << "No hay registros para exportar." << endl;
                    fclose(pFile);
                    system("pause");
                    break;
                }

                // Escribir encabezados
                fprintf(pFile, "ID,DNI,Nombre,Apellido,telefono,email,Fecha de nacimiento\n");
                Subscriptor regSub;

                for (int i = 0; i < regCant; i++) {
                    regSub = archivoSub.Leer(i);

                    fprintf(pFile, "%d,%s,%s,%s,%s,%s,%s\n",
                            regSub.getIDSub(),
                            regSub.getDni().c_str(),
                            regSub.getNombre().c_str(),
                            regSub.getApellido().c_str(),
                            regSub.getTelefono().c_str(),
                            regSub.getEmail().c_str(),
                            regSub.getFechaNacimiento().c_str()
                            );
                }

                fclose(pFile);

                cout << "Exportacion a CSV exitosa." << endl;
                system("pause");

                break;
                }
            case 5:
                result = true;
                break;
            default:
                cls();
                cout << "OPCION INCORRECTA. VUELVA A INGRESAR" << endl;
                cin.get();
                break;
            }
        }
    }
    while (!result);


    system("pause");
    return result;
}

