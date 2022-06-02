#include <stdio.h>
#include <limits.h>
#define TEMP 5

int main(){
    int temperaturas[TEMP], maior = INT_MIN, menor = INT_MAX, soma = 0;
    for(int i = 0; i < TEMP; i++){
        printf("Digite a temperatura no dia %d", i + 1);
        scanf("%d", &temperaturas[i]);
        soma += temperaturas[i];
        if(temperaturas[i] > maior){
            maior = temperaturas[i];
        }
        if(temperaturas[i] < menor){
            menor = temperaturas[i];
        }
    }
    double media = soma/(double)TEMP;
    printf("Maior temperatura: %d\n", maior);
    printf("Menor temperatura: %d\n", menor);
    printf("Temperatura media: %lf\n", media);
    printf("Temperaturas acima da media: ");
    for(int i = 0; i < TEMP; i++){
        if(temperaturas[i] > media)
            printf("%d,", temperaturas[i]);
    }
    puts("");
    return 0;
}