#include "stdio.h"
#include "limits.h"

int main(){
    double mediaPar = 0, mediaImpar = 0;
    int totalPar, totalImpar;
    int maiorPar = INT_MIN, menorImpar = INT_MAX;
    int input = 0;
    while(input >= 0){
        printf("Digite um numero ou um negativo para sair: ");
        scanf("%d", &input);
        if(input >= 0){
            if(input % 2 == 0){
                totalPar++;
                if(input > maiorPar){
                    maiorPar = input;
                }
                mediaPar += input;
            }else{
                totalImpar++;
                if(input < menorImpar){
                    menorImpar = input;
                }
                mediaImpar += input;
            }
        }
    }
    printf("MEDIA PAR: %lf\n", mediaPar/totalPar);
    printf("MEDIA IMPAR: %lf\n", mediaImpar/totalImpar);
    printf("MAIOR PAR: %d\n", maiorPar);
    printf("MENOR IMPAR: %d\n", menorImpar);
}