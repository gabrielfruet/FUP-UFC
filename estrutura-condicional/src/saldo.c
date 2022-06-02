#include <stdio.h>

// ALGORITMO VISUALG
// 	DECLARE saldo, credito NUMERICO
// 	ESCREVA "Digite seu saldo medio no ultimo ano: "
// 	LEIA  saldo
// 	SE saldo>400 ENTAO
// 		credito <- saldo * 0.3
// 	SE saldo>300 E saldo<=400 ENTAO
// 		credito <- saldo * 0.25
// 	SE saldo>200 E saldo<=300 ENTAO
// 		credito <- saldo * 0.2
// 	SENÃO
// 		credito <- saldo * 0.10
// 	FIMSE
// 	ESCREVAL "Saldo medio: R$", saldo
// 	ESCREVAL "Valor do credito: R$", credito
// FIM_ALGORITMO.

int main(){
    float saldo, credito;
    printf("Digite seu saldo medio no ultimo ano: ");
    scanf("%f", &saldo);
    if(saldo > 400){
        credito = saldo * 0.3;
    }else if(saldo > 300){
        credito = saldo * 0.25;
    }else if(saldo > 200){
        credito = saldo * 0.2;
    }else{
        credito = saldo * 0.10;
    }
    printf("Saldo medio: R$%.2f\n", saldo);
    printf("Valor do credito: R$%.2f\n", credito);
    return 0;
}