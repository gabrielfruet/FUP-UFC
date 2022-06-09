#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define inverte ^32

bool eLetra(char c){
  for(char letra = 'a'; letra < 'z'; letra++){
    if(c == letra || c == (letra inverte))
      return true;
  }
  return false;
}

void inverteCaixa(char* str){
  for(int c = 0; c < strlen(str); c++){
    if(eLetra(str[c]))
      str[c] = str[c] inverte;
  }
}

int main(){
  char data[100];
  printf("Digite um texto para inverter a caixa: ");
  fgets(data, 99, stdin);
  printf("PALAVRA DIGITADA: %s\n", data);
  inverteCaixa(data);
  printf("PALAVRA DIGITADA INVERTIDA: %s\n", data);
  return 0;
}
