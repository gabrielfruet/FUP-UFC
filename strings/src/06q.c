#include <stdio.h>
#include <stdlib.h>

void imprimeSufixos(char* str){
  if(*str){
    printf("%s", str);
    imprimeSufixos(str+1);
  }
}

int main(){
  char data[100];
  printf("Digite uma string: "); 
  fgets(data,99,stdin);
  imprimeSufixos(data);
  return 0;
}

