#include <stdio.h>
#define TAM 100

int main(){
	double mercadorias[TAM][2];
	double vendas, preco;
	for(int i = 0; i < TAM; i++){
		printf("Digite o preco e as vendas da mercadoria com o ID %d: ", i);
		scanf("%lf %lf", &preco, &vendas);
		mercadorias[i][0] = preco;
		mercadorias[i][1] = vendas;
	}
	double total = 0;
	for(int i = 0; i < TAM; i++){
		total += mercadorias[i][0]*mercadorias[i][1];
	}
	printf("VALOR TOTAL DAS VENDAS : R$%.2lf\n",total);
	
}
