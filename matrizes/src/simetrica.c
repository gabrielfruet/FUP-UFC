#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n;
    printf("Digite o tamanho da matriz quadrada: ");
    scanf("%d", &n);
    int m[2][n][n];
    for(int k = 0; k < 2; k++){
        printf("Preencha a matriz: %c\n", 'A' + k);
        for(int i = 0; i < n; i++){
           for(int j = 0; j < n; j++){
               printf("Insira o elemento da linha %d e coluna %d: ", i,j);
               scanf("%d", &m[k][i][j]);
           } 
        }
    }
    bool simetrica = 1;
    int (*A)[n] = *m, (*B)[n] = *(m + 1);
    for(int i = 0; i < n && simetrica; i++){
        for(int j = 0; j < n && simetrica; j++){
            if(A[i][j] != B[j][i]){
                simetrica = 0;
            }
        }
    }
    if(simetrica){
        printf("SAO SIMETRICAS!\n");
    }else{
        printf("NAO SAO SIMETRICAS!\n");
    }
    
    return 0;
}
