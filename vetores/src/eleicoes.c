#include <stdio.h>
#include <string.h>

int main(){
	int n;
	printf("Digite a quantidade de candidatos que serao votados: ");
	scanf("%d", &n);

	if(n > 5){
		printf("QUANTIDADE MAXIMA DE CANDIDATOS : 5");
		n = 5;
	}

	char candidatos[n][30];
	int votos[n];
	memset(votos, 0, sizeof(int)*n);

	getchar();
	for(int i = 0; i < n; i++){
		printf("Digite o nome do candidato %d: ", i + 1);
		fgets(candidatos[i], sizeof(char)*30, stdin);
	}

	char voto[30] = "NAOFIM"; 
	printf("Digite o nome do candidato ou fim para finalizar: ");
	fgets(voto, 30, stdin);

	while(strcmp(voto, "fim\n")){
		int escolhido = 0;
		for(escolhido = 0; escolhido < n && strncmp(voto, candidatos[escolhido], 30); escolhido++);

		if(escolhido >= n){
			printf("Candidato nao existe!\n");
		}else{
			printf("Voto computado no candidato %s\n", candidatos[escolhido]);
			votos[escolhido] += 1;
		}

		printf("Digite o nome do candidato ou fim para finalizar: ");
		fgets(voto, 30, stdin);
	}

	for(int i = 0; i < n; i++){
		printf("CANDIDATO: %s\n\tVOTOS: %d\n", candidatos[i], votos[i]);
	}

	return 0;
}
