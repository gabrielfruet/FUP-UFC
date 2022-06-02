#include <stdio.h>

// ALGORITMO
// 	DECLARE anoAtual, anoNascimento NUMERICO
// 	ESCREVA "Digite o ano atual e o ano que voce nasceu: "
// 	LEIA  anoAtual
// 	LEIA  anoNascimento
// 	DECLARE emAnos = anoAtual - anoNascimento, NUMERICO
// 	emMeses <- emAnos * 12,
// 	emDias <- emMeses * 30,
// 	emSemanas <- emMeses * 4
// 	ESCREVA "Idade em anos: ", emAnos
// 	ESCREVA "Idade em meses: ", emMeses
// 	ESCREVA "Idade em semanas: ", emSemanas
// 	ESCREVA "Idade em dias: ", emDias
// FIM_ALGORITMO.

int main(){
    int anoAtual, anoNascimento;
    printf("Digite o ano atual e o ano que voce nasceu: ");
    scanf("%d", &anoAtual);
    scanf("%d", &anoNascimento);
    int emAnos = anoAtual - anoNascimento,
    emMeses = emAnos * 12,
    emDias = emMeses * 30,
    emSemanas = emMeses * 4;
    printf("Idade em anos: %d\n", emAnos);
    printf("Idade em meses: %d\n", emMeses);
    printf("Idade em semanas: %d\n", emSemanas);
    printf("Idade em dias: %d\n", emDias);
    return 0;
}