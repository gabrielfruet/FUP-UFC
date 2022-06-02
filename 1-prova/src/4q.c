#include <stdio.h>
#include <math.h>

int main(){
	int propina = 0, faltando = 0;
	printf("Digite a propina e o numero faltando: ");
	scanf("%d %d",&propina, &faltando);
	if(propina >= 10100){
		printf("Propina maxima 10100! usando 10100 como valor.\n");
		propina = 10100;
	}
	int tamanho = floor(log10(propina)) + 1;//ESSE LOG EH PRA PEGAR A QUANTIDADE DE ALGARISMOS DO NUMERO
	int decomposto[tamanho];
	//DECOMPOE OS DIGITOS DO NUMERO EM UM VETOR DE DIGITOS
	for(int contador = tamanho - 1; contador >= 0; contador--){
		decomposto[contador] = propina%10;
		propina /= 10;
	}
	int resultado = 0;
	for(int i = 0; i < tamanho; i++){
		if(decomposto[i] != faltando){
			resultado = resultado*10 + decomposto[i];
		}	
	}
	printf("NUMERO SEM O DIGITO: %d\n", resultado);
	return 0;
}
