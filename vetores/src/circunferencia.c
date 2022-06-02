#include <stdio.h>
#include <math.h>

typedef struct{
	double x, y;	
}Ponto;

int main(){
	Ponto centro;
	printf("Digite os pontos do centro da circunferencia x e y: ");
	scanf("%lf %lf", &centro.x, &centro.y);
	int n;
	printf("Digite a quantidade de pontos: ");
	scanf("%d", &n);
	Ponto pontos[n];
	for(int i = 0; i < n; i++){
		printf("Digite as coordenadas x e y do ponto %d: ", i + 1);
		scanf("%lf %lf", &pontos[i].x, &pontos[i].y);
	}
	double r[n];
	int s_r = 0;
	for(int i = 0; i < n; i++){
		r[s_r] = sqrt(pow(centro.x - pontos[i].x, 2) + pow(centro.y - pontos[i].y, 2));
		//verifica se existe outra ocorrencia desse raio
		int k = 0;
		for(k = 0; k < s_r && r[k] != r[s_r]; k++);
		if(k == s_r){
			s_r++;
		}
	}
	printf("[");
	for(int i = 0; i < s_r; i++){
		printf("%lf, ", r[i]);
	}
	printf("]\n");
	return 0;
}
