#include <stdio.h>


// ALGORITMO
//     DECLARE salario, valorVendas, salarioResultante, comissaoResultante NUMERICO
//     ESCREVA "Digite seu salario e o valor das suas vendas: "
//     LEIA  salario
//     LEIA  valorVendas
//     comissaoResultante <- valorVendas*0.04
//     salarioResultante <- salario + comissaoResultante
//     ESCREVA "Salario resultante: R$", salarioResultante
//     ESCREVA "Comissao resultante: R$", comissaoResultante
// FIM_ALGORITMO.


int main() {
    float salario, valorVendas, salarioResultante, comissaoResultante;
    printf("Digite seu salario e o valor das suas vendas: ");
    scanf("%f", &salario);
    scanf("%f", &valorVendas);
    comissaoResultante = valorVendas*0.04;
    salarioResultante = salario + comissaoResultante;
    printf("Salario resultante: R$%.2f\n", salarioResultante);
    printf("Comissao resultante: R$%.2f\n", comissaoResultante);
    return 0;
}
