#include <stdio.h>

// ALGORITMO
// 	DECLARE baseMenor,baseMaior, altura NUMERICO
// 	ESCREVA "Digite a base menor, base maior e altura de um trapezio: "
// 	LEIA  baseMaior
// 	LEIA  baseMenor
// 	LEIA  altura
// 	DECLARE area = (baseMaior + baseMenor)*altura/2 NUMERICO
// 	ESCREVA "Area total: ", area
// FIM_ALGORITMO.

int main()
{
    float baseMenor,baseMaior, altura;
    printf("Digite a base menor, base maior e altura de um trapezio: ");
    scanf("%f", &baseMaior);
    scanf("%f", &baseMenor);
    scanf("%f", &altura);
    float area = (baseMaior + baseMenor)*altura/2;
    printf("Area total: %.1f", area);
    return 0;
}
