#include <iostream>
#include <cstring>
#include "reporte.h"
#include "rlutils.h"
#include "suscriptor.h"
#include "archivosSuscriptor.h"
#include "arrayUtils.h"
#include "archivoArtista.h"
#include "artista.h"
#include "cancion.h"
#include "archivosCancion.h"
#include "acceso.h"
#include "archivoAcceso.h"
using namespace std;
using namespace rlutil;

///Para calcular edades
const int _anioActual = 2025;
const int _mesActual = 6;
const int _diaActual = 1;

void ManagerReporte::mostrarSubmenuReportes(){
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
        cout << "Velvet Note Reports" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "------------------------" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "1- Canciones mas escuchadas" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "2- Promedio y moda de edades" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "3- Cantidad de canciones por artista" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "4- Artistas mas escuchados" << endl;
        locate(tcols()/3,i);
        i++;
        cout << "5- Genero mas escuchado" << endl;
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
                //Canciones más escuchadas
                cancionesMasEscuchadas();
                break;
            case 1:
                cls();
                //Promedio y moda de edades
                promedioModaEdades();
                break;
            case 2:
                cls();
                //Cantidad de canciones por artista
                cantidadCancionesPorArtista();
                break;
            case 3:
                cls();
                //Artistas más escuchados
                artistasMasEscuchados();
                break;
            case 4:
                cls();
                //Genero mas escuchado
                generoMasEscuchado();
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



void ManagerReporte::cancionesMasEscuchadas(){

    system("pause");
}

void ManagerReporte::promedioModaEdades(){
    ArchivoSubscriptor archivoSub("lista de subscriptores.dat");
    Subscriptor reg;
    int promedioSuma = 0;

    int cantReg = archivoSub.getCantidadRegistros();
    int *cantEdades = new int[cantReg];

    if(cantEdades==nullptr){
        perror("Error al crear array");
        system("pause");
        return;
    }

    ///get todas las edades
    for(int i=0; i<cantReg; i++){
        reg = archivoSub.Leer(i);
        *(cantEdades+i) = reg.getEdad(_diaActual, _mesActual, _anioActual);
        promedioSuma += *(cantEdades+i);
    }

    ///PROMEDIO
    float promedio = (float)promedioSuma/cantReg;
    cout << "Promedio de edades de los subscriptores: " << promedio << endl;


    ///MODA
    int* edadesUnicas = new int[cantReg];
    int* frecuencias = new int[cantReg];
    int totalUnicas = 0;

    ///creacion de arrays de edades unicas y su frecuencias
    for(int i=0; i<cantReg; i++) {
        int edadActual = cantEdades[i];
        bool encontrada = false;

        ///contamos la frecuencia de cada edad unica
        for (int j=0; j<totalUnicas; j++) {
            if (edadesUnicas[j]==edadActual) {
                frecuencias[j]++;
                encontrada = true;
                break;
            }
        }

        ///si el numero actual en el array de edades no existe,
        ///lo agregamos al array de edades unicas
        if (!encontrada) {
            edadesUnicas[totalUnicas] = edadActual;
            frecuencias[totalUnicas] = 1;
            totalUnicas++;
        }
    }

    ///buscar la moda
    int moda = edadesUnicas[0];
    int maxFrecuencia = frecuencias[0];

    for (int i = 1; i < totalUnicas; i++) {
        if (frecuencias[i] > maxFrecuencia) {
            moda = edadesUnicas[i];
            maxFrecuencia = frecuencias[i];
        }
    }

    cout << "Moda de edad: " << moda << " (frecuencia: " << maxFrecuencia << ")" << endl;


    delete[] cantEdades;
    delete[] edadesUnicas;
    delete[] frecuencias;
    system("pause");
}

void ManagerReporte::cantidadCancionesPorArtista(){
    Cancion regCan;
    ArchivoCancion archivoCancion("lista de canciones.dat");
    Artista regArt;
    ArchivoArtista archivoArtista("lista de artista.dat");

    int cantArtistas = archivoArtista.getCantidadRegistros();
    int cantCanciones = archivoCancion.getCantidadRegistros();

    int *cantCancionesPorArtista = new int[cantArtistas];
    llenarArray(cantCancionesPorArtista, cantArtistas);

    int idArt;
    for(int i=0; i<cantCanciones; i++) {
        regCan = archivoCancion.Leer(i);
        idArt = regCan.getIDArtista() - 1;
        if(idArt>=0 && idArt<cantArtistas) {
            cantCancionesPorArtista[idArt]++;
        }
    }


    for(int i=0; i<cantArtistas; i++) {
        regArt = archivoArtista.Leer(i);
        cout << regArt.getNombre() << ": " << cantCancionesPorArtista[i] << endl;
    }


    delete []cantCancionesPorArtista;
    system("pause");
}

void ManagerReporte::artistasMasEscuchados(){
    Artista regArt;
    ArchivoArtista archivoArtista("lista de artista.dat");
    HistorialUsuario regHistorial;
    ArchivoHistorial archivoHistorial("lista de accesos.dat");
    Cancion regCan;
    ArchivoCancion archivoCancion("lista de canciones.dat");

    int cantArtistas = archivoArtista.getCantidadRegistros();
    int *vArtistasVistas = new int[cantArtistas];
    llenarArray(vArtistasVistas, cantArtistas);

    int cantHistoriales = archivoHistorial.getCantidadRegistros();

    for(int i=0; i<cantHistoriales; i++){
        regHistorial = archivoHistorial.Leer(i);
        int idCancion = regHistorial.getIdSong()-1;
        regCan = archivoCancion.Leer(idCancion);
        int idArtista = regCan.getIDArtista()-1;

        vArtistasVistas[idArtista]++;
    }

    for(int i=0; i<cantArtistas; i++){
        regArt = archivoArtista.Leer(i);
        cout << regArt.getNombre() << ": " << vArtistasVistas[i] << endl;
    }

    system("pause");
}

void ManagerReporte::generoMasEscuchado(){
    Artista regArt;
    ArchivoArtista archivoArtista("lista de artista.dat");
    HistorialUsuario regHistorial;
    ArchivoHistorial archivoHistorial("lista de accesos.dat");
    Cancion regCan;
    ArchivoCancion archivoCancion("lista de canciones.dat");




    system("pause");
}
