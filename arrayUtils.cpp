#include <iostream>
#include <cstring>
#include "arrayUtils.h"
using namespace std;

void arrayordenar(int *v, int tam){
    int posmin, aux;

    for(int i = 0; i < tam - 1; i++) {
        posmin = i;
        for(int j = i + 1; j < tam; j++) {
            if(v[j] < v[posmin]) {
                posmin = j;
            }
        }

        aux = v[i];
        v[i] = v[posmin];
        v[posmin] = aux;
    }
}

void ordenarMayorMenor(int *v, int tam){
    int posmax, aux;

    for(int i=0; i<tam-1; i++) {
        posmax = i;
        for(int j=i+1; j<tam; j++) {
            if(v[j]>v[posmax]) {
                posmax = j;
            }
        }

        aux = v[i];
        v[i] = v[posmax];
        v[posmax] = aux;
    }
}

void ordenar_m_col(int (*m)[5], int fila, int col){
    int i,j,k,nf,aux;
    for(k = 0;k<col;k++){
        for(i = 0;i<fila-1;i++){
            nf = i;
            for(j=i+1;j<fila;j++){
                if(m[j][k]>m[nf][k]){
                    nf = j;
                }
            }
            aux = m[i][k];
            m[i][k] = m[nf][k];
            m[nf][k] = aux;
        }
    }

}

void ordenar_m_fila(int (*m)[5], int fila, int col){
    int i,j,k,nc,aux;

    for(k=0; k<fila; k++){
        for(i=0; i<col-1; i++){
            nc = i;
            for(j=i+1; j<col; j++){
                if(m[k][j]>m[k][nc]){
                    nc = j;
                }
            }
            aux = m[k][i];
            m[k][i] = m[k][nc];
            m[k][nc] = aux;
        }
    }

}

void llenarArray(int *v, int tam){
    for(int i=0; i<tam; i++){
        *(v+i)=0;
    }
}

void mostrarArray(int *v, int tam){
    for(int i=0; i<tam; i++){
        std::cout << *(v+i) << std::endl;
    }
}
void mostrarArray(std::string *v, int tam){
    for(int i=0; i<tam; i++){
        std::cout << *(v+i) << std::endl;
    }
}

int contarUnicos(int *v, int n) {
    int unicos = 0;

    for(int i=0; i<n; i++) {
        bool yaContado=false;
        // Verifica si v[i] ya fue contado antes
        for(int j=0; j<i; j++) {
            if(v[i]==v[j]) {
                yaContado=true;
                break;
            }
        }
        if(!yaContado){
            unicos++;
        }
    }

    return unicos;
}
int contarUnicos(std::string *v, int n) {
    int unicos = 0;

    for(int i=0; i<n; i++) {
        bool yaContado=false;
        // Verifica si v[i] ya fue contado antes
        for(int j=0; j<i; j++) {
            if(v[i]==v[j]) {
                yaContado=true;
                break;
            }
        }
        if(!yaContado){
            unicos++;
        }
    }

    return unicos;
}

void ordenarFrecuenciasYGeneros(int* vFrecuencias, std::string* vGeneros, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int posMax = i;
        for (int j = i + 1; j < tam; j++) {
            if (vFrecuencias[j] > vFrecuencias[posMax]) {
                posMax = j;
            }
        }

        // Intercambio en el vector de frecuencias
        int auxFrecuencia = vFrecuencias[i];
        vFrecuencias[i] = vFrecuencias[posMax];
        vFrecuencias[posMax] = auxFrecuencia;

        // Intercambio en el vector de géneros (mantener sincronía)
        std::string auxGenero = vGeneros[i];
        vGeneros[i] = vGeneros[posMax];
        vGeneros[posMax] = auxGenero;
    }
}

std::string toLowerCase(std::string str) {
    for(int i=0; i<str.length(); i++) {
        // Si es mayúscula, convertirla restando la diferencia
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
    return str;
}

int getDiaDesdeSTR(std::string diaSTR){
    char slash = '/';
    int slashInt = (int)slash;
    int vDia[2] = {};

    int contadorSlashes = 0;
    int dia = 0;
    for(int  i=0; i<diaSTR.length(); i++) {
        if(diaSTR[i]==slash) {
            contadorSlashes++;
        }

        if(contadorSlashes==1){
            if(i==2){
                vDia[0] = diaSTR[0] - '0';
                vDia[1] = diaSTR[1] - '0';

                dia = vDia[0]*10 + vDia[1];
                break;
            }
            else if(i==1){
                vDia[0] = 0;
                vDia[1] = diaSTR[0] - '0';

                dia = vDia[1];
                break;
            }
        }
    }

    return dia;
}

int getMesDesdeSTR(std::string mesSTR){
    char slash = '/';
    int slashInt = (int)slash;
    int vMes[2] = {};

    int contadorSlashes = 0;
    int mes = 0;
    for(int  i=0; i<mesSTR.length(); i++) {
        if(mesSTR[i]==slash) {
            contadorSlashes++;
            continue;
        }

        if(contadorSlashes==1){
            if(mesSTR[i+1]==slash){
                mes = mesSTR[i] - '0';
                break;
            }
            else if(mesSTR[i+1]!=slash){
                vMes[0] = mesSTR[i] - '0';
                vMes[1] = mesSTR[i+1] - '0';
                mes = vMes[0]*10 + vMes[1];
                break;
            }
        }

    }

    return mes;
}

int getAnioDesdeSTR(std::string anioSTR){
    char slash = '/';
    int slashInt = (int)slash;
    int vAnio[4] = {};
    int indexAnio = 0;

    int contadorSlashes = 0;
    for(int  i=0; i<anioSTR.length(); i++) {
        if(anioSTR[i]==slash) {
            contadorSlashes++;
            continue;
        }

        if(contadorSlashes==2 && indexAnio<4) {
            // Convertimos de char '2' a int 2 restando '0' que es 48 en int
            vAnio[indexAnio] = anioSTR[i] - '0';
            indexAnio++;
        }
    }

    int anio = 0;
    int unidades = 1000;

    for(int i=0; i<4; i++){
        anio += vAnio[i]*unidades;
        unidades /= 10;
    }

    return anio;
}
