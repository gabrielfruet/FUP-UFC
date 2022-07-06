#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contas.h"
#include "erro.h"

bool existeConta(int num){
  char buffer[CONTAS_BUFFER_SIZE];
  FILE* contas_READ = fopen(CONTAS_PATH, "r");
  if(contas_READ == NULL){
    errornum = ERRO_ABERTURA_ARQUIVO;
    return false;
  }
  while(fgets(buffer, CONTAS_BUFFER_SIZE, contas_READ) != NULL){
    if(atoi(buffer) == num){
      fclose(contas_READ);
      return true;
    }
  }
  fclose(contas_READ);
  return false;
}

struct Conta parseConta(char* contastr){
  char* num = strtok(contastr, ",");
  char* saldo = strtok(NULL, ",'");
  char* titular = strtok(NULL, "'");

  if(num == NULL || saldo == NULL || titular == NULL){
    errornum = ERRO_FORMATO_CONTA_INVALIDO;
    struct Conta error;
    error.numero = -1;
    return error;
  }

  struct Conta convertida;
  convertida.numero = atoi(num);
  convertida.saldo = atof(saldo);
  strncpy(convertida.titular, titular, TITULAR_SIZE);
  return convertida;
}

int procuraConta(int num, struct Conta* dest){
  char buffer[CONTAS_BUFFER_SIZE];
  FILE* contas_READ = fopen(CONTAS_PATH, "r");
  if(contas_READ == NULL){
    errornum = ERRO_ABERTURA_ARQUIVO;
    return 0;
  }
  for(
      int linha = 0;
      fgets(buffer, CONTAS_BUFFER_SIZE, contas_READ) != NULL;
      linha++
      ){
    if(atoi(buffer) == num){
      if(dest != NULL){
        *dest = parseConta(buffer);
      }    
      fclose(contas_READ);
      return linha;
    }
  }
  fclose(contas_READ);
  errornum = ERRO_CONTA_NAO_ENCONTRADA; 
  return 0;
}

int excluiConta(int num){
  char buffer[CONTAS_BUFFER_SIZE];  
  FILE* contasREAD = fopen(CONTAS_PATH, "r");
  FILE* tempWRITE = fopen(TEMP_PATH, "w");

  if(contasREAD == NULL || tempWRITE == NULL){
    errornum = ERRO_ABERTURA_ARQUIVO;
    return 0;
  }

  struct Conta leitora;
  
  errornum = ERRO_CONTA_NAO_ENCONTRADA;
  while(fgets(buffer, CONTAS_BUFFER_SIZE, contasREAD) != NULL){
    leitora = parseConta(buffer);

    if(num != leitora.numero)
      fprintf(tempWRITE, CONTA_FORMAT, leitora.numero, leitora.saldo, leitora.titular);
    else
      errornum = 0;

  }
  fclose(contasREAD);
  fclose(tempWRITE);
  remove(CONTAS_PATH);
  rename(TEMP_PATH, CONTAS_PATH);
  return 1;
}

int atualizaConta(struct Conta* conta){
  char buffer[CONTAS_BUFFER_SIZE];
  FILE* contasREAD = fopen(CONTAS_PATH, "r");
  FILE* tempWRITE = fopen(TEMP_PATH, "w");

  if(contasREAD == NULL || tempWRITE == NULL){
    errornum = ERRO_ABERTURA_ARQUIVO;
    return 0;
  }

  struct Conta leitora;
  
  while(fgets(buffer, CONTAS_BUFFER_SIZE, contasREAD) != NULL){
    struct Conta* escrita;
    leitora = parseConta(buffer);

    if(conta->numero == leitora.numero)
      escrita = conta;
    else
      escrita = &leitora;

    fprintf(tempWRITE, CONTA_FORMAT, escrita->numero, escrita->saldo, escrita->titular);
  }
  fclose(contasREAD);
  fclose(tempWRITE);
  remove(CONTAS_PATH);
  rename(TEMP_PATH, CONTAS_PATH);
  return 1;
}

int criaConta(struct Conta* conta){
  FILE* conta_APPEND = fopen(CONTAS_PATH, "a");
  if(!existeConta(conta->numero)){
    fprintf(conta_APPEND, CONTA_FORMAT, conta->numero, conta->saldo, conta->titular);
  }else{
    errornum = ERRO_CONTA_JA_EXISTE;
    fclose(conta_APPEND);
    return 0;
  }
  fclose(conta_APPEND);
  return 1;
}

int realizaCredito(int num, double valor){
  if(valor <= 0){
    errornum = ERRO_VALOR_INVALIDO;
    return 0;
  }
  struct Conta conta;
  procuraConta(num, &conta);

  if(errornum){
    return 0;
  }

  conta.saldo += valor;
  return atualizaConta(&conta);
}

int realizaDebito(int num, double valor){
  if(valor <= 0){
    errornum = ERRO_VALOR_INVALIDO;
    return 0;
  }
  struct Conta conta;
  procuraConta(num, &conta);

  if(errornum){
    return 0;
  }

  if(valor > conta.saldo){
    errornum = ERRO_SALDO_INSUFICIENTE;
    return 0;
  } 
  conta.saldo -= valor;
  return atualizaConta(&conta);
}

int realizaTransferencia(int numSaida, int numEntrada, double valor){ 
  if(valor <= 0){
    errornum = ERRO_VALOR_INVALIDO;
    return 0;
  }
  struct Conta saida, entrada;
  procuraConta(numSaida, &saida);
  procuraConta(numEntrada, &entrada);
 
  if(errornum){
    return 0;
  }
  
  if(valor > saida.saldo){
    errornum = ERRO_SALDO_INSUFICIENTE;
    return 0;
  }
  saida.saldo -= valor;
  entrada.saldo += valor;
  
  atualizaConta(&saida);
  atualizaConta(&entrada);
  return errornum != 0;
}
