#include <stdio.h>

// ALGORITMO VISUALG
// 	DECLARE numero NUMERICO
// 	ESCREVA "Digite um numero: "
// 	LEIA  numero
// 	SE numero % 5 == 0 ENTAO
//      ESCREVAL "Eh multiplo de cinco!"
//  SENAO
//      ESCREVAL "Nao eh multiplo de cinco!"
//  FIMSE
// FIM_ALGORITMO.

int main(){
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    printf("%s\n", numero % 5 == 0 ? "Eh multiplo de cinco!" : "Nao eh multiplo de cinco");
    return 0;
}