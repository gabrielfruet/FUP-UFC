#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define inverte ^= 32

bool eLetra(char c){
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void inverteCaixa(char* str){
  for(;*str; str++)
    if(eLetra(*str))
      *str inverte;
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
