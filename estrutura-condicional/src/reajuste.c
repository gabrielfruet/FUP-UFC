#include <stdio.h>

// ALGORITMO VISUALG
// 	DECLARE salario NUMERICO
// 	ESCREVA "Digite seu salario: "
// 	LEIA  salario
// 	SE salario<900 ENTAO
// 	INÍCIO
// 		salario <- salario*1.3
// 		ESCREVAL "Salario reajustado: R$", salario
// 	FIM
// 	SENÃO
//  	INÍCIO
// 		ESCREVAL "Voce nao tem direito ao aumento"
// 	FIM
// FIM_ALGORITMO.

int main(){
    float salario;
    printf("Digite seu salario: ");
    scanf("%f", &salario);
    if(salario < 900){
        salario *= 1.3;
        printf("Salario reajustado: R$%.2f", salario);
    }else{
        printf("Voce nao tem direito ao aumento");
    }
    return 0;
}