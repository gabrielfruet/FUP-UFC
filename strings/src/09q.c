#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int strcnt(char *str, char c){
  int count = 0;
  while(*str)
    if(*str++ == c)
      count++;
  return count;
}

bool isEmail(char* str){
  return strcnt(str, '@') == 1 && strstr(strchr(str, '@'), ".com\n"); 
}

int main(){
  char data[100];
  printf("Digite uma sentenca para verificar se eh um email: "); 
  fgets(data, 99, stdin);
  if(isEmail(data)){
    puts("EH EMAIL!");
  }else{
    puts("NAO EH EMAIL!");
  }
  return 1;
}
