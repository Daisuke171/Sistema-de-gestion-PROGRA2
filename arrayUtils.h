#ifndef ARRAYUTILS_H_INCLUDED
#define ARRAYUTILS_H_INCLUDED

#include <iostream>

void ordenar(int *v, int tam){
    int posmin, aux;

    for(int i=0; i<tam-1; i++){
        posmin = i;
        for(int j=i+1; j<tam; j++)

        if(v[j]<v[posmin]){
            posmin=j;
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



#endif // ARRAYUTILS_H_INCLUDED
