#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

int* procuraOcorrencias(char *str, char c, int* s){
  int * out = malloc(sizeof(int)*strlen(str));
  *s = 0;
  for(int i = 0; str[i]; i++){
    if(str[i] == c){
      out[*s] = i;
      (*s)++;
    }
  }
  return out;
}

void imprimeVetor(const int s, int v[s]){
  printf("[");
  for(int i = 0; i < s; i++){
    printf("%d, ", v[i]);
  }
  printf("]\n");
}


int main(){
  char s[TAM], letra;
  printf("Digite uma palavra: ");
  fgets(s, TAM, stdin);
  printf("Digite a letra para procurar: ");
  scanf(" %c", &letra);
  int* size = malloc(sizeof(int));
  int* ocorrencias = procuraOcorrencias(s, letra, size);
  imprimeVetor(*size, ocorrencias);
  free(ocorrencias);
  free(size);
  return 0;
}
