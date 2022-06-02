#include "stdio.h"

int main(){
    int qntd;
    double soma;
    printf("Digite a quantidade de operacoes: ");
    scanf("%d", &qntd);
    for(double i = 1; i <= qntd; i++){
        soma += 1/i;
    }
    printf("RESULTADO: %lf\n", soma);
    return 0;
}