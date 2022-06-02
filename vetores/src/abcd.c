#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <strings.h>

void elim_repeated(int* v, int* s){
	int l = 1;
	for(int i = 1; i < *s; i++){
		if(v[i] != v[i-1]){
			v[l] = v[i];
			l++;
		}
	}
	*s = l;
}

void count_each(int* v, int s){
	int which = v[0];
	int count = 1;
	for(int i = 1; i < s; i++){
		if(which != v[i]){
			printf("O NUMERO %d SE REPETIU %d VEZES\n", which, count);
			which = v[i];
			count = 1;
		}else{
			count++;
		}
	}
	printf("O NUMERO %d SE REPETIU %d VEZES\n", which, count);
}

void print_array(int* v, int s){
	printf("[");
	for(int i = 0; i < s; i++){
		printf("%d, ", v[i]);
	}
	printf("]\n");
}

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* v, int s, int e){
	int l = s, r = e;
	int p = v[s];
	while(l < r){
		while(v[l] <= p){
			l++;
		}
		while(v[r] > p){
			r--;
		}
		if(l < r){
			swap(v + r, v + l);
		}
	}
	swap(v + s, v + r);
	return r;
}

void quicksort(int* v, int s, int e){
	if(s < e){
		int p = partition(v, s, e);

		quicksort(v, s, p - 1);
		quicksort(v, p + 1, e);
	}
}

int main(){
	int tamanho = 0;
	printf("Digite o tamanho do vetor que voce deseja: ");
	scanf("%d", &tamanho);
	int vetor[tamanho];
	printf("Digite os elementos em ordem crescente:\n");
	for(int i = 0; i < tamanho; i++){
		printf("ELEMENTO %d", i); 
		scanf("%d", &vetor[i]);
	}
	print_array(vetor, tamanho);
	quicksort(vetor, 0, tamanho - 1);
	count_each(vetor, tamanho);
	elim_repeated(vetor, &tamanho);
	print_array(vetor, tamanho);
	return 0;
}
