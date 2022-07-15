#include <stdio.h>
#include <stdlib.h>

int calcula_vizinhos(int pos, int n, int v[n]){

  int vizinhos = 0;

  vizinhos += v[pos];
  if(pos - 1 >= 0)
    vizinhos += v[pos - 1];
  if(pos + 1 < n)
    vizinhos += v[pos + 1];
  
  return vizinhos;
}

int main(){
  int tam = 0;
  scanf("%d", &tam);
  int campo[tam];
  for(int i = 0; i < tam; i++){
    scanf("%d", &campo[i]);
  }

  int vizinhos[tam];
  for(int i = 0; i < tam; i++){
    vizinhos[i] = calcula_vizinhos(i, tam, campo);
    printf(" %d", vizinhos[i]);
  }
  puts("");
  return 0;
}
