#include <stdio.h>

// ALGORITMO
// 	DECLARE salarioMinimo, salarioResultante NUMERICO
// 	DECLARE horasTrabahadas, horasExtras NUMERICO
// 	ESCREVA "Digite o salario minino, suas horas trabalhadas e suas horas extras trabalhadas: "
// 	LEIA  salarioMinimo
// 	LEIA  horasTrabahadas
// 	LEIA  horasExtras
// 	salarioResultante <- (salarioMinimo*horasTrabahadas)/8 + (salarioMinimo*horasExtras)/4
// 	ESCREVA "Salario resultante: R$", salarioResultante
// FIM_ALGORITMO.

int main(){
    float salarioMinimo, salarioResultante;
    int horasTrabahadas, horasExtras;
    printf("Digite o salario minino, suas horas trabalhadas e suas horas extras trabalhadas: ");
    scanf("%f", &salarioMinimo);
    scanf("%d", &horasTrabahadas);
    scanf("%d", &horasExtras);
    salarioResultante = (salarioMinimo*horasTrabahadas)/8 + (salarioMinimo*horasExtras)/4;
    printf("Salario resultante: R$%.2f", salarioResultante);
    return 0;
}