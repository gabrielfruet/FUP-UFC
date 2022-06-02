#include <stdio.h>

int main(){
	int n;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &n);
	int v[n];
	for(int i = 0; i < n; i++){
		printf("Digite o elemento da posicao %d do vetor: ", i);
		scanf("%d", &v[i]);
	}
	int a = 0, b = 0, k = 0, finish = 0;
	for(int i = 0; i < n && !finish; i++){
		for(int j = i + 2; j < n && !finish; j++){
			if(v[i] == v[j]){
				for(a = i, b = j, k = 0; a < n && b < n && v[a] == v[b]; b++, a++, k++);
				if(k > 1){
					a = a - k;
					b = b - k;
					finish = 1;
				}
			}
		}
	}
	printf("i : %d\n", a + 1);
	printf("m : %d\n", k);
	return 0;
}
