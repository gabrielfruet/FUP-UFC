#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ALGORITMO VISUALG
// 	DECLARE a,b,c NUMERICO
// 	ESCREVA "Digite tres lados de um suposto triangulo para verificar se ele existe: "
// 	LEIA  a,  b,  c
// 	SE abs(b - c) < a E a < b + c ENTAO
// 		ESCREVA "EXISTE!"
//      DECLARE cosA <- (a^2 - b^2 - c^2)/-(2*b*c) NUMERICO;
//      DECLARE cosB <- (b^2 - c^2 - a^2)/-(2*c*a) NUMERICO;
//      DECLARE cosC <- (c^2 - a^2 - b^2)/-(2*a*b) NUMERICO;
//      SE NAO cosA OU NAO cosB OU NAO cosC ENTAO
//          ESCREVAL "TRIANGULO RETANGULO!"
//      SENAO SE cosA < 0 OU cosB < 0 OU cosC < 0 ENTAO
//          ESCREVAL "TRIANGULO OBTUSANGULO!"
//      SENAO
//          ESCREVAL "TRIANGULO ACUTANGULO!"
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
        printf("EXISTE!\n");
        //CALCULO O COS DOS ANGULOS POR MEIO DA LEI DOS COSSENOS
        float cosA = (pow(a,2) - pow(b,2) - pow(c,2))/-(2*b*c);
        float cosB = (pow(b,2) - pow(c,2) - pow(a,2))/-(2*c*a);
        float cosC = (pow(c,2) - pow(a,2) - pow(b,2))/-(2*a*b);
        //Quando cos(lado) for 0, significa que eh FALSEY e que é retângulo, ou seja, 
        //quando for !FALSE, ele deve entrar na condição
        if(!cosA || !cosB || !cosC){
            printf("TRIANGULO RETANGULO!\n");
        }else if(cosA < 0 || cosB < 0 || cosC < 0){
            printf("TRIANGULO OBTUSANGULO\n");
        }else{
            printf("TRIANGULO ACUTANGULO\n");
        }
    }else{
        printf("NAO EXISTE!\n");
    }
    return 0;
}