#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n;
    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);
    int m[2][n][n];
    for(int k = 0; k < 2; k++){
        printf("Preencha a matriz %c: \n", 'A' + k);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &m[k][i][j]);
            }
        }
    }
    bool anti_simetrica = 1;
    int (*A)[n] = m[0], (*B)[n] = m[1];
    for(int i = 0; i < n && anti_simetrica; i++){
        for(int j = 0; j < n && anti_simetrica; j++){
           if(i == j && (A[i][j] || B[i][j])){
                anti_simetrica = 0;                
           }else if(A[i][j] != -B[i][j]){
               anti_simetrica = 0;
           }
        }
    }
    if(anti_simetrica){
        printf("SAO ANTI-SIMETRICAS!\n");
    }else{
        printf("NAO SAO ANTI-SIMETRICAS!\n");
    }
    return 0;
}
