#include <stdio.h>
#include <math.h>

int main(){
	int n;
	printf("Digite a quantidade de valores que serao digitados: ");	
	scanf("%d", &n);
	double v[n];
	double soma = 0;
	for(int i = 0; i < n; i++){
		scanf("%lf", v + n);
		soma += v[n];
	}
	//calculando media
	double media = soma/n;
	double variancia = 0;
	//calculando variancia
	for(int i = 0; i < n; i++){
		variancia += pow(v[n] - media, 2); 
	}
	variancia /= n;
	double desvio = sqrt(variancia);
	printf("MEDIA: %lf\n", media);
	printf("VARIANCIA: %lf\n", variancia);
	printf("DESVIO PADRAO: %lf\n", desvio);


	return 0;
}
