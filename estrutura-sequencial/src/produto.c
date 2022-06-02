#include <stdio.h>

// ALGORITMO
// 	DECLARE produtoInicial = 0, NUMERICO
// 	desconto <- 0.1,
// 	produtoFinal <- 0
// 	ESCREVA "Digite o preco inicial do produto: "
// 	LEIA  produtoInicial
// 	produtoFinal <- (1 - desconto)*produtoInicial
// 	ESCREVA "Preco apos o desconto: ", produtoFinal
// FIM_ALGORITMO.

int main() {
    float produtoInicial = 0,
    desconto = 0.1,
    produtoFinal = 0;

    printf("Digite o preco inicial do produto: ");
    scanf("%f", &produtoInicial);
    produtoFinal = (1 - desconto)*produtoInicial;
    printf("Preco apos o desconto: R$%.2f", produtoFinal);
}
