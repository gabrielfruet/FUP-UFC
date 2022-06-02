#include <stdio.h>

void imprime_vetor(int* v, int s){
	printf("[");
	for(int i = 0; i < s; i++){
		printf("%d, ", v[i]);
	}
	printf("]\n");
}

int main(){
	int m[3][20], n[3], uniao[40], inter[20], i = 0, j = 0, k = 0;
	int opc = 1, valor = 0, repetido = 0;
	for(i = 0; i < 3; i++){
		printf("Preencha o vetor %c:\n", 'A' + i);
		for(j = 0; j < 20 && opc; j++){
			repetido = 0;
			printf("Voce deseja inserir o %do numero? (1 - SIM, 0 - NAO)", j);
			scanf("%d", &opc);
			if(opc){
				printf("Insira um numero: ");
				scanf("%d", &valor);
				for(k = 0; k < j && !repetido; k++){
					repetido = valor == m[i][k];
				}
				if(!repetido){
					m[i][j] = valor;
				}else{
					printf("Valor repetido! digite novamente\n");
					j--;
				}
			}else{
				j--;
			}
		}
		opc = 1;
		n[i] = j;
	}
	printf("A: ");
	imprime_vetor(m[0], n[0]);
	printf("B: ");
	imprime_vetor(m[1], n[1]);
	printf("C: ");
	imprime_vetor(m[2], n[2]);
	int n_inter = 0, n_uniao = 0;
	//INSERINDO INTERSECAO
	for(i = 0; i < n[1]; i++){
		for(j = 0; j < n[2]; j++){
			if(m[1][i] == m[2][j]){
				inter[n_inter] = m[1][i];
				n_inter++;
			}
		}
	}
	printf("INTER: ");
	imprime_vetor(inter, n_inter);
	n_uniao = n_inter;
	//SEMPRE TERA AO MENOS TODOS OS ELEMENTOS DE UM NA UNIAO 
	for(i = 0; i < n_inter; i++){
		uniao[i] = inter[i];
	}
	int contido = 0;
	//FAZENDO A UNIAO
	for(i = 0; i < n[0]; i++){
		contido = 0;
		for(j = 0; j < n_inter && !contido; j++){
			contido = m[0][i] == inter[j];
		}
		if(!contido){
			uniao[n_uniao] = m[0][i];
			n_uniao++;
		}
	}
	printf("UNIAO: ");
	imprime_vetor(uniao, n_uniao);


	return 0;
}
