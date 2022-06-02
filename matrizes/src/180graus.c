#include <stdio.h>
#include <stdlib.h>

void imprime_matriz(const int m, const int n, int mat[m][n]){
    printf("[\n");
    for(int i = 0; i < m; i++){
        printf("[");
        for(int j = 0; j < n; j++){
            printf("%d", mat[i][j]);
            if(j != n - 1) printf("\t");
        }
        printf("],\n");
    }
    printf("]\n");
}

int main(){
    int m[3][3];
    printf("Preencha a matriz para girar 180graus: \n");
    for(int i = 0; i < 3; i++){
        printf("Preencha a linha %d: \n", i);
        for(int j = 0; j < 3; j++){
            scanf("%d", &m[i][j]);
        }
    }
    printf("MATRIZ ORIGINAL\n");
    imprime_matriz(3, 3, m);
    /*int m_g[3][3] = {*/
        /*{m[2][2], m[2][1], m[2][0]},*/
        /*{m[1][2], m[1][1], m[1][0]},*/
        /*{m[0][2], m[0][1], m[0][0]}*/
    /*};*/
    /*puts("MATRIZ REFERENCIA: ");*/
    /*imprime_matriz(3, 3, m_g);*/
    int m_r[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
           m_r[i][j] = m[2 - i][2 - j];
        }
    }
    puts("MATRIZ RESULTANTE: ");
    imprime_matriz(3, 3, m_r);
    return 0;
}

