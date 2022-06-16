#include <stdio.h>
#include <stdlib.h>

void imprimeSufixos(char* str){
  if(*str){
    imprimeSufixos(str+1);
    printf("%s", str);
  }
}

int main(){
  char data[100];
  printf("Digite uma string: "); 
  fgets(data,100,stdin);
  imprimeSufixos(data);
  return 0;
}
