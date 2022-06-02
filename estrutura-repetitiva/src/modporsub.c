#include "stdio.h"

int main(){
    int a,b;
    printf("Digite os numeros que voce quer multiplicar!");
    scanf("%d %d", &a, &b);
    for(int i = 1; a >= b; i++){
        a -= b;
        printf("%d : %d\n",b, a);
    }
    printf("RESULTADO: %d\n", a);
    return 0;
}