#include <stdio.h>

int main(){
    int m[4][4];
    puts("Preencha a matriz 4x4: ");
    for(int i = 0; i < 4; i++){
       for(int j = 0; j < 4; j++){
            printf("Preencha a posicao i:%d e j:%d: ",i,j);
            scanf("%d", &m[i][j]);
       }
    }
    puts("Diagonal principal: ");
    for(int i = 0; i < 4; i++){
        printf("%d\t",m[i][i]);
    }
    return 0;
}
