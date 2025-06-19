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
                a.restaurarData();
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
                    cout << "Se creo el Back-Up exitosamente" << endl;
                    system("pause");
                    break;
                }
            case 1:
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
                    pFile = fopen(".\\backups\\lista de canciones.bak", "wb+");
                    if (pFile == nullptr) {
                        perror("Error al abrir archivo");
                        system("pause");
                        return false;
                    }

                    Cancion regCan;
                    int cantReg = archivoCan.getCantidadRegistros();
                    for(int i=0; i<cantReg; i++){
                        regCan = archivoCan.Leer(i);
                        fwrite(&regCan, sizeof(Cancion), 1, pFile);
                    }


                    fclose(pFile);
                    cout << "Se creo el Back-Up exitosamente" << endl;
                    system("pause");
                    break;
                }
            case 2:
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
                    pFile = fopen(".\\backups\\lista de historiales.bak", "wb+");
                    if (pFile == nullptr) {
                        perror("Error al abrir archivo");
                        system("pause");
                        return false;
                    }

                    HistorialUsuario regHis;
                    int cantReg = archivoHis.getCantidadRegistros();
                    for(int i=0; i<cantReg; i++){
                        regHis = archivoHis.Leer(i);
                        fwrite(&regHis, sizeof(HistorialUsuario), 1, pFile);
                    }


                    fclose(pFile);
                    cout << "Se creo el Back-Up exitosamente" << endl;
                    system("pause");
                    break;
                }
            case 3:
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
                    pFile = fopen(".\\backups\\lista de subscriptores.bak", "wb+");
                    if (pFile == nullptr) {
                        perror("Error al abrir archivo");
                        system("pause");
                        return false;
                    }

                    Subscriptor regSub;
                    int cantReg = archivoSub.getCantidadRegistros();
                    for(int i=0; i<cantReg; i++){
                        regSub = archivoSub.Leer(i);
                        fwrite(&regSub, sizeof(Subscriptor), 1, pFile);
                    }


                    fclose(pFile);
                    cout << "Se creo el Back-Up exitosamente" << endl;
                    system("pause");
                    break;
                }
            case 4:
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

                    FILE *pFile1, *pFile2, *pFile3, *pFile4;
                    pFile1 = fopen(".\\backups\\lista de artistas.bak", "wb+");
                    pFile2 = fopen(".\\backups\\lista de canciones.bak", "wb+");
                    pFile3 = fopen(".\\backups\\lista de historiales.bak", "wb+");
                    pFile4 = fopen(".\\backups\\lista de subscriptores.bak", "wb+");
                    if (pFile1 == nullptr || pFile2 == nullptr || pFile3 == nullptr || pFile4 == nullptr) {
                        perror("Error al abrir los archivos");
                        system("pause");
                        return false;
                    }

                    Artista regArt;
                    Cancion regCan;
                    HistorialUsuario regHis;
                    Subscriptor regSub;

                    int cantArtist, cantCanciones, cantHistorial, cantSubs;
                    cantArtist = archivoArt.getCantidadRegistros();
                    cantCanciones = archivoCan.getCantidadRegistros();
                    cantHistorial = archivoHis.getCantidadRegistros();
                    cantSubs = archivoSub.getCantidadRegistros();

                    for(int i=0; i<cantArtist; i++){
                        regArt = archivoArt.Leer(i);
                        fwrite(&regArt, sizeof(Artista), 1, pFile1);
                    }
                    for(int i=0; i<cantCanciones; i++){
                        regCan = archivoCan.Leer(i);
                        fwrite(&regCan, sizeof(Cancion), 1, pFile2);
                    }
                    for(int i=0; i<cantHistorial; i++){
                        regHis = archivoHis.Leer(i);
                        fwrite(&regHis, sizeof(HistorialUsuario), 1, pFile3);
                    }
                    for(int i=0; i<cantSubs; i++){
                        regSub = archivoSub.Leer(i);
                        fwrite(&regSub, sizeof(Subscriptor), 1, pFile4);
                    }

                    fclose(pFile1);
                    fclose(pFile2);
                    fclose(pFile3);
                    fclose(pFile4);
                    cout << "Se crearon los Back-Ups exitosamente" << endl;
                    system("pause");

                    break;
                }
            case 5:
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

    return result;
}

bool ManagerConfiguracion::restaurarData(){
    bool exit=false;
    int y=0;
    int key;

    ArchivoArtista archivoArt("lista de artista.dat");
    ArchivoArtista archivoArtBKP(".\\backups\\lista de artistas.bak");
    ArchivoCancion archivoCan("lista de canciones.dat");
    ArchivoCancion archivoCanBKP(".\\backups\\lista de canciones.bak");
    ArchivoHistorial archivoHis("lista de accesos.dat");
    ArchivoHistorial archivoHisBKP(".\\backups\\lista de historiales.bak");
    ArchivoSubscriptor archivoSub("lista de subscriptores.dat");
    ArchivoSubscriptor archivoSubBKP(".\\backups\\lista de subscriptores.bak");

    do{
        system("cls");
        int i=2;
        locate(tcols()/3,i);
        i++;
        cout << "Velvet Note Restore" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "1. Restaurar Artistas" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "2. Restaurar Canciones" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3. Restaurar Historiales" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4. Restaurar Subscriptores" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "5. Restaurar Todos" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "6. Reinicializar con Datos Predeterminados" << endl;
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
                if(y>6){
                    y=6;
                }
                break;
        case 1: /// 1 = ENTER
            switch(y){
            case 0:
                {
                    cls();
                    FILE *pFile1, *pFile2;
                    pFile1 = fopen("lista de artista.dat", "wb+");
                    pFile2 = fopen(".\\backups\\lista de artistas.bak", "rb");

                    if(pFile1 == nullptr || pFile2 == nullptr){
                        perror("Error al abrir archivos");
                        system("pause");
                        return false;
                    }

                    Artista regBkp;

                    int cantReg = archivoArtBKP.getCantidadRegistros();
                    std::remove("lista de artista.dat");

                    for(int i=0; i<cantReg; i++){
                        regBkp = archivoArtBKP.Leer(i);

                        fwrite(&regBkp, sizeof(Artista), 1, pFile1);
                    }


                    fclose(pFile1);
                    fclose(pFile2);

                    cout << "Se restauro correctamente los datos" << endl;
                    system("pause");
                    break;
                }
            case 1:
                {
                    cls();
                    FILE *pFile1, *pFile2;
                    pFile1 = fopen("lista de canciones.dat", "wb+");
                    pFile2 = fopen(".\\backups\\lista de canciones.bak", "rb");

                    if(pFile1 == nullptr || pFile2 == nullptr){
                        perror("Error al abrir archivos");
                        system("pause");
                        return false;
                    }

                    Cancion regBkp;

                    int cantReg = archivoCanBKP.getCantidadRegistros();
                    std::remove("lista de canciones.dat");

                    for(int i=0; i<cantReg; i++){
                        regBkp = archivoCanBKP.Leer(i);

                        fwrite(&regBkp, sizeof(Cancion), 1, pFile1);
                    }


                    fclose(pFile1);
                    fclose(pFile2);

                    cout << "Se restauro correctamente los datos" << endl;
                    system("pause");
                    break;
                }
            case 2:
                {
                    cls();
                    FILE *pFile1, *pFile2;
                    pFile1 = fopen("lista de historiales.dat", "wb+");
                    pFile2 = fopen(".\\backups\\lista de historiales.bak", "rb");

                    if(pFile1 == nullptr || pFile2 == nullptr){
                        perror("Error al abrir archivos");
                        system("pause");
                        return false;
                    }

                    HistorialUsuario regBkp;

                    int cantReg = archivoHisBKP.getCantidadRegistros();
                    std::remove("lista de historiales.dat");

                    for(int i=0; i<cantReg; i++){
                        regBkp = archivoHisBKP.Leer(i);

                        fwrite(&regBkp, sizeof(HistorialUsuario), 1, pFile1);
                    }


                    fclose(pFile1);
                    fclose(pFile2);

                    cout << "Se restauro correctamente los datos" << endl;
                    system("pause");
                    break;
                }
            case 3:
                {
                    cls();
                    FILE *pFile1, *pFile2;
                    pFile1 = fopen("lista de subscriptores.dat", "wb+");
                    pFile2 = fopen(".\\backups\\lista de subscriptores.bak", "rb");

                    if(pFile1 == nullptr || pFile2 == nullptr){
                        perror("Error al abrir archivos: ");
                        system("pause");
                        return false;
                    }

                    Subscriptor regBkp;

                    int cantReg = archivoSubBKP.getCantidadRegistros();
                    std::remove("lista de subscriptores.dat");

                    for(int i=0; i<cantReg; i++){
                        regBkp = archivoSubBKP.Leer(i);

                        fwrite(&regBkp, sizeof(Subscriptor), 1, pFile1);
                    }


                    fclose(pFile1);
                    fclose(pFile2);

                    cout << "Se restauro correctamente los datos" << endl;
                    system("pause");
                    break;
                }
            case 4:
                {
                    cls();
                    FILE *pFile1, *pFile2, *pFile3, *pFile4;
                    FILE *pFile1BKP, *pFile2BKP, *pFile3BKP, *pFile4BKP;

                    int confirmation;
                    cout << "Usted esta seguro de querer restaurar desde su backup mas reciente? (se borrara todo los datos que tiene hasta el momento)" << endl;
                    cout << "SI = 1     NO = 0" << endl;
                    cin >> confirmation;





                    if(confirmation==0){
                        cout << "Se cancelo el proceso" << endl;
                    }
                    else if(confirmation==1){
                        pFile1 = fopen("lista de artista.dat", "wb+");
                        pFile1BKP = fopen(".\\backups\\lista de artistas.bak", "rb");
                        pFile2 = fopen("lista de canciones.dat", "wb+");
                        pFile2BKP = fopen(".\\backups\\lista de canciones.bak", "rb");
                        pFile3 = fopen("lista de accesos.dat", "wb+");
                        pFile3BKP = fopen(".\\backups\\lista de historiales.bak", "rb");
                        pFile4 = fopen("lista de subscriptores.dat", "wb+");
                        pFile4BKP = fopen(".\\backups\\lista de subscriptores.bak", "rb");

                        if(pFile1 == nullptr || pFile1BKP == nullptr || pFile2 == nullptr || pFile2BKP == nullptr || pFile3 == nullptr || pFile3BKP == nullptr || pFile4 == nullptr || pFile4BKP == nullptr){
                            perror("Error al abrir archivos: ");
                            system("pause");
                            return false;
                        }

                        std::remove("lista de artista.dat");
                        cout << "Se borro lista de artista.dat" << endl;
                        std::remove("lista de canciones.dat");
                        cout << "Se borro lista de canciones.dat" << endl;
                        std::remove("lista de accesos.dat");
                        cout << "Se borro lista de accesos.dat" << endl;
                        std::remove("lista de subscriptores.dat");
                        cout << "Se borro lista de subscriptores.dat" << endl;

                        Artista regBkpArt;
                        Cancion regBkpCan;
                        HistorialUsuario regBkpHis;
                        Subscriptor regBkpSub;

                        if(!validarBKP(regBkpArt, archivoArtBKP, pFile1)){
                            break;
                        }
                        if(!validarBKP(regBkpCan, archivoCanBKP, pFile2)){
                            break;
                        }
                        if(!validarBKP(regBkpHis, archivoHisBKP, pFile3)){
                            break;
                        }
                        if(!validarBKP(regBkpSub, archivoSubBKP, pFile4)){
                            break;
                        }

                        cout << "Se restablecieron los datos desde los backups correctamente" << endl;
                        fclose(pFile1);
                        fclose(pFile2);
                        fclose(pFile3);
                        fclose(pFile4);
                        fclose(pFile1BKP);
                        fclose(pFile2BKP);
                        fclose(pFile3BKP);
                        fclose(pFile4BKP);
                    }
                    else{
                        cout << "Opcion incorrecta" << endl;

                    }

                    system("pause");
                    break;
                }
            case 5:
                {
                    cls();
                    FILE *pFile1, *pFile2, *pFile3, *pFile4;
                    FILE *pFile1INIT, *pFile2INIT, *pFile3INIT, *pFile4INIT;

                    pFile1INIT = fopen(".\\INIT\\lista de artista.init", "rb");
                    pFile2INIT = fopen(".\\INIT\\lista de canciones.init", "rb");
                    pFile3INIT = fopen(".\\INIT\\lista de historiales.init", "rb");
                    pFile4INIT = fopen(".\\INIT\\lista de subscriptores.init", "rb");

                    if(pFile1INIT==nullptr || pFile2INIT==nullptr || pFile3INIT==nullptr || pFile4INIT==nullptr){
                        perror("Error al abrir archivos: ");
                        system("pause");
                        return false;
                    }

                    pFile1 = fopen("lista de artista.dat", "wb+");
                    pFile2 = fopen("lista de canciones.dat", "wb+");
                    pFile3 = fopen("lista de accesos.dat", "wb+");
                    pFile4 = fopen("lista de subscriptores.dat", "wb+");

                    if(pFile1==nullptr || pFile2==nullptr || pFile3==nullptr || pFile4==nullptr){
                        perror("Error al abrir archivos: ");
                        system("pause");
                        return false;
                    }

                    ArchivoArtista archivoArtINI(".\\INIT\\lista de artista.init");
                    ArchivoCancion archivoCanINI(".\\INIT\\lista de canciones.init");
                    ArchivoHistorial archivoHisINI(".\\INIT\\lista de historiales.init");
                    ArchivoSubscriptor archivSubINI(".\\INIT\\lista de subscriptores.init");

                    Artista regArt;
                    Cancion regCan;
                    HistorialUsuario regHis;
                    Subscriptor regSub;

/*
                    ///EN CASO DE SOBREESCRIBIR INIT
                    //cambiar archivos de arriba por wb+ y rb respectivamente
                    //cambiar archivo y registro por el que queres sobreescribir el init
                    //este por ej es para artistas
                    bool ok;
                    for(int i=0; i<archivoArt.getCantidadRegistros(); i++){
                        regArt = archivoArt.Leer(i);
                        ok = fwrite(&regArt, sizeof(Artista), 1, pFile1INIT);
                        if(!ok){
                            cout << "no se guardo bien" << endl;
                            return false;
                        }
                    }
*/


                    if(!validarInit(regArt, archivoArtINI, pFile1)){
                        break;
                    }
                    if(!validarInit(regCan, archivoCanINI, pFile2)){
                        break;
                    }
                    if(!validarInit(regHis, archivoHisINI, pFile3)){
                        break;
                    }
                    if(!validarInit(regSub, archivSubINI, pFile4)){
                        break;
                    }

                    fclose(pFile1INIT);
                    fclose(pFile2INIT);
                    fclose(pFile3INIT);
                    fclose(pFile4INIT);
                    fclose(pFile1);
                    fclose(pFile2);
                    fclose(pFile3);
                    fclose(pFile4);
                    cout << "Se reinicializo correctamente los datos" << endl;
                    system("pause");
                    break;
                }
            case 6:
                {
                    exit = true;
                    break;
                }
            }
        }
    }while(!exit);
    return exit;
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

                    fprintf(pFile, "%d,%d,%d,%s,%d\n",
                            reg.getID(),
                            reg.getIdSong(),
                            reg.getIdSub(),
                            reg.getFecha().c_str(),
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


    return result;
}

bool ManagerConfiguracion::validarInit(Artista reg, ArchivoArtista archivo, FILE *pFileINIT){
    bool ok = false;
    int sizeWrite;
    int cantReg = archivo.getCantidadRegistros();
    for(int i=0; i<cantReg; i++){
        reg = archivo.Leer(i);
        sizeWrite = fwrite(&reg, sizeof(Artista), 1, pFileINIT);
        if(sizeWrite!=1){
            cout << "No se guardo el archivo (Artistas)" << endl;
            return false;
        }
    }

    cout << "Se guardo el archivo exitosamente (Artistas)" << endl;
    return true;
}

bool ManagerConfiguracion::validarInit(Cancion reg, ArchivoCancion archivo, FILE *pFileINIT){
    bool ok = false;
    int sizeWrite;
    int cantReg = archivo.getCantidadRegistros();
    for(int i=0; i<cantReg; i++){
        reg = archivo.Leer(i);
        sizeWrite = fwrite(&reg, sizeof(Cancion), 1, pFileINIT);
        if(sizeWrite!=1){
            cout << "No se guardo el archivo (Canciones)" << endl;
            return false;
        }
    }

    cout << "Se guardo el archivo exitosamente (Canciones)" << endl;
    return true;
}

bool ManagerConfiguracion::validarInit(HistorialUsuario reg, ArchivoHistorial archivo, FILE *pFileINIT){
    bool ok = false;
    int sizeWrite;
    int cantReg = archivo.getCantidadRegistros();
    for(int i=0; i<cantReg; i++){
        reg = archivo.Leer(i);
        sizeWrite = fwrite(&reg, sizeof(HistorialUsuario), 1, pFileINIT);
        if(sizeWrite!=1){
            cout << "No se guardo el archivo (Historiales)" << endl;
            return false;
        }
    }

    cout << "Se guardo el archivo exitosamente (Historiales)" << endl;
    return true;
}

