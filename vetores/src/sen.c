#include <stdio.h>
#include <math.h>

unsigned long long int fact(int n){
    return n<2 ? 1 : n*fact(n-1);
}

int main(){
    double termos[15], angulo, termo, seno;
    printf("Digite o angulo em graus: ");
    scanf("%lf", &angulo);
    angulo = M_PI*angulo/180;
    for(int i = 0; i < 15; i++){
        termo = pow(-1, i)*pow(angulo, i * 2 + 1)/fact(i * 2 + 1);
        termos[i] = termo;
        printf("TERMO I: %d = %lf\n", i, termos[i]);
        seno += termo;
    }
    printf("SENO: %lf\n", seno);
    return 0;
}