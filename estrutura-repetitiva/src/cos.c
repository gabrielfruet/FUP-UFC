#include "stdio.h"
#include "math.h"

unsigned long long int fact(int n){
    if(n <= 1){
        return 1;
    }
    return (unsigned long long int)n*fact(n-1);
}

int main(){
    double ang;
    int base;
    double sen;
    printf("Digite o angulo para saber o cosseno: ");
    scanf("%lf", &ang);
    ang = ang*M_PI/180;
    for(int i = 0; i < 12; i++){
        base = (i * 2);
        sen += (pow(ang,base) * pow(-1, i))/fact(base);
    }
    printf("COS: %lf\n", sen);
    return 0;
}