#include <stdio.h>
#include <stdlib.h>

void deleteChar(char* str, char c){
  int p = 0, i = 0;
  for(; str[i] != 0; i++){
    if(str[i] != c){
      str[p] = str[i];
      p++;
    }
  }
  str[p-1] = 0;
}

int main(){
  char str[100], take;
  printf("Digite uma string e uma letra para retirar: ");
  fgets(str, 99, stdin);
  scanf("%c", &take);
  deleteChar(str, take);
  printf("Palavra sem o caractere: %s\n", str);
  return 0;
}
