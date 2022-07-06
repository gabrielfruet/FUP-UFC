#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contas.h"
#include "erro.h"

bool existeConta(int num){
  struct Conta leitora;
  FILE* contas_READ = fopen(CONTAS_PATH, "rb");
  if(contas_READ == NULL){
    errornum = ERRO_ABERTURA_ARQUIVO;
    return false;
  }
  while(fread(&leitora, sizeof(struct Conta), 1, contas_READ) == 1){
    if(leitora.numero == num){
      fclose(contas_READ);
      return true;
    }
  }
  fclose(contas_READ);
  return false;
}

int procuraConta(int num, struct Conta* dest){
  struct Conta leitora;
  FILE* contas_READ = fopen(CONTAS_PATH, "rb");
  if(contas_READ == NULL){
    errornum = ERRO_ABERTURA_ARQUIVO;
    return -1;
  }
  for(
      int pos = 0;
      fread(&leitora, sizeof(struct Conta), 1, contas_READ) == 1;
      pos++
      ){
    if(leitora.numero == num){
      if(dest != NULL){
        memcpy(dest, &leitora, sizeof(struct Conta));
      }    
      fclose(contas_READ);
      return pos;
    }
  }
  fclose(contas_READ);
  errornum = ERRO_CONTA_NAO_ENCONTRADA; 
  return -1;
}

int excluiConta(int num){
  struct Conta leitora;
  FILE* contasREAD = fopen(CONTAS_PATH, "rb");
  FILE* tempWRITE = fopen(TEMP_PATH, "wb");

  if(contasREAD == NULL || tempWRITE == NULL){
    errornum = ERRO_ABERTURA_ARQUIVO;
    return 0;
  }

  int quantidadeAntes = procuraConta(num, NULL);
  if(quantidadeAntes == -1){
    errornum = ERRO_CONTA_NAO_ENCONTRADA;
    return 0;
  }
  struct Conta antes[quantidadeAntes];
  fread(antes, sizeof(struct Conta), quantidadeAntes, contasREAD);
  fwrite(antes, sizeof(struct Conta), quantidadeAntes, tempWRITE);
  fread(&leitora, sizeof(struct Conta), 1, contasREAD);
  
  while(fread(&leitora, sizeof(struct Conta), 1, contasREAD) == 1){
    fwrite(&leitora, sizeof(struct Conta), 1, tempWRITE);
  }
  fclose(contasREAD);
  fclose(tempWRITE);
  remove(CONTAS_PATH);
  rename(TEMP_PATH, CONTAS_PATH);
  return 1;
}

int atualizaConta(struct Conta* conta){
  FILE* contasREAD = fopen(CONTAS_PATH, "rb");
  FILE* tempWRITE = fopen(TEMP_PATH, "wb");

  if(contasREAD == NULL || tempWRITE == NULL){
    errornum = ERRO_ABERTURA_ARQUIVO;
    return 0;
  }

  int quantidadeAntes = procuraConta(conta->numero, NULL);
  struct Conta antes[quantidadeAntes];
  fread(antes, sizeof(struct Conta), quantidadeAntes, contasREAD);
  fwrite(antes, sizeof(struct Conta), quantidadeAntes, tempWRITE);
  fread(antes, sizeof(struct Conta), 1, contasREAD);
  fwrite(conta, sizeof(struct Conta), 1, tempWRITE);

  struct Conta leitora;
  
  while(fread(&leitora, sizeof(struct Conta), 1, contasREAD) == 1){
    fwrite(&leitora, sizeof(struct Conta), 1, tempWRITE);
  }
  fclose(contasREAD);
  fclose(tempWRITE);
  remove(CONTAS_PATH);
  rename(TEMP_PATH, CONTAS_PATH);
  return 1;
}

int criaConta(struct Conta* conta){
  FILE* conta_APPEND = fopen(CONTAS_PATH, "ab");
  if(!existeConta(conta->numero)){
    fwrite(conta, sizeof(struct Conta), 1, conta_APPEND);
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
