#include <stdio.h>

//ALGORITMO
//        DECLARE total = 1 NUMERICO
//        DECLARE atual = 1 NUMERICO
//        REPITA
//        INÍCIO
//            total *<- atual
//            ESCREVA "Digite um numero para multiplicar ou zero para terminar: "
//            LEIA  atual
//        FIM
//        ATÉ atual = 0
//        ESCREVA "TOTAL: ", total
//FIM_ALGORITMO.

int main(){
    int total = 1;
    int atual = 1;
    do{
        total *= atual;
        printf("Digite um numero para multiplicar ou zero para terminar: ");
        scanf("%d", &atual);
    }while(atual != 0);
    printf("TOTAL: %d\n", total);
    return 0;
}