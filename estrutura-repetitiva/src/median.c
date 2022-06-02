#include <stdio.h>

//ALGORITMO
//        DECLARE total, soma = 0, atual NUMERICO
//        DECLARE media NUMERICO
//        ESCREVA "Digite a quantidade de numeros para calcular a media: "
//        LEIA  total
//        PARA  i = 0 ATÉ     total FAÇA
//        INÍCIO
//            ESCREVA "Digite um numero: "
//            LEIA  atual
//            soma <- soma + atual
//        FIM
//        ESCREVA "MEDIA: \n", media
//FIM_ALGORITMO.




int main(){
    int total, soma = 0, atual;
    float media;
    printf("Digite a quantidade de numeros para calcular a media: ");
    scanf("%d", &total);

    for(int i = 0; i < total; i++){
        printf("Digite um numero: ");
        scanf("%d", &atual);
        soma += atual;
    }
    media = soma/(float)total;
    printf("MEDIA: %f\n", media);

    return 0;
}