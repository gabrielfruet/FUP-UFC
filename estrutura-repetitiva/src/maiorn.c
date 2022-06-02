#include <stdio.h>
#include <limits.h>

/*
 * ALGORITMO
	DECLARE maior = INT_MIN NUMERICO
	DECLARE atual = 1 NUMERICO
	ENQUANTO atual!=0 FAÇA
	INÍCIO
		ESCREVA "Digite um numero ou 0 para terminar: "
		LEIA  atual
		SE atual>maior ENTAO
		maior <- atual
	FIM
	ESCREVA "MAIOR: \n", maior
FIM_ALGORITMO.
 */

int main(){
    int maior = INT_MIN;
    int atual = 1;
    while(atual != 0){
        printf("Digite um numero ou 0 para terminar: ");
        scanf("%d", &atual);
        if(atual > maior)
            maior = atual;
    }
    printf("MAIOR: %d\n", maior);
    return 0;
}