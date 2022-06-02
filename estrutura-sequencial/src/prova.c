#include <stdio.h>

// ALGORITMO
//     DECLARE nota1 <- 0,nota2 <- 0,media <- 0, peso1 <- 2,peso2 <- 3 NUMERICO
//     LEIA  nota1
//     LEIA  nota2
//     media <- (nota1*peso1 + nota2*peso2)/(peso1 + peso2)
//     ESCREVA "Sua media eh: ", media
// FIM_ALGORITMO.

int main(){
    float nota1 = 0,nota2 = 0,media = 0;
    int peso1 = 2,peso2 = 3;

    puts("Digite a sua primeira e seguda nota: ");
    scanf("%f", &nota1);
    scanf("%f", &nota2);

    media = (nota1*peso1 + nota2*peso2)/(peso1 + peso2);
    printf("Sua media eh: %.2f", media);
}