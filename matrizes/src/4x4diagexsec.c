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
    puts("Diagonal secundaria: ");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(3 - i != j){
                printf("%d\t",m[i][j]);
            }
        }
    }
    return 0;
}
