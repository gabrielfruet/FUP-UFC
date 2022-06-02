#include <stdio.h>

// ALGORITMO
// 	DECLARE lado NUMERICO
// 	ESCREVA "Digite o lado de um quadrado: "
// 	LEIA  lado
// 	DECLARE area = lado*lado NUMERICO
// 	ESCREVA "Area do quadrado: ", area
// FIM_ALGORITMO.

int main()
{
    float lado;
    printf("Digite o lado de um quadrado: ");
    scanf("%f", &lado);
    float area = lado*lado;
    printf("Area do quadrado: %.1f", area);
    return 0;
}
