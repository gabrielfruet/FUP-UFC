#include <stdio.h>
#include "erro.h"

int ERRORNUM = 0;

char* error_message[] = {
  "",
  "Problema na abertura do arquivo.\n",
  "Formato de conta invalido.\n",
  "Conta nao encontrada.\n",
  "Operacao invalida.\n",
  "Valor invalido.\n",
  "Saldo insuficiente.\n",
  "Conta ja existe.\n"
};

void printError(){
  printf("%s", error_message[ERRORNUM]);
}
