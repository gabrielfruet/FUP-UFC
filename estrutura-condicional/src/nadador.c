#include <stdio.h>

// ALGORITMO VISUALG
// 	DECLARE idade NUMERICO
// 	ESCREVA "Qual a idade do nadador?"
// 	LEIA  idade
// 	SENAO SE idade>30 ENTAO
// 		ESCREVAL "CATEGORIA: MASTER"
// 	SENAO SE idade>=16 ENTAO
// 		ESCREVAL "CATEGORIA: ADULTO"
// 	SENAO SE idade>=11 ENTAO
// 		ESCREVAL "CATEGORIA: JUVENIL"
// 	SENAO SE idade>=8 ENTAO
// 		ESCREVAL "CATEGORIA: INFANTO-JUVENIL"
// 	SENAO SE idade>=5 ENTAO
// 		ESCREVAL "CATEGORIA: INFANTO"
// 	SENÃO
// 		ESCREVAL "Nao pode competir!"
// 	FIMSE
// FIM_ALGORITMO.

int main(){
    int idade;
    printf("Qual a idade do nadador?");
    scanf("%d", &idade);
    if(idade > 30){
        printf("CATEGORIA: MASTER\n");
    }else if(idade >= 16){
        printf("CATEGORIA: ADULTO\n");
    }else if(idade >= 11){
        printf("CATEGORIA: JUVENIL\n");
    }else if(idade >= 8){
        printf("CATEGORIA: INFANTO-JUVENIL\n");
    }else if(idade >= 5){
        printf("CATEGORIA: INFANTO\n");
    }else{
        printf("Nao pode competir!\n");
    }
    return 0;
}