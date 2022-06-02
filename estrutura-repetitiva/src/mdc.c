#include "stdio.h"

int main(){
    int a,b,i;
    printf("Digite dois numeros para fazer o mdc: ");
    scanf("%d %d", &a, &b);
    for(i = a > b ? b : a; i > 0 && (a % i != 0 || b % i != 0); i--){}
    printf("MDC: %d\n", i);
    return 0;
}