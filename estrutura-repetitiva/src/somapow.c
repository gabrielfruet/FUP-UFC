#include "stdio.h"
#include "math.h"

int main(){
    double soma;
    int qntd;
    printf("Quantidade de numeros na serie: ");
    scanf("%d", &qntd);
    for(int i = 1; i <= qntd; i++){
        soma += 1/pow(i,i);
    }
    printf("RESULTADO: %lf", soma);
    return 0;
}