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
    ManagerConfiguracion a;

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
                if(y>4){
                    y=4;
                }
                break;
        case 1: /// 1 = ENTER
            switch(y){
            case 0:
                {
                cls();
                ///ADMIN VALIDATION
                //logon();

                FILE *pFile;
                pFile = fopen("artistas.csv", "wb+"); // "w" para escribir nuevo archivo
                if (pFile == nullptr) {
                    perror("Error al abrir archivo");
                    return false;
                }

                int regCant = archivoArt.getCantidadRegistros();
                if (regCant == 0) {
                    cout << "No hay registros para exportar." << endl;
                    fclose(pFile);
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
                //logon();

                FILE *pFile;
                pFile = fopen("canciones.csv", "wb+"); // "w" para escribir nuevo archivo
                if (pFile == nullptr) {
                    perror("Error al abrir archivo");
                    return false;
                }

                int regCant = archivoCan.getCantidadRegistros();
                if (regCant == 0) {
                    cout << "No hay registros para exportar." << endl;
                    fclose(pFile);
                    break;
                }

                // Escribir encabezados
                fprintf(pFile, "ID,Nombre,Autor,Genero,Fecha publicacion\n");
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
                //logon();

                FILE *pFile;
                pFile = fopen("historiales.csv", "wb+"); // "w" para escribir nuevo archivo
                if (pFile == nullptr) {
                    perror("Error al abrir archivo");
                    return false;
                }

                int regCant = archivoCan.getCantidadRegistros();
                if (regCant == 0) {
                    cout << "No hay registros para exportar." << endl;
                    fclose(pFile);
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
                //logon();

                FILE *pFile;
                pFile = fopen("subscriptores.csv", "wb+"); // "w" para escribir nuevo archivo
                if (pFile == nullptr) {
                    perror("Error al abrir archivo");
                    return false;
                }

                int regCant = archivoSub.getCantidadRegistros();
                if (regCant == 0) {
                    cout << "No hay registros para exportar." << endl;
                    fclose(pFile);
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
                return 1;
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
    return result;
}

