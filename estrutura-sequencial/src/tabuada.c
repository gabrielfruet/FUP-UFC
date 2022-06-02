#include <stdio.h>

// ALGORITMO
// 	DECLARE numero NUMERICO
// 	ESCREVA "Digite o numero que voce deseja a tabuada: "
// 	LEIA  numero
// 	PARA  i = 1 ATÉ     10 FAÇA
// 	INÍCIO
// 		ESCREVA i, " x ", numero, " = ", numero*i
// 	FIM
// FIM_ALGORITMO.

int main(){
    int numero;
    printf("Digite o numero que voce deseja a tabuada: ");
    scanf("%d", &numero);
    for(int i = 1; i < 10; i++){
        printf("%d x %d = %d\n", i, numero, numero*i);
    }
    return 0;
}