#include <stdio.h>

// ALGORITMO
// 	DECLARE celsius, fahrenheit NUMERICO
// 	ESCREVA "Digite a temperatura em celsius: "
// 	LEIA  celsius
// 	fahrenheit <- (celsius*1.8) + 32
// 	ESCREVA "Em fahrenheit: ", fahrenheit
// FIM_ALGORITMO.

int main(){
    float celsius, fahrenheit;
    printf("Digite a temperatura em celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius*1.8) + 32;
    printf("Em fahrenheit: %f", fahrenheit);
    return 0;
}