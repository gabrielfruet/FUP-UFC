#include <stdio.h>

// ALGORITMO
// 	DECLARE dimX, dimY NUMERICO
// 	ESCREVA "Digite as dimensoes do seu comodo em metros: "
// 	LEIA  dimX
// 	LEIA  dimY
// 	ESCREVA "Potencia a ser utilizado: ", dimY*dimX*18, "w"
// FIM_ALGORITMO.

int main(){
    float dimX, dimY;
    printf("Digite as dimensoes do seu comodo em metros: ");
    scanf("%f", &dimX);
    scanf("%f", &dimY);
    printf("Potencia a ser utilizado %.2fw", dimY*dimX*18);
    return 0;
}