#include <stdio.h>
#include <math.h>

/*ALGORITMO
        ESCREVA "O aluno cometeu ", 2^(26-1), " erros"
FIM_ALGORITMO.*/

int main(){
    printf("O aluno cometeu %d erros", (int)pow(2,26 - 1));
    return 0;
}