#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool eSenha(const char* senha){
  int senha_s = strlen(senha);
  if(senha_s < 7 || senha_s > 15) return false;
  bool numerico = 0, minusc = 0, maiusc = 0; 
  //VERIFICA SE TEM OS TRES
  for(;*senha && (!numerico || !minusc || !maiusc); senha++){

    if(isupper(*senha)) maiusc = true;  
    else if(islower(*senha)) minusc = true;
    else if(isdigit(*senha)) numerico = true;

  }
  return numerico && minusc && maiusc;
}

int main(){
  char data[100];
  printf("Digite uma senha para verificar se eh valida: "); 
  fgets(data, 99, stdin);
  if(eSenha(data))
    puts("VALIDO!");
  else
    puts("INVALIDO!");
  return 1;
}
