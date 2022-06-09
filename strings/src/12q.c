#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>


void trioPorExtenso(char* dest, unsigned int num){
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
    "cento",
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
  if(num >= 100){
    int vezes = num/100;
    strcat(dest, num == 100 ? "cem" : centenas[vezes - 1]);
    precisa_de_e = true;
    num %= 100;
  }
  if(num >= 10){
    int vezes = num/10; 
    if(vezes >= 2){
      strcat(dest, precisa_de_e ? " e " : num_ORIGINAL >= 100 ? " " : "");
      strcat(dest, dezenas[vezes - 2]);
      num %= 10;
      precisa_de_e = true;
    } 
  }
  if(num > 0){
    strcat(dest, precisa_de_e ? " e " : num_ORIGINAL >= 100 ? " " : "");
    if(num > 9){
      strcat(dest, dez_a_dezenove[num - 10]);
    }else{
      strcat(dest, unidades[num - 1]);
    }
  }
}


void numeroPorExtenso(char* dest, const char* src){
  unsigned int num = atoi(src);
  const unsigned int num_ORG = num;

  char* classes[5][2] = {
    {"mil"},
    {"milhao", "milhoes"},
    {"bilhao", "bilhoes"},
    {"trilhao", "trilhoes"},
    {"quadrilhao", "quadrilhao"}
  };
  bool precisa_de_separador = false;
  unsigned int trio = 1;

  for(int exp = 15; exp >= 0; exp -= 3){
    trio = num/pow(10,exp);
    num = num % (int)pow(10,exp);
    if(trio){
      if(precisa_de_separador)
        strcat(dest, exp == 0 ? " e " : ", ");

      trioPorExtenso(dest, trio);
      if(exp > 0){
        strcat(dest, " ");
        strcat(dest, classes[exp/3 - 1][trio > 1 && exp != 3]);
      }
      precisa_de_separador = true; 
    }
  }
  dest[0] = toupper(dest[0]);
}

int main(){
  char ano[11];
  printf("Digite um ano para descobrir por extenso: ");
  fgets(ano, 10, stdin);
  char ano_extenso[151] = "";
  numeroPorExtenso(ano_extenso, ano);
  printf("ANO POR EXTENSO: %s anos\n", ano_extenso);

  return 1;
}
