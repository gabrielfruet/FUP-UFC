#include <stdio.h>

int main(){
    int prim,seg, soma = 0;
    printf("Digite dois numeros em ordem crescente para ver o intervalo!");
    scanf("%d %d",&prim,&seg);
    for(int i = prim % 2 ? prim + 1 : prim; i < seg; i += 2){
        printf("%d\n", i);
        soma += i;
    }
    printf("SOMA: %d\n", soma);
    return 0;
}