#include "stdio.h"
#include "math.h"

unsigned long long int fact(int n){
    if(n <= 1){
        return 1;
    }
    return (unsigned long long int)n*fact(n-1);
}

int main(){
    int N;
    printf("Digite o valor de N:");
    scanf("%d", &N);
    double resultado, atual;
    for(int i = 0; i <= N; i++){
        atual = pow(-1,i) * fact(N - i)/(long double)fact(i);
        resultado += atual;
        printf("%lf, ", atual);
    }
    printf("\nRESULTADO: %lf\n", resultado);
    return 0;
}