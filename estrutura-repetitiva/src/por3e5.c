#include <stdio.h>

int main(){
    int n;
    printf("Digite um numero para ver os multiplos de 3 e 5 no intervalo fechado de 1 a N\n");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0){
            printf("%d DIVISIVEL POR 3\n", i);
        }else if(i % 5 == 0){
            printf("%d DIVISIVEL POR 5\n", i);
        }
    }
    return 0;
}