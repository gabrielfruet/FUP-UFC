#include "stdio.h"
#include "limits.h"
#define TAMANHO 50

int main(){
    int sexo;
    int altura;
    int totalFem = 0, maior = INT_MIN, menor = INT_MAX, somaFem = 0, somaTurma = 0;
    for(int i = 0; i < TAMANHO; i++){
        printf("Digite seu sexo(1 - M, 2 - F) e sua altura em cm");
        scanf("%d %d", &sexo, &altura);
        somaTurma += altura;
        if(sexo == 2){
            somaFem += altura;
            totalFem++;
        }else if(sexo != 1){
            puts("Sexo invalido!");
            i--;
        }
        if(altura > maior){
            maior = altura;
        }else if(altura < menor){
            menor = altura;
        }
    }
    printf("MAIOR ALTURA: %dcm\n", maior);
    printf("MENOR ALTURA: %dcm\n", menor);
    printf("MEDIA DA TURMA: %lfcm\n", somaTurma/(double)TAMANHO);
    printf("MEDIA FEM DE ALTURA: %lfcm\n", somaFem/(double)totalFem);
    return 0;
}