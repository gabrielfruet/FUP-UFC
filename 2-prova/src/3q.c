#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define DEFINIDAS 17
#define POS 1
#define NEG -1

char *palavras[] = {

  "arrochado",
  "abirobado",
  "corno",
  "bichim",
  "birita",
  "paia",
  "arretado",
  "abestado",
  "apapagaiado",
  "aperrear",
  "ariado",
  "arrumação",
  "babão",
  "bocó",
  "cagado",
  "espilicute",
  "estribado"
};

int valores[] = {
  POS, 
  NEG,
  NEG,
  POS,
  POS,
  NEG,
  POS,
  NEG,
  NEG,
  NEG,
  NEG,
  NEG,
  NEG,
  NEG,
  POS,
  POS,
  POS
};

int main(){
  char tweet[280];
  fgets(tweet, 280, stdin);
  char* ptr = tweet; 
  while(*ptr){
    *ptr = tolower(*ptr);
    ptr++;
  }

  int polarizacao = 0;
  for(int i = 0; i < DEFINIDAS; i++){
      if(strstr(tweet, palavras[i])){
        polarizacao += valores[i];
      }
  }

  if(polarizacao > 0){
    printf("positivo");
  }else if(polarizacao < 0){
    printf("negativo");
  }

  return 0;
}
