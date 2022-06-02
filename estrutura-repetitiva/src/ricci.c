#include "stdio.h"

int main(){
    int last = 0, current = 1, next = 0;
    int n;
    printf("Quantos numeros de ricci voce deseja?");
    scanf("%d", &n);
    printf("Digite os dois primeiros numeros: ");
    scanf("%d %d", &last, &current);
    for(int i = 0; i < n; i++){
        printf("Atual: %d\n", current);
        next = current + last;
        last = current;
        current = next;
    }
    return 0;
}