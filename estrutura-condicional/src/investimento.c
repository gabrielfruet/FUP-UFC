#include <stdio.h>
#include <stdlib.h>

// ALGORITMO VISUALG
// 	DECLARE opcao NUMERICO
// 	DECLARE valor, rendimento NUMERICO
// 	ESCREVA "Digite o valor do seu investimento: "
// 	LEIA  valor
// 	LEIA  opcao
//  ESCREVAL "Selecione o tipo de investimento: "
//  ESCREVAL "1 - POUPANCA"
//  ESCREVAL "2 - FUNDO DE RENDA FIXA"
// 	ESCOLHA opcao
//      CASO 1 FACA
// 		    rendimento <- valor*0.1
// 		    PARE
//      CASO 2 FACA
// 		    rendimento <- valor*0.15
// 		    PARE
//      CASO PADRAO FACA
//          ESCREVAL "Opcao invalida!"
//          SAIR
// 	FIM-ESCOLHA
// 	ESCREVAL "Valor total corrigido: R$", valor + rendimento
// 	ESCREVAL "Valor do rendimento: R$", rendimento
// FIM_ALGORITMO.

int main(){
    int opcao;
    float valor, rendimento;
    printf("Digite o valor do seu investimento: ");
    scanf("%f", &valor);
    puts("Selecione o tipo de investimento: ");
    puts("1 - POUPANCA");
    puts("2 - FUNDO DE RENDA FIXA");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            rendimento = valor*0.1;
            break;
        case 2:
            rendimento = valor*0.15;
            break;
        default:{
            puts("Opcao invalida!");
            exit(1);
        }
    }
    printf("Valor total corrigido: R$%.2f\n", valor + rendimento);
    printf("Valor do rendimento: R$%.2f\n", rendimento);
    return 0;
}