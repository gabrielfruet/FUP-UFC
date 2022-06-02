#include "stdio.h"

int main(){
    int a,b,i;
    printf("Digite dois numeros para verificar se sao primos entre si: ");
    scanf("%d %d", &a, &b);
    for(i = 2; (i <= a && i <= b) && (a % i != 0 || a % b != 0); i++){}
    if(i == a || i == b){
        printf("NAO SAO PRIMOS ENTRE SI!\n");
    }else{
        printf("SAO PRIMOS ENTRE SI!\n");
    }
    return 0;
}