#ifndef ARRAYUTILS_H_INCLUDED
#define ARRAYUTILS_H_INCLUDED

#include <iostream>
#include <cstring>
using namespace std;

void ordenar(int *v, int tam);
void ordenarMayorMenor(int *v, int tam);

void ordenar_m_col(int (*m)[5], int fila, int col);

void ordenar_m_fila(int (*m)[5], int fila, int col);

void llenarArray(int *v, int tam);

void mostrarArray(int *v, int tam);
void mostrarArray(std::string *v, int tam);

int contarUnicos(int *v, int n);
int contarUnicos(std::string *v, int n);

void ordenarFrecuenciasYGeneros(int* vFrecuencias, std::string* vGeneros, int tam);

std::string toLowerCase(std::string str);

int getDiaDesdeSTR(std::string diaSTR);
int getMesDesdeSTR(std::string mesSTR);
int getAnioDesdeSTR(std::string anioSTR);

#endif // ARRAYUTILS_H_INCLUDED
