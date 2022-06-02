#include <stdio.h>
#include <stdlib.h>

void inverteVetor(int* v, int s){
  int temp;
  for(int i = 0, j = s - 1; i < j; i++, j--){
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
  }
}

void imprimeVetor(const int s, int v[s]){
  printf("[");
  for(int i = 0; i < s; i++){
    printf("%d, ", v[i]);
  }
  printf("]\n");
}


int main(){
  int n;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", &n);
  int v[n];
  for(int i = 0; i < n; i++){
    printf("Insira um elemento: ");
    scanf("%d", &v[i]);
  }
  imprimeVetor(n, v);
  inverteVetor(v, n);
  imprimeVetor(n, v);
  return 0;
}
