#include "stdio.h"

int main(){
    long long int num, fatorial;
    printf("Digite o numero que deseja usar na serie: ");
    scanf("%lli",&num);
    double resultado = num;
    for(int i = 1; i <= 20; i++){
        fatorial = 1;
        for(int k = i; k > 0; k--){
            fatorial *= k;
        }
        printf("FATORIAL: %lli\n", fatorial);
        if(i % 2 == 0){
            resultado -= num/(double)fatorial;
        }else{
            resultado += num/(double)fatorial;
        }
    }
    printf("RESULTADO: %lf\n", resultado);
    return 0;
}