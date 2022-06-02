#include <stdio.h>
#include <stdlib.h>

// ALGORITMO VISUALG
// 	DECLARE a,b,c NUMERICO
// 	ESCREVA "Digite tres lados de um suposto triangulo para verificar se ele existe: "
// 	LEIA  a,  b,  c
//  SE  abs(b - c) < a E a < b + c ENTAO
// 		ESCREVA "EXISTE!"
// 	SENÃO
// 		ESCREVA "NAO EXISTE!"
// 	FIMSE
// FIM_ALGORITMO.

int main(){
    int a,b,c;
    printf("Digite tres lados de um suposto triangulo para verificar se ele existe: ");
    scanf("%d %d %d", &a, &b, &c);
    if(abs(b - c) < a && a < b + c){
        printf("EXISTE!");
    }else{
        printf("NAO EXISTE!");
    }
    return 0;
}