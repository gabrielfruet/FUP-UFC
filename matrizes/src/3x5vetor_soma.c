#include <stdio.h>

int main(){
    int m[3][5], v[3];
    printf("Preencha a matriz 3x5: ");
    for(int i=0; i<3; i++){
        v[i] = 0;
        for(int j=0; j<5; j++){
            printf("Digite o elemento da posicao i:%d e j:%d: ", i, j);
            scanf("%d",&m[i][j]);
            v[i] += m[i][j];
        }
    }
    printf("Vetor soma: ");
    for(int i=0; i<3; i++){
        printf("%d\t", v[i]);
    }
    return 0;
}
