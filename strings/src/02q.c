#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool ePalindromo(const char *str){
  for(int l = 0, r = strlen(str) - 2; l < r; l++, r--){
    if(str[l] != str[r])
      return false;
  }
  return true;
}

int main(){
  char data[100];
  printf("Digite uma palavra para verificar se eh palindromo: ");
  fgets(data, 99, stdin);
  if(ePalindromo(data)){
    puts("EH PALINDROMO!");
  }else{
    puts("NAO EH PALINDROMO");
  }
  return 0;
}
