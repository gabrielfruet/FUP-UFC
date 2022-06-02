#include "stdio.h"

/*ALGORITMO
	DECLARE numeroAlunos NUMERICO
	DECLARE somaNotas = 0 NUMERICO
	DECLARE notaAtual NUMERICO
	DECLARE maiorNota = -1 NUMERICO
	DECLARE media NUMERICO
	ESCREVA "Digite quantos alunos serao lidos: "
	LEIA  numeroAlunos
	PARA  i = 0 ATÉ     numeroAlunos FAÇA
	INÍCIO
		ESCREVA "Digite a nota do o aluno ",i + 1
		LEIA  notaAtual
		somaNotas +<- notaAtual
		SE notaAtual>maiorNota ENTAO
		maiorNota <- notaAtual
	FIM
	ESCREVA "MAIOR NOTA: \n", maiorNota
	ESCREVA "MEDIA: \n", media
FIM_ALGORITMO.*/

int main(){
    int numeroAlunos;
    float somaNotas = 0;
    float notaAtual;
    float maiorNota = -1;
    float media;
    printf("Digite quantos alunos serao lidos: ");
    scanf("%d", &numeroAlunos);
    for(int i = 0; i < numeroAlunos; i++){
        printf("Digite a nota do %do aluno ",i + 1);
        scanf("%f", &notaAtual);
        somaNotas += notaAtual;
        if(notaAtual > maiorNota)
            maiorNota = notaAtual;
    }
    media = somaNotas/(float)numeroAlunos;
    printf("MAIOR NOTA: %f\n", maiorNota);
    printf("MEDIA: %f\n", media);
    return 0;
}