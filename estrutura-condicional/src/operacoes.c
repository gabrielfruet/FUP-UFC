#include <stdio.h>
#include <stdlib.h>

// ALGORITMO VISUALG
// 	DECLARE opcao, numero1,numero2, resultado NUMERICO
// 	ESCREVA "Digite dois numeros: "
// 	LEIA  numero1
// 	LEIA  numero2
//  ESCREVAL "Escolha uma opcao: "
//  ESCREVAL "1 - MEDIA ENTRE OS NUMEROS DIGITADOS"
//  ESCREVAL "2 - DIFERENCA DO MAIOR PELO MENOR"
//  ESCREVAL "3 - PRODUTO ENTRE OS NUMEROS DIGITADOS"
//  ESCREVAL "4 - DIVISAO DO PRIMEIRO PELO SEGUNDO"
// 	LEIA  opcao
// 	ESCOLHA opcao
//      CASO 1 FACA
// 		    resultado <- (numero1 + numero2)/2
// 		    PARE
//      CASO 2 FACA
// 		    resultado <- abs(numero1 - numero2)
// 		    PARE
//      CASO 3 FACA 
// 		    resultado <- numero1*numero2
// 		    PARE
//      CASO 4 FACA
//          SE numero2 = 0 FACA
//              ESCREVAL "Indeterminacao"
//              SAIR
// 		    resultado <- numero1/numero2
// 		    PARE
// 		CASO PADRAO FACA
//          ESCREVA "OPCAO INVALIDA"
//          SAIR
// 	FIM-ESCOLHA
// 	ESCREVAL "Resultado: ", resultado
// FIM_ALGORITMO.

int main(){
    int opcao;
    float numero1,numero2, resultado;
    printf("Digite dois numeros: ");
    scanf("%f", &numero1);
    scanf("%f", &numero2);
    puts("Escolha uma opcao: ");
    puts("1 - MEDIA ENTRE OS NUMEROS DIGITADOS");
    puts("2 - DIFERENCA DO MAIOR PELO MENOR");
    puts("3 - PRODUTO ENTRE OS NUMEROS DIGITADOS");
    puts("4 - DIVISAO DO PRIMEIRO PELO SEGUNDO");
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
            resultado = (numero1 + numero2)/2;
            break;
        case 2:
            resultado = abs(numero1 - numero2);
            break;
        case 3:
            resultado = numero1*numero2;
            break;
        case 4:
            if(numero2 == 0){
                puts("Indeterminacao");
                exit(1);
            }
            resultado = numero1/numero2;
            break;
        default:{
            puts("Opcao invalida");
            exit(1);
        }    
    }
    printf("Resultado: %f\n", resultado);
    return 0;
}