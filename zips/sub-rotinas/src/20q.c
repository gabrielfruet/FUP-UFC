#include <stdio.h>
#include <stdlib.h>

void excluiOcorrencias(int* v, int *s, int e){
  int p = 0;
  for(int i = 0; i < *s; i++){
    if(v[i] != e){
      v[p] = v[i];
      p++;
    }
  }
  *s = p;
}

void imprimeVetor(const int s, int v[s]){
  printf("[");
  for(int i = 0; i < s; i++){
    printf("%d, ", v[i]);
  }
  printf("]\n");
}


int main(){
  int *s = malloc(sizeof(int)), e;
  printf("Digite o tamanho do vetor: ");
  scanf("%d", s);
  printf("Digite o elemento a ser excluido: ");
  scanf("%d", &e);
  int v[*s];
  for(int i = 0; i < *s; i++){
    printf("Insira um elemento: ");
    scanf("%d", &v[i]);
  }
  imprimeVetor(*s , v);
  excluiOcorrencias(v, s, e);
  imprimeVetor(*s, v);
  free(s);
  return 0;
}
