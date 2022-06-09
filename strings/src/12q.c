#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>


void numeroPorExtenso(char* dest, const char* src){
  unsigned int num = atoi(src);
  const unsigned int num_ORIGINAL = num;
  char* unidades[] = {
    "um",
    "dois",
    "tres",
    "quatro",
    "cinco",
    "seis",
    "sete",
    "oito",
    "nove"
  }; 
  char* dez_a_dezenove[] = {
    "dez",
    "onze",
    "doze",
    "treze",
    "quatorze",
    "quinze",
    "dezesseis",
    "dezessete",
    "dezoito",
    "dezenove"
  };
  char* dezenas[] = {
    "vinte",
    "trinta",
    "quarenta",
    "cinquenta",
    "sessenta",
    "setenta",
    "oitenta",
    "noventa"
  };
  char* centenas[] = {
    "cem",
    "duzentos",
    "trezentos",
    "quatrocentos",
    "quinhentos",
    "seiscentos",
    "setecentos",
    "oitocentos",
    "novecentos",
  };
  bool precisa_de_e = false;
  if(num >= 1000){
    int vezes = num/1000;     
    if(vezes > 1){
      strcat(dest, unidades[vezes - 1]);      
      strcat(dest, " mil");
    }else{
      strcat(dest, "mil");
    }
    precisa_de_e = true;
    num %= 1000;
  }
  if(num >= 100){
    int vezes = num/100;
    strcat(dest, precisa_de_e ? " e " : num_ORIGINAL > 999 ? " " : "");
    strcat(dest, centenas[vezes - 1]);
    precisa_de_e = true;
    num %= 100;
  }
  if(num >= 10){
    int vezes = num/10; 
    if(vezes > 1){
      strcat(dest, precisa_de_e ? " e " : num_ORIGINAL > 99 ? " " : "");
      strcat(dest, dezenas[vezes - 2]);
      num %= 10;
      precisa_de_e = true;
    } 
  }
  if(num > 0){
    strcat(dest, precisa_de_e ? " e " : num_ORIGINAL > 99 ? " " : "");
    if(num > 9){
      strcat(dest, dez_a_dezenove[num - 10]);
    }else{
      strcat(dest, unidades[num - 1]);
    }
  }
  dest[0] = toupper(dest[0]);
}

int main(){
  char ano[10];
  printf("Digite um ano para descobrir por extenso: ");
  fgets(ano, 9, stdin);
  char ano_extenso[150] = "";
  numeroPorExtenso(ano_extenso, ano);
  printf("ANO POR EXTENSO: %s anos\n", ano_extenso);
  return 0;
}
