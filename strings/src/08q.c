#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printFromTo(const char* data, const int start, const int end){
  for(int i = start; i < end; i++){
    printf("%c", data[i]);
  } 
  puts(",");
}

int main(){
  int n;
  char data[100];
  printf("Digite um numero e uma cadeia de caracteres: ");
  scanf("%d ", &n);
  fgets(data, 99, stdin);
  int str_s = strlen(data);
  for(int i = 0; i < str_s - n; i++){
    printFromTo(data, i, i + n); 
  }
  return 0;
}