bool ManagerConfiguracion::validarInit(Subscriptor reg, ArchivoSubscriptor archivo, FILE *pFileINIT){
    bool ok = false;
    int sizeWrite;
    int cantReg = archivo.getCantidadRegistros();
    for(int i=0; i<cantReg; i++){
        reg = archivo.Leer(i);
        sizeWrite = fwrite(&reg, sizeof(Subscriptor), 1, pFileINIT);
        if(sizeWrite!=1){
            cout << "No se guardo el archivo (Subscriptores)" << endl;
            return false;
        }
    }

    cout << "Se guardo el archivo exitosamente (Subscriptores)" << endl;
    return true;
}




bool ManagerConfiguracion::validarBKP(Artista reg, ArchivoArtista archivo, FILE *pFile){
    int cant = archivo.getCantidadRegistros();
    int sizeWrite;
    for(int i=0; i<cant; i++){
        reg = archivo.Leer(i);
        sizeWrite = fwrite(&reg, sizeof(Artista), 1, pFile);
        if(sizeWrite!=1){
            cout << "No se guardo el archivo (Artista)" << endl;
            return false;
        }
    }
    cout << "Se restauro el archivo exitosamente (Artista)" << endl;
    return true;
}

bool ManagerConfiguracion::validarBKP(Cancion reg, ArchivoCancion archivo, FILE *pFile){
    int cant = archivo.getCantidadRegistros();
    int sizeWrite;
    for(int i=0; i<cant; i++){
        reg = archivo.Leer(i);
        sizeWrite = fwrite(&reg, sizeof(Cancion), 1, pFile);
        if(sizeWrite!=1){
            cout << "No se guardo el archivo (Cancion)" << endl;
            return false;
        }
    }
    cout << "Se restauro el archivo exitosamente (Cancion)" << endl;
    return true;
}

bool ManagerConfiguracion::validarBKP(HistorialUsuario reg, ArchivoHistorial archivo, FILE *pFile){
    int cant = archivo.getCantidadRegistros();
    int sizeWrite;
    for(int i=0; i<cant; i++){
        reg = archivo.Leer(i);
        sizeWrite = fwrite(&reg, sizeof(HistorialUsuario), 1, pFile);
        if(sizeWrite!=1){
            cout << "No se guardo el archivo (Historial)" << endl;
            return false;
        }
    }
    cout << "Se restauro el archivo exitosamente (Historial)" << endl;
    return true;
}

bool ManagerConfiguracion::validarBKP(Subscriptor reg, ArchivoSubscriptor archivo, FILE *pFile){
    int cant = archivo.getCantidadRegistros();
    int sizeWrite;
    for(int i=0; i<cant; i++){
        reg = archivo.Leer(i);
        sizeWrite = fwrite(&reg, sizeof(Subscriptor), 1, pFile);
        if(sizeWrite!=1){
            cout << "No se guardo el archivo (Subscriptor)" << endl;
            return false;
        }
    }
    cout << "Se restauro el archivo exitosamente (Subscriptor)" << endl;
    return true;
}
