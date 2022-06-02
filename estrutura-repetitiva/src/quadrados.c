#include "stdio.h"

int main(){
    int qntd;
    printf("Digite quantos numeros dessa serie voce deseja: ");
    scanf("%d", &qntd);
    int i;
    for(i = 1; i < qntd; i++){
        printf("%d, ", i*i);
    }
    printf("%d\n", i*i);
    return 0;
}