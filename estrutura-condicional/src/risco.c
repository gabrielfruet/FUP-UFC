#include <stdio.h>

// ALGORITMO VISUALG
// 	DECLARE idade, grupo NUMERICO
// 	DECLARE peso NUMERICO
// 	ESCREVA "Digite sua idade e seu peso em kg"
// 	LEIA  idade
// 	LEIA  peso
// 	SE idade>50 ENTAO
// 		SE peso<=60 ENTAO
// 			grupo <- 3
// 		SENAO SE peso>90 ENTAO
// 			grupo <- 1
// 		SENÃO
// 			grupo <- 2
//      FIMSE
// 	SENAO SE idade<20 ENTAO
// 		SE peso<=60 ENTAO
// 			grupo <- 6
// 		SENAO SE peso>90 ENTAO
// 			grupo <- 4
// 		SENÃO
// 			grupo <- 5
//      FIMSE
// 	SENÃO
// 		SE peso<=60 ENTAO
// 			grupo <- 9
// 		SENAO SE peso>90 ENTAO
// 			grupo <- 7
// 		SENÃO
// 			grupo <- 8
//      FIMSE
//  FIMSE
// 	ESCREVA "GRUPO DE RISCO: ", grupo


// FIM_ALGORITMO.

int main(){
    int idade, grupo;
    float peso;
    printf("Digite sua idade e seu peso em kg");
    scanf("%d", &idade);
    scanf("%f", &peso);
    if(idade > 50){
        if(peso <= 60){
            grupo = 3;
        }else if(peso > 90){
            grupo = 1;
        }else{
            grupo = 2;
        }
    }else if(idade < 20){
        if(peso <= 60){
            grupo = 6;
        }else if(peso > 90){
            grupo = 4;
        }else{
            grupo = 5;
        }
    }else{
        if(peso <= 60){
            grupo = 9;
        }else if(peso > 90){
            grupo = 7;
        }else{
            grupo = 8;
        }
    }
    printf("GRUPO DE RISCO: %d", grupo);
    return 0;
}