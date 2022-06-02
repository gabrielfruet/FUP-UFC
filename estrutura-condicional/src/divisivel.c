#include <stdio.h>

// ALGORITMO VISUALG
// 	DECLARE a,b NUMERICO
// 	ESCREVA "Digite dois numeros para verificar se o primeiro eh divisivel pelo segundo: "
// 	LEIA  a,  b
// 	SE a % b == 0 ENTAO
//      ESCREVAL "Eh divisivel!"
//  SENAO
//      ESCREVAL "Nao eh divisivel!"
// FIM_ALGORITMO.

int main(){
    int a,b;
    printf("Digite dois numeros para verificar se o primeiro eh divisivel pelo segundo: ");
    scanf("%d %d", &a, &b);
    printf("%s\n", a % b == 0 ? "Eh divisivel!" : "Nao eh divisivel!");
    return 0;
}