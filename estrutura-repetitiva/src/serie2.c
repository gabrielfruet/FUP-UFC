#include "stdio.h"

int main(){
    int qntd;
    printf("Digite quantos numeros voce deseja na serie: ");
    scanf("%d", &qntd);
    for(int i = 1; i <= qntd; i++){
        for(int k = 0; k < 3; k++){
            if(k == 0){
                printf("%d,",i);
            }else{
                printf("%d,", i + 3);
            }

        }
    }
    puts("");
    return 0;
}