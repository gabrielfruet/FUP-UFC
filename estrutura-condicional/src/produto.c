#include <stdio.h>

// ALGORITMO VISUALG
// 	DECLARE preco NUMERICO
// 	DECLARE  classificacao LITERAL
// 	ESCREVA "Digite o preco do produto: "
// 	LEIA  preco
// 	SE preco>100 ENTAO
// 		preco *<- 1.15
// 	SENAO SE preco>50 ENTAO
// 		preco *<- 1.10
// 	SENÃO
// 		preco *<- 1.05
// 	FIMSE
//
// 	SE preco>200 ENTAO
//      classificacao <- 'A'
// 	SENAO SE preco>120 E preco<=200 ENTAO
//      classificacao <- 'B'
// 	SENAO SE preco>80 E preco<=120 ENTAO
//      classificacao <- 'C'
// 	SENÃO
//      classificacao <- 'D'
//  FIMSE
// 	ESCREVA "Novo preco: R$%.2f\n", preco
// 	ESCREVA "Classificacao: \n", classificacao
// FIM_ALGORITMO.

int main(){
    float preco;
    char classificacao;
    printf("Digite o preco do produto: ");
    scanf("%f", &preco);
    if(preco > 100){
        preco *= 1.15;
    }else if(preco > 50){
        preco *= 1.10;
    }else{
        preco *= 1.05;
    }
    if(preco > 200){
        classificacao = 'A';
    }else if(preco > 120){
        classificacao = 'B';
    }else if(preco > 80){
        classificacao = 'C';
    }else{
        classificacao = 'D'; 
    }
    printf("Novo preco: R$%.2f\n", preco);
    printf("Classificacao: %c\n", classificacao);

    return 0;
}