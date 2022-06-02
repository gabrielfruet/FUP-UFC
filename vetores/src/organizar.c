#include <stdio.h>

void swap(int* a, int* b){
		int temp = *a;
		*a = *b;
		*b = temp;
}

int partition(int s, int e, int* v){
	int p = v[s];
	int l = s, r = e;
	while(l < r){
		while(v[l] <= p){
			l++;
		}
		while(v[r] > p){
			r--;
		}
		if(l < r){
			swap(v + l, v + r);
		}
	}
	swap(v + s, v + r);
	return r;
}

void quicksort(int s, int e, int* v){
	if(s < e){
		int pPos = partition(s, e, v);

		quicksort(s, pPos - 1, v);
		quicksort(pPos + 1, e, v);
	}
}

int findK(int* v, int s, int k){
	for(int i = 0; i < s; i++){
		if(v[i] == k){
			return i;
		}
	}
	return -1;
}

void printVector(int* v, int s){
	printf("[");
	for(int i = 0; i < s; i++){
		printf("%d, ", v[i]);
	}
	printf("]\n");
}

int main(){
	int size, k = -1;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &size);
	int v[size];
	for(int i = 0; i < size; i++){
		printf("Digite o %do valor: ", i + 1);
		scanf("%d", &v[i]);
	}
	printf("Digite um K para procurar no vetor: ");
	scanf("%d", &k);
	printf("Vetor antes de ser organizado: ");
	printVector(v, size);
	printf("Posicao do K antes de organizar: %d\n",findK(v, size, k));
	quicksort(0, size - 1, v);
	printf("Vetor depois de organizar");
	printVector(v, size);
	printf("Posicao do K depois de organizar: %d\n", findK(v, size, k));
	return 0;
}
