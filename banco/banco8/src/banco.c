#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "contas.h"
#include "erro.h"
#define CRIAR_CONTA 1
#define REMOVER_CONTA 2
#define CREDITO 3
#define DEBITO 4
#define TRANSFERIR 5
#define CONSULTAR_SALDO 6
#define SAIR 0
#define BUFFER_SIZE 512

int main(){
  char buffer[BUFFER_SIZE];
  int opc;
  do{
    bool opcaoValida = false;
    printf("\nESCOLHA UMA DAS OPCOES\n");
    printf("1..........CRIAR CONTA\n");
    printf("2........REMOVER CONTA\n");
    printf("3..............CREDITO\n");
    printf("4...............DEBITO\n");
    printf("5...........TRANSFERIR\n");
    printf("6......CONSULTAR SALDO\n");
    printf("0.................SAIR\n");
    printf("Digite sua opcao: ");

    do{
      opc = atoi(fgets(buffer, BUFFER_SIZE, stdin));
      opcaoValida = opc <= 6 && opc >= 0;
      if(!opcaoValida){
        printf("Opcao invalida.\n");
      }
    }while(!opcaoValida);

    switch(opc){
      case CRIAR_CONTA:{
        struct Conta contaCriada;
        bool sair = false;
        contaCriada.saldo = 0;

        do{
          errornum = 0;
          printf("Digite o nome do titular da conta e o numero separados por virgula: ");
          fgets(buffer, BUFFER_SIZE, stdin);

          sair = strcmp(buffer, "sair\n") == 0;
          if(sair) break;

          char* tokens[2] = {
            strtok(buffer, ","),
            strtok(NULL, " ")
          };

          if(tokens[0] == NULL || tokens[1] == NULL){
            errornum = ERRO_INFORMACOES_INSUFICIENTES;
            printError();
            continue;
          }

          if(strcmp(buffer, "\n") == 0){
            errornum = ERRO_NOME_INVALIDO;
            printError();
            continue;
          }

          strncpy(contaCriada.titular, tokens[0], TITULAR_SIZE);
          contaCriada.numero = atoi(tokens[1]);

          criaConta(&contaCriada);

          if(handleError()){
            printf("Digite novamente.\n");
          }
        }while(errornum);
        if(!sair){
          printf("Conta criada com sucesso.\n");
        }
        break;
      }
      case REMOVER_CONTA:{
        bool sair = false;
        do{
          int numExcluir = 0;
          errornum = 0;
          printf("Digite o numero da conta que deseja excluir: \n");

          sair = strcmp(buffer, "sair\n") == 0;
          if(sair) break;
          numExcluir = atoi(fgets(buffer, BUFFER_SIZE, stdin));

          excluiConta(numExcluir);
          if(handleError()){
            printf("Digite novamente.\n");
          }
        }while(errornum);
        if(!sair){
          printf("Conta excluida com sucesso.\n");
        }
        break;
      }
      case CREDITO:{
        bool sair = false;
        do{
          errornum = 0;
          printf("Digite o valor que voce deseja debitar e o numero da conta: ");
          fgets(buffer, BUFFER_SIZE, stdin);

          sair = strcmp(buffer, "sair\n") == 0;
          if(sair) break;

          char* tokens[2] = {
            strtok(buffer, " "),
            strtok(NULL, " ")
          };

          if(tokens[0] == NULL || tokens[1] == NULL){
            printf("Faltando informacoes.\n");
            continue;
          }

          double valor = atof(tokens[0]);
          int numConta = atoi(tokens[1]);
          realizaCredito(numConta, valor);

          if(handleError()){
            printf("Digite novamente.\n");
          }
        }while(errornum);
        if(!sair){
          printf("Conta creditada com sucesso.\n");
        }
        break;
      }
      case DEBITO:{
        bool sair = false;
        do{
          errornum = 0;
          printf("Digite o valor que voce deseja creditar e o numero da conta: ");
          fgets(buffer, BUFFER_SIZE, stdin);

          sair = strcmp(buffer, "sair\n") == 0;
          if(sair) break;

          char* tokens[2] = {
            strtok(buffer, " "),
            strtok(NULL, " ")
          };

          if(tokens[0] == NULL || tokens[1] == NULL){
            printf("Faltando informacoes.\n");
            continue;
          }

          double valor = atof(tokens[0]);
          int numConta = atoi(tokens[1]);

          realizaDebito(numConta, valor);

          if(handleError()){
            printf("Digite novamente.\n");
          }
        }while(errornum);

        if(!sair){
          printf("Conta debitada com sucesso.\n");
        }
        break;
      }
      case TRANSFERIR:{
        bool sair = false;

        do{
          errornum = 0;
          printf("Digite o valor que voce deseja transferir e a conta de saida e entrada: ");
          fgets(buffer, BUFFER_SIZE, stdin);

          sair = strcmp(buffer, "sair\n") == 0;
          if(sair) break;

          char* tokens[3] = {
            strtok(buffer, " "),
            strtok(NULL, " "),
            strtok(NULL, " ")
          };

          if(tokens[0] == NULL || tokens[1] == NULL || tokens[2] == NULL){
            errornum = ERRO_INFORMACOES_INSUFICIENTES;
            printError();
            continue;
          }

          double valor = atof(tokens[0]);
          int numSaida = atoi(tokens[1]);
          int numEntrada = atoi(tokens[2]);

          realizaTransferencia(numSaida, numEntrada, valor);
          if(handleError()){
            printf("Digite novamente.\n");
          }
        }while(errornum);

        printf("Transferencia realizada com sucesso.\n");
        break;
      }
      case CONSULTAR_SALDO:{
        bool sair = false;
        do{
          errornum = 0;
          printf("Digite o numero da conta: ");
          
          sair = strcmp(buffer, "sair\n") == 0;
          if(sair) break;

          int numConta = atoi(fgets(buffer, BUFFER_SIZE, stdin));
          struct Conta consulta;
          procuraConta(numConta, &consulta);
          if(!handleError()){ 
            printf("NUMERO DA CONTA: %06d\nSALDO: %.2lf\nTITULAR: %s\n", consulta.numero, consulta.saldo, consulta.titular);
          }else{
            printf("Digite novamente.\n");
          }
        }while(errornum);
        break;
      }
      case SAIR:{ 
        printf("Saindo.\n");
        break;
      }
    }  
  }while(opc != SAIR);
}
