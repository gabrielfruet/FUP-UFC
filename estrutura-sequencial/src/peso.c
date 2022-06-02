#include <stdio.h>

// ALGORITMO
// 	DECLARE pesoKG, pesoG NUMERICO
// 	ESCREVA "Digite seu peso em KG: "
// 	LEIA  pesoKG
// 	pesoG <- pesoKG * 1000
// 	ESCREVA "Seu peso em gramas eh: ", pesoG
// FIM_ALGORITMO.

int main(){
    float pesoKG, pesoG;
    printf("Digite seu peso em KG: ");
    scanf("%f", &pesoKG);
    pesoG = pesoKG * 1000;
    printf("Seu peso em gramas eh: %.2f", pesoG);
    return 0;
}