#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* lastAsFirst(char* str){
  int size = strlen(str);
  char* lastWord = strrchr(str, ' '); 
  if(lastWord == NULL){
    char* err_return = calloc(size, sizeof(char));
    strcpy(err_return, str);
    return err_return; 
  }
  *lastWord = 0;
  int lastWordIndex = lastWord - str + 1; 
  int lastWordSize = size - lastWordIndex;

  char* output = calloc(size + 1, sizeof(char));
  output[size] = 0;

  strcat(output, lastWord + 1);
  strcat(output, ", ");
  strcat(output, str);
  return output;

}

int main(){
  char nome[100];
  printf("Digite seu nome: ");
  fgets(nome, 100, stdin);
  nome[strlen(nome) - 1] = '\0';
  char* novoNome = lastAsFirst(nome);
  printf("Nome refatorado : %s\n", novoNome);
  free(novoNome);
  return 0;
}
