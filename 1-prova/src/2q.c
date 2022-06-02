#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Digite o tamanho da sequencia: ");
	scanf("%d",&n);
	int sequencia[n];
	printf("Preencha a sequencia:\n");
	for(int i=0; i<n; i++){
		printf("Insira um numero: ");
		scanf("%d",&sequencia[i]);
		if(sequencia[i] >= 3000){
			printf("So podem existir valores menores que 3000!\n");
			i--;
		}
	}
	int atual = 0, feliz = 1;
	//FAZ O FOR ATE A SEQUENCIA SER INFELIZ OU ACABAR OS NUMEROS
	for(int i=1; i<n && feliz; i++){
		atual = abs(sequencia[i] - sequencia[i - 1]);
		feliz = atual > 0 && atual < n;
	}
	if(feliz){
		printf("FELIZ!\n");
	}else{
		printf("NAO FELIZ!\n");
	}
	return 0;
}
