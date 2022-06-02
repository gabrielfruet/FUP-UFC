#include <stdio.h>
#include <stdlib.h>
#define upper & ~32

int eVogal(char c){
  char *vogais = "aeiou", vogal;
  while((vogal = *(vogais++))){
    if(c == vogal || c == (vogal upper)){
      return 1;
    }
  }
  return 0;
}

int main(){
  int letra;
  printf("Digite uma letra para saber se eh vogal: "); 
  scanf(" %c", &letra);
  if(eVogal(letra)){
    printf("Eh vogal!\n");
  }else{
    printf("Nao eh vogal!\n");
  }
  return 0;
}
