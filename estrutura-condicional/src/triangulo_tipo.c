#include <stdio.h>
#include <stdlib.h>

// ALGORITMO VISUALG
// 	DECLARE a,b,c NUMERICO
// 	ESCREVA "Digite tres lados de um suposto triangulo para verificar se ele existe: "
// 	LEIA  a,  b,  c
// 	SE abs(b - c) < a && a < b + c ENTAO
// 		SE a == b E b == c ENTAO
//          ESCREVAL "TRIANGULO EQUILATERO!"
//      SENAO SE a == b OU b == c OU a == c ENTAO
//          ESCREVAL "TRIANGULO ISOSCELES"
//      SENAO
//          ESCREVAL "TRIANGULO ESCALENO"
//      FIMSE
// 	SENÃO
// 		ESCREVA "NAO EXISTE!"
// 	FIMSE
// FIM_ALGORITMO.

int main(){
    int a,b,c;
    printf("Digite tres lados de um suposto triangulo para verificar se ele existe: ");
    scanf("%d %d %d", &a, &b, &c);
    if(abs(b - c) < a && a < b + c){
        if(a == b && b == c){
            printf("TRIANGULO EQUILATERO!\n");
        }else if(a == b || b == c || a == c){
            printf("TRIANGULO ISOSCELES\n");
        }else{
            printf("TRIANGULO ESCALENO\n");
        }
    }else{
        printf("NAO EXISTE!\n");
    }
    return 0;
}