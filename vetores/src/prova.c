#include <stdio.h>
#define TAM 5

int main(){
	char gabarito[TAM];
	printf("Preencha o gabarito da prova usando A, B, C, D ou E: \n");
	for(int i = 0; i < TAM; i++){
		printf("Gabarito da %da questao: ", i);
		scanf(" %c", &gabarito[i]);
	}
	int n;
	printf("Digite a quantidade de alunos da turma: ");
	scanf("%d", &n);
	char gabaritosAlunos[n][TAM];
	for(int i = 0; i < n; i++){
		printf("GABARITO DO ALUNO DE No %d: \n", i);
		for(int j = 0; j < TAM; j++){
			printf("\t%da questao: ", j);
			scanf(" %c", &gabaritosAlunos[i][j]); 
		} 
	} 
	double nota = 0; 
	for(int i = 0; i < n; i++){ 
		nota = 0; 
		printf("NOTA DO ALUNO DE NUMERO %d: ", i);
		for(int j = 0; j < TAM; j++){
			if(gabarito[j] == gabaritosAlunos[i][j]){
				nota += 10.0/TAM;
			}
		}
		printf("%lf\n", nota);
	}
	return 0;
}
