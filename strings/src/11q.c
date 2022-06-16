#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

enum format_e {
  AMERICANO = 0b00000001,
  BRASILEIRO = 0b00000010,
  INVALIDO = 0b00000000
};

typedef struct data {
  uint16_t ano;
  uint8_t dia;  
  uint8_t mes;
  enum format_e formato;
}data_t;

data_t criaData(const char* data){
  data_t novaData;
  char* data_c = malloc(strlen(data) + 1);
  strcpy(data_c, data);
  char* parte_data = strtok(data_c, "/");
  int data_divida[3];
  for(int i = 0; i < 3; i++, parte_data = strtok(NULL, "/")){
    if(parte_data == NULL){
      novaData.ano = 0;
      novaData.mes = 0;
      novaData.dia = 0;
      novaData.formato = INVALIDO;
      return novaData;
    }
    data_divida[i] = atoi(parte_data);
  }
  novaData.ano = data_divida[2];
  if(data_divida[1] > 12 && data_divida[0] < 31){
    novaData.formato = AMERICANO; 
    novaData.mes = data_divida[0];
    novaData.dia = data_divida[1];
  }else if(data_divida[0] < 31 && data_divida[1] <= 12){
    novaData.formato = BRASILEIRO; 
    novaData.mes = data_divida[1];
    novaData.dia = data_divida[0];
  }else{
    memset(&novaData, 0, sizeof(data_t));
    novaData.formato = INVALIDO;
  }
  free(data_c);
  return novaData;
}

void imprimeData(const data_t data){
  switch(data.formato){
    case AMERICANO:
      printf("FORMATO : AMERICANO, DATA : %02d/%02d/%d\n", data.mes, data.dia, data.ano);
      break;
    case BRASILEIRO:
      printf("FORMATO : BRASILEIRO, DATA : %02d/%02d/%d\n", data.dia, data.mes, data.ano);
      break;
    case INVALIDO:
      printf("DATA INVALIDA!\n");
      break;
  }
}

int main(){
  char input[100]; 
  printf("Digite uma data no formato XX/XX/XXXX: ");
  fgets(input, 99, stdin);
  data_t data = criaData(input);
  imprimeData(data);
  return 0;
}
