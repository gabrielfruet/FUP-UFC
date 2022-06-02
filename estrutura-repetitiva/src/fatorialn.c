#include <stdio.h>

/*ALGORITMO
	DECLARE fatorial NUMERICO
	ESCREVA "Digite o fatorial que vc deseja: "
	LEIA  fatorial
	PARA  i <- 0 ATÉ     fatorial FAÇA
	INÍCIO
		total <- total * (i + 1)
	FIM
	ESCREVA fatorial, "! = " total
FIM_ALGORITMO.*/

int main(){
    long long int total = 1;
    int fatorial;
    printf("Digite o fatorial que vc deseja: ");
    scanf("%d", &fatorial);
    for(int i = 0; i < fatorial; i++){
        total = total * (i + 1);
    }
    printf("%d! = %lld\n", fatorial, total);
}