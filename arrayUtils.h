#ifndef ARRAYUTILS_H_INCLUDED
#define ARRAYUTILS_H_INCLUDED

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



#endif // ARRAYUTILS_H_INCLUDED
