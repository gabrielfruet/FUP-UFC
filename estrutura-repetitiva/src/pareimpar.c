#include <stdio.h>

int main(){
    int qntd;
    printf("Quantos numeros voce quer digitar?");
    scanf("%d", &qntd);
    int par = 0, impar = 0, atual = 0;
    for(int i = 0; i < qntd; i++){
        printf("Digite um numero: ");
        scanf("%d", &atual);
        if(atual % 2){
            impar++;
        }else{
            par++;
        }
    }
    printf("%d IMPARES, %d PARES\n", impar, par);
    return 0;
}