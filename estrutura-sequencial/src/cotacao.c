#include <stdio.h>

// ALGORITMO
// 	DECLARE dinheiroEmReal, dinheiroEmDolar,dinheiroEmEuro,dinheiroEmLibras NUMERICO
// 	ESCREVA "Digite a quantia de dinheiro que quer converter em reais: "
// 	LEIA  dinheiroEmReal
// 	dinheiroEmDolar <- dinheiroEmReal/5.23
// 	dinheiroEmEuro <- dinheiroEmReal/6,39
// 	dinheiroEmLibras <- dinheiroEmReal/7.43
// 	ESCREVA "Em dolar: USD ", dinheiroEmDolar
// 	ESCREVA "Em euro: EUR ", dinheiroEmEuro
// 	ESCREVA "Em libras esterlinas: GBP ", dinheiroEmLibras
// FIM_ALGORITMO.

int main(){
    float dinheiroEmReal, dinheiroEmDolar,dinheiroEmEuro,dinheiroEmLibras;
    printf("Digite a quantia de dinheiro que quer converter em reais: ");
    scanf("%f", &dinheiroEmReal);
    dinheiroEmDolar = dinheiroEmReal/5.23;
    dinheiroEmEuro = dinheiroEmReal/6,39;
    dinheiroEmLibras = dinheiroEmReal/7.43;
    printf("Em dolar: USD %.2f\n", dinheiroEmDolar);
    printf("Em euro: EUR %.2f\n", dinheiroEmEuro);
    printf("Em libras esterlinas: GBP %.2f\n", dinheiroEmLibras);
    return 0;
}