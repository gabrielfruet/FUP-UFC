#include <stdio.h>
#include <limits.h>

int main(){
    int m[2][2];
    int maior = INT_MIN;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            printf("Digite o numero da posicao I:%d J:%d",i,j);
            scanf("%d", &m[i][j]);
            if(m[i][j] > maior){
                maior = m[i][j];
            }
        }
    }
    int r[2][2];
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            r[i][j] = m[i][j]*maior;
            printf("%d, ", r[i][j]);
        }
    }
    puts("");
    return 0;
}
