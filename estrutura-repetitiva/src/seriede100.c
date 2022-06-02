#include "stdio.h"

int main(){
    double soma = 1;
    for(int i = 1; i < 100; i++){
        if(i % 2 == 0){
            soma -= 1/(double)(i*2);
        }else{
            soma += 1/(double)(i*2);
        }
        printf("SOMA: %lf\n", soma);
    }
    printf("RESULTADO: %lf\n", soma);
    return 0;
}