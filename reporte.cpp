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
    Cancion regCancion;
    ArchivoCancion archivoCancion("lista de canciones.dat");
    HistorialUsuario regHistorial;
    ArchivoHistorial archivoHistorial("lista de accesos.dat");

    int cantHistoriales = archivoHistorial.getCantidadRegistros();
    HistorialUsuario *vHistoriales = new HistorialUsuario[cantHistoriales];
    archivoHistorial.leerMuchos(vHistoriales, cantHistoriales);
    int cantCanciones = archivoCancion.getCantidadRegistros();
    int *vFrecuenciasCanciones = new int[cantCanciones];
    llenarArray(vFrecuenciasCanciones, cantCanciones);

    for(int i=0; i<cantHistoriales; i++){
        int idCancionHistorial = vHistoriales[i].getIdSong() - 1;

        *(vFrecuenciasCanciones+idCancionHistorial) += 1;
    }

    string *vCancionesNombres = new string[cantCanciones];
    for(int i=0; i<cantCanciones; i++){
        regCancion = archivoCancion.Leer(i);
        *(vCancionesNombres+i) = regCancion.getNombre();
    }
    ordenarFrecuenciasYGeneros(vFrecuenciasCanciones, vCancionesNombres, cantCanciones);

    int select;
    cout << "Quiere ver todas las frecuencias o solamente el top 3? (0=todos, 1=top)" << endl;
    cin >> select;
    cls();
    switch(select){
    case 1:
        {
            for(int i=0; i<3; i++){
                cout << "TOP " << i+1 << " " << vCancionesNombres[i] << ": " << vFrecuenciasCanciones[i] << " vistas" << endl;
            }
            break;
        }
    case 0:
        {
            for(int i=0; i<cantCanciones; i++){
                cout << vCancionesNombres[i] << ": " << vFrecuenciasCanciones[i] << " vistas" << endl;
            }
            break;
        }
    default:
        {
            cout << "Opcion incorrecta" << endl;
            break;
        }
    }


    delete []vCancionesNombres;
    delete []vHistoriales;
    delete []vFrecuenciasCanciones;
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

    int cantCancionesReg = archivoCancion.getCantidadRegistros();
    Cancion *vCanciones = new Cancion[cantCancionesReg];
    archivoCancion.leerMuchos(vCanciones, cantCancionesReg);

    int cantArtistasReg = archivoArtista.getCantidadRegistros();
    Artista *vArtistas = new Artista[cantArtistasReg];
    archivoArtista.leerMuchos(vArtistas, cantArtistasReg);

    int *vCancionesPorArtista = new int[cantArtistasReg];
    llenarArray(vCancionesPorArtista, cantArtistasReg);


    for(int i=0; i<cantCancionesReg; i++){
        cout << vCanciones[i].getNombre() << ": " << vCanciones[i].getIDArtista() <<endl;
    }

    /*
    for(int i=0; i<cantArtistasReg; i++){
        cout << vArtistas[i].getNombre() << ": " << vCancionesPorArtista[i] << endl;
    }
*/

    delete []vArtistas;
    delete []vCancionesPorArtista;
    delete []vCanciones;
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

    string *vArtistasNombres = new string[cantArtistas];
    for(int i=0; i<cantArtistas; i++){
        regArt = archivoArtista.Leer(i);
        *(vArtistasNombres+i) = regArt.getNombre();
    }

    ordenarFrecuenciasYGeneros(vArtistasVistas, vArtistasNombres, cantArtistas);

    int select;
    cout << "Quiere ver todas las frecuencias o solamente el top 3? (0=todos, 1=top)" << endl;
    cin >> select;
    cls();
    switch(select){
    case 1:
        {
            for(int i=0; i<3; i++){
                cout << "TOP " << i+1 << " " << vArtistasNombres[i] << ": " << vArtistasVistas[i] << " vistas" << endl;
            }
            break;
        }
    case 0:
        {
            for(int i=0; i<cantArtistas; i++){
                cout << vArtistasNombres[i] << ": " << vArtistasVistas[i] << " vistas" << endl;
            }
            break;
        }
    default:
        {
            cout << "Opcion incorrecta" << endl;
            break;
        }
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

    ///CREACION DE VECTOR CON GENEROS UNICOS
    int cantArt = archivoArtista.getCantidadRegistros();

    Artista *vArtistas = new Artista[cantArt];
    archivoArtista.leerMuchos(vArtistas, cantArt);

    if(vArtistas==nullptr){
        cout << "Error en la asignacion de memoria" << endl;
        exit(-1);
    }

    std::string *vGeneros = new std::string[cantArt];
    for(int i=0; i<cantArt; i++){
        *(vGeneros+i) = vArtistas[i].getGenero();
    }

    int cantGenerosUnicos = contarUnicos(vGeneros, cantArt);


    std::string* vGenerosUnicos = new std::string[cantGenerosUnicos];
    vGenerosUnicos[0] = vGeneros[0];
    int contadorUnicos = 1;

    for(int i=1; i<cantArt; i++) {
        bool seEncontro = false;

        for(int j=0; j<contadorUnicos; j++) {
            if(vGenerosUnicos[j]==vGeneros[i]) {
                seEncontro = true;
                break;
            }
        }

        if(!seEncontro) {
            vGenerosUnicos[contadorUnicos] = vGeneros[i];
            contadorUnicos++;

            if(contadorUnicos==cantGenerosUnicos) {
                break;
            }
        }
    }
    ///CREACION DE VECTOR CON GENEROS UNICOS



    ///ACTUALIZAMOS LA FRECUENCIA EN LA QUE FUE ESCUCHADA CADA GENERO
    int cantHistoriales = archivoHistorial.getCantidadRegistros();
    HistorialUsuario *vHistoriales = new HistorialUsuario[cantHistoriales];
    archivoHistorial.leerMuchos(vHistoriales, cantHistoriales);

    int cantCanciones = archivoCancion.getCantidadRegistros();
    Cancion *vCanciones = new Cancion[cantCanciones];
    archivoCancion.leerMuchos(vCanciones, cantCanciones);

    int *vFrecuencias = new int[cantGenerosUnicos];
    llenarArray(vFrecuencias, cantGenerosUnicos);
    for(int i=0; i<cantHistoriales; i++){
        for(int j=0; j<cantArt; j++){
            if(vCanciones[j].getID()==vHistoriales[i].getIdSong()){
                std::string genero = vArtistas[vCanciones[j].getIDArtista()-1].getGenero();
                for(int g=0; g<cantGenerosUnicos; g++){
                    if(genero==vGenerosUnicos[g]){
                        vFrecuencias[g]++;
                    }
                }
            }
        }
    }
    ///ACTUALIZAMOS LA FRECUENCIA EN LA QUE FUE ESCUCHADA CADA GENERO


    ///ORDENAMIENTO Y LISTADO FINAL
    ordenarFrecuenciasYGeneros(vFrecuencias, vGenerosUnicos, cantGenerosUnicos);

    int select;
    cout << "Quiere ver todas las frecuencias o solamente el top 3? (0=todos, 1=top)" << endl;
    cin >> select;
    cls();
    switch(select){
    case 1:
        {
            for(int i=0; i<3; i++){
                cout << "TOP " << i+1 << " " << vGenerosUnicos[i] << ": " << vFrecuencias[i] << endl;
            }
            break;
        }
    case 0:
        {
            for(int i=0; i<cantGenerosUnicos; i++){
                cout << vGenerosUnicos[i] << ": " << vFrecuencias[i] << endl;
            }
            break;
        }
    default:
        {
            cout << "Opcion incorrecta" << endl;
            break;
        }
    }
    ///ORDENAMIENTO Y LISTADO FINAL

    delete []vFrecuencias;
    delete []vHistoriales;
    delete []vGeneros;
    delete []vGenerosUnicos;
    delete []vArtistas;
    delete []vCanciones;
    system("pause>null");
}
