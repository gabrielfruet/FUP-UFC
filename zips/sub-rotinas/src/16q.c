#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void maiorNaPrimeira(const int s, int v[s]){
  int v_maior = INT_MIN, i_maior = 0;
  for(int i = 0; i < s; i++){
    if(v[i] > v_maior){
      v_maior = v[i];
      i_maior = i;
    }
  }
  int temp = v[i_maior];
  v[i_maior] = v[0];
  v[0] = temp;
  return;
}

void imprimeVetor(const int s, int v[s]){
  printf("[");
  for(int i = 0; i < s; i++){
    printf("%d, ", v[i]);
  }
  printf("]\n");
}

int main(){
  int s;
  printf("Digite o tamanho do vetor: \n");
  scanf("%d", &s);
  int v[s];
  for(int i = 0; i < s; i++){
    printf("Insira um elemento: ");
    scanf("%d", &v[i]);
  }
  imprimeVetor(s, v);
  maiorNaPrimeira(s, v);
  imprimeVetor(s, v);
  return 0;
}
