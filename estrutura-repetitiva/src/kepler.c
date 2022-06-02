#include "stdio.h"
#include "math.h"

unsigned long long int fact(int n){
    if(n <= 1){
        return 1;
    }
    return (unsigned long long int)n*fact(n-1);
}

int main(){
    int power;
    printf("Digite a potencia para elevear o numero e: ");
    scanf("%d", &power);
    long double result = 0;
    for(int i = 0; i < 15; i++){
        result += pow(power,i)/fact(i);
    }
    printf("RESULTADO: %Lf\n", result);
}