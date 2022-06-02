#include <stdio.h>
#include <limits.h>

int main(){
	int n;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	int v[n];
	for(int i = 0; i < n; i++){
		printf("Digite o elemento da posicao %d: ", i);
		scanf("%d", v + i);
	}
	int max = INT_MIN;
	int t = 0;
	for(int i = 0; i < n; i++){
		t += v[i];
		if(t < 0){
			t = 0;
		}
		if(t > max){
			max = t;
		}
	}
	printf("Soma maxima: %d", max);
	return 0;
}
