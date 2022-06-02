#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ALGORITMO VISUALG
// 	DECLARE a,b,c NUMERICO
// 	ESCREVA "Digite os coeficients a,b e c de uma equacao de segundo grau: "
// 	LEIA  a,  b,  c
// 	DECLARE delta = pow(b,2) - 4*a*c NUMERICO
// 	SE delta<0 ENTAO
// 		ESCREVA "ERRO: A equacao nao possui raizes reais!\n"
//  FIMSE
// 	DECLARE x1 = (-b + sqrt(delta))/2*a, x2 = (-b - sqrt(delta))/2*a NUMERICO
// 	ESCREVAL "Raiz 1: ", x1
// 	ESCREVAL "Raiz 2: ", x2
// FIM_ALGORITMO.

int main(){
    double a,b,c;
    printf("Digite os coeficients a,b e c de uma equacao de segundo grau: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double delta = pow(b,2) - 4*a*c;
    if(delta < 0){
        printf("ERRO: A equacao nao possui raizes reais!\n");
        exit(1);
    }
    double x1 = (-b + sqrt(delta))/2*a, x2 = (-b - sqrt(delta))/2*a;
    printf("Raiz 1: %lf\n", x1);
    printf("Raiz 2: %lf\n", x2);
    return 0;
}