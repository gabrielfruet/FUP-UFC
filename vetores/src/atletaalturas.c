#include <stdio.h>

int main(){
    double alturas[10], soma = 0, media = 0;
    for(int i = 0; i < 10; i++){
        printf("DIGITE A ALTURA DO ATLETA: ");
        scanf("%lf", &alturas[i]);
        soma += alturas[i];
    }
    media = soma/10;
    printf("MEDIA: %lf\n", media);
    printf("ACIMA DA MEDIA: ");
    for(int i = 0; i < 10; i++){
        if(alturas[i] > media){
            printf("%.2lf,", alturas[i]);
        }
    }
    return 0;
}