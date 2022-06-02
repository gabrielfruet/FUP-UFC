#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ALGORITMO VISUALG
// 	DECLARE a,b,c NUMERICO
// 	ESCREVA "Digite tres lados de um suposto triangulo para verificar se ele existe: "
// 	LEIA  a,  b,  c
// 	SE  abs(b - c) < a E a < b + c ENTAO
// 		ESCREVA "EXISTE!"
//      DECLARE angA <- acos((pow(a,2) - pow(b,2) - pow(c,2))/-(2*b*c))*180/M_PI NUMERICO;
//      DECLARE angB <- acos((pow(b,2) - pow(c,2) - pow(a,2))/-(2*c*a))*180/M_PI NUMERICO;
//      DECLARE angC <- acos((pow(c,2) - pow(a,2) - pow(b,2))/-(2*a*b))*180/M_PI NUMERICO;
//      ESCREVAL angA
//      ESCREVAL angB
//      ESCREVAL angC
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
        //APLICA A LEI DOS COSSENOS, CONVERTE OS COSSENOS DOS ANGULOS PARA ARCOCOSSENO EM RADIANOS E CONVERTE PARA ANGULO
        double angA = acos((pow(a,2) - pow(b,2) - pow(c,2))/-(2*b*c))*180/M_PI;
        double angB = acos((pow(b,2) - pow(c,2) - pow(a,2))/-(2*c*a))*180/M_PI;
        double angC = acos((pow(c,2) - pow(a,2) - pow(b,2))/-(2*a*b))*180/M_PI;
        //if(angA == 90 || angB == 90 || angC == 90){
            printf("Angulo de A: %lf°\n", angA);
            printf("Angulo de B: %lf°\n", angB);
            printf("Angulo de C: %lf°\n", angC);
        //}
    }else{
        printf("NAO EXISTE!\n");
    }
    return 0;
}