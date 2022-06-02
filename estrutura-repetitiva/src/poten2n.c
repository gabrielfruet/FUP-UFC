#include <stdio.h>
#include <math.h>

//ALGORITMO
//        DECLARE qntd NUMERICO
//        ESCREVA "Digite quantas potencias de 2 voce deseja imprimir: "
//        LEIA  qntd
//        PARA  i <- 0 ATÉ     qntd FAÇA
//        INÍCIO
//            ESCREVA " : %lld\n", i + 1, (long long)pow(2, i + 1)
//        FIM
//FIM_ALGORITMO.

int main(){
    int qntd;
    printf("Digite quantas potencias de 2 voce deseja imprimir: ");
    scanf("%d", &qntd);
    for(int i = 0; i < qntd; i++){
        printf("%d : %lld\n", i + 1, (long long)pow(2, i + 1));
    }
    return 0;
}