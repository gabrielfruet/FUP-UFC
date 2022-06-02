#include <stdio.h>
#include <math.h>

//ALGORITMO
//  PARA  i = 1 ATÉ    = 20 FAÇA
//  INÍCIO
//      ESCREVA i," : " 2^i
//  FIM
// FIM_ALGORITMO.

int main(){
    for(int i = 1; i <= 20; i++){
        printf("%d : %d\n", i, (int)pow(2,i));
    }
    return 0;
}