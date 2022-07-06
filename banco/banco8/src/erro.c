#include <stdlib.h>
#include <stdio.h>
#include "erro.h"

int errornum = 0;

char* error_message[] = {
  "",
  "Problema na abertura do arquivo.\n",
  "Formato de conta invalido.\n",
  "Conta nao encontrada.\n",
  "Operacao invalida.\n",
  "Valor invalido.\n",
  "Saldo insuficiente.\n",
  "Conta ja existe.\n",
  "Informacoes insuficiente.\n",
  "Nome invalido.\n"
};

void printError(){
  printf("%s", error_message[errornum]);
}

int handleError(){
  if(errornum != 0){ 
    printError();
      if(errornum == ERRO_ABERTURA_ARQUIVO){
        exit(errornum);
      }
      return 1;
  }
  return 0;
}

