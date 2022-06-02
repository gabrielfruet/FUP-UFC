#include <stdio.h>
#include <math.h>

int main(){
	//TABELA PARA DESCRIPTOGRAFAR
	int table[9] = {7,8,9,1,2,3,4,5,6};
	int cripto = 0, uncripto = 0;
	printf("Digite o numero para descriptografar: ");
	scanf("%d", &cripto);
	int tamanho = floor(log10(cripto)) + 1;//ESSE LOG EH PRA PEGARA QUANTIDADE DE ALGARISMO DO NUMERO
	int contador = tamanho - 1;
	int decomposto[tamanho];
	//DECOMPOE O NUMERO EM UM VETOR DE ALGARISMOS
	while(cripto > 0){
		decomposto[contador] = table[(cripto % 10) - 1];
		cripto /= 10;
		contador--;
	}
	for(int i = 0; i < tamanho; i++){
		uncripto = decomposto[i] + (uncripto * 10);
	}
	printf("DESCRIPTOGRAFADO: %d\n", uncripto);
	return 0;
}
