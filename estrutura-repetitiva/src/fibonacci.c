#include "stdio.h"

int main(){
    int last = 0, current = 1, next = 0;
    int n;
    printf("Quantos numeros de fibonacci voce deseja?");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Atual: %d\n", current);
        next = current + last;
        last = current;
        current = next;
    }
    return 0;
}