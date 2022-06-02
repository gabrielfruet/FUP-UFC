#include <stdio.h>

// ALGORITMO VISUALG
//     DECLARE x, fn NUMERICO
//     ESCREVA "Digite o valor de x: "
//     LEIA x
//     SE x <= 1 ENTAO
//         fn <- 1
//     SENAO SE x <= 2 ENTAO
//         fn <- 2
//     SENAO SE x <= 3 ENTAO
//         fn <- x*x
//     SENAO 
//         fn <- x*x*x
//     FIMSE
//     ESCREVAL "RESULTADO DA FUNCAO: ", fn
// FIM


int main(){
    double x, fn;
    printf("Digite o valor de x: ");
    scanf("%lf", &x);
    if(x <= 1){
        fn = 1;
    }else if(x <= 2){
        fn = 2;
    }else if(x <= 3){
        fn = x*x;
    }else{
        fn = x*x*x;
    }
    printf("RESULTADO DA FUNCAO: %lf", fn);
    return 0;
}