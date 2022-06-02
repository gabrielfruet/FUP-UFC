#include "stdio.h"

int main(){
    int a,b, resultado = 0;
    printf("Digite os numeros que voce quer multiplicar!");
    scanf("%d %d", &a, &b);
    for(int i = 1; a >= b; i++, resultado++){
        a -= b;
        printf("%d : %d\n",b, resultado);
    }
    printf("RESULTADO: %d\n", resultado);
    return 0;
}