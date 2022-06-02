#include <stdio.h>

// ALGORITMO
// 	DECLARE salarioMin, salarioAtual NUMERICO
// 	ESCREVA "Digite o salario minimo e o seu salario: "
// 	LEIA  salarioMin
// 	LEIA  salarioAtual
// 	DECLARE quantidadeDeSalarios = salarioAtual/salarioMin NUMERICO
// 	ESCREVA "Quantidade de salarios minimos que voces recebe : ", quantidadeDeSalarios
// FIM_ALGORITMO.

int main(){
    float salarioMin, salarioAtual;
    printf("Digite o salario minimo e o seu salario: ");
    scanf("%f", &salarioMin);
    scanf("%f", &salarioAtual);
    float quantidadeDeSalarios = salarioAtual/salarioMin;
    printf("Quantidade de salarios minimos que voces recebe : %.1f", quantidadeDeSalarios);
    return 0;
}