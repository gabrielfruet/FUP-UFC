#include <stdio.h>
#include <stdlib.h>

// ALGORITMO VISUALG
// 	DECLARE  sexo LITERAL
// 	DECLARE altura, peso NUMERICO
// 	ESCREVA "Digite sua altura em metros e seu sexo(M/F): "
// 	LEIA  altura
// 	LEIA  sexo
// 	ESCOLHA sexo
//      CASO 'M' FACA
// 		    peso <- (72.7 * altura) - 58
// 		    PARE
//      CASO 'F' FACA
// 		    peso <- (62.1 * altura) - 44.7
// 		    PARE
//      CASO PADRAO FACA
// 		    ESCREVA "Opcao invalida!"
//          SAIR
// 	FIM-ESCOLHA
// 	ESCREVA "Peso ideal: %.2fkg\n", peso
// FIM_ALGORITMO.

int main(){
    char sexo;
    float altura, peso;
    printf("Digite sua altura em metros e seu sexo(M/F): ");
    scanf("%f", &altura);
    scanf(" %c", &sexo);
    switch(sexo){
        case 'M':
            peso = (72.7 * altura) - 58;
            break;
        case 'F':
            peso = (62.1 * altura) - 44.7;
            break;
        default:
            printf("Opcao invalida!");
            exit(1);
    }
    printf("Peso ideal: %.2fkg\n", peso);
    return 0;
}