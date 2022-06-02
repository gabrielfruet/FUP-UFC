#include <stdio.h>

// ALGORITMO VISUALG
// 	DECLARE numero NUMERICO
// 	ESCREVA "Digite um numero: "
// 	LEIA  numero
// 	SE numero % 3 == 0 ENTAO
//      ESCREVAL "Eh multiplo de tres!"
//  SENAO
//      ESCREVAL "Nao eh multiplo de tres"
//  FIMSE
// FIM_ALGORITMO.

int main(){
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    printf("%s\n", numero % 3 == 0 ? "Eh multiplo de tres!" : "Nao eh multiplo de tres");
    return 0;
}