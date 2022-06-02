#include <stdio.h>
#include <limits.h>

int main(){
    int m[4][7], menorLINHA = 0, menorVALOR = INT_MAX;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 7; j++){
            printf("Digite um numero para a posicao I: %d e J: %d: ",i,j);
            scanf("%d", &m[i][j]);
        }
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 7; j++){
            if(m[i][j] < menorVALOR){
                menorVALOR = m[i][j];
                menorLINHA = i;
            }
        }
    }
    int maiorVALOR = INT_MIN, maiorCOLUNA;
    for(int j = 0; j < 7; j++){
        if(m[menorLINHA][j] > maiorVALOR){
            maiorVALOR = m[menorLINHA][j];
            maiorCOLUNA = j;
        }
    }
    printf("POSICAO I: %d e J: %d\n", menorLINHA, maiorCOLUNA);
}