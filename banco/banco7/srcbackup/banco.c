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
    }while(!opcaoValida);

    switch(opc){
      case CRIAR_CONTA:{
        struct Conta contaCriada;
        bool sair = false;
        contaCriada.saldo = 0;
        printf("Digite o nome do titular da conta ou sair: ");
        bool titularValido;
        //LE O NOME DO TITULAR E VERIFICA SE ESTA CORRETO
        do{
          fgets(contaCriada.titular, TITULAR_SIZE, stdin);
          contaCriada.titular[strcspn(contaCriada.titular, "\n")] = 0;
          titularValido = strcmp(contaCriada.titular, "");
          if(strcmp(buffer, "sair\n") == 0){
            sair = true;
            break;
          }
          if(!titularValido){
            printf("Titular invalido! digite novamente.");
          }
        }while(!titularValido);

        if(sair) break;

        do{
          ERRORNUM = 0;
          printf("Digite o numero da conta a ser criada: ");
          contaCriada.numero = atoi(fgets(buffer, BUFFER_SIZE, stdin));
          criaConta(&contaCriada);
          if(ERRORNUM){ 
            printError();
            if(ERRORNUM == ERRO_ABERTURA_ARQUIVO){
              exit(ERRORNUM);
            }
            printf("Digite novamente.\n");
          }
        }while(ERRORNUM);
        printf("Conta criada com sucesso.\n");
        break;
      }
      case REMOVER_CONTA:{
        int numExcluir = 0;
        do{
          ERRORNUM = 0;
          printf("Digite o numero da conta que deseja excluir: \n");
          numExcluir = atoi(fgets(buffer, BUFFER_SIZE, stdin));
          excluiConta(numExcluir);
          if(ERRORNUM){ 
            printError();
            if(ERRORNUM == ERRO_ABERTURA_ARQUIVO){
              exit(ERRORNUM);
            }
            printf("Digite novamente.\n");
          }
        }while(ERRORNUM);

        printf("Conta excluida com sucesso.\n");
        break;
      }
      case CREDITO:{
        do{
          ERRORNUM = 0;
          printf("Digite o valor que voce deseja creditar: ");
          double valor = atof(fgets(buffer, BUFFER_SIZE, stdin));

          printf("Digite o numero da conta que voce deseja realizar o credito: ");
          int numConta = atoi(fgets(buffer, BUFFER_SIZE, stdin));

          realizaCredito(numConta, valor);

          if(ERRORNUM){ 
            printError();
            if(ERRORNUM == ERRO_ABERTURA_ARQUIVO){
              exit(ERRORNUM);
            }
            printf("Digite novamente.\n");
          }
        }while(ERRORNUM);
        
        printf("Conta creditada com sucesso.\n");
        break;
      }
      case DEBITO:{

        do{
          ERRORNUM = 0;
          printf("Digite o valor que voce deseja debitar: ");
          double valor = atof(fgets(buffer, BUFFER_SIZE, stdin));

          printf("Digite o numero da conta que voce deseja realizar o credito: ");
          int numConta = atoi(fgets(buffer, BUFFER_SIZE, stdin));

          realizaDebito(numConta, valor);

          if(ERRORNUM){ 
            printError();
            if(ERRORNUM == ERRO_ABERTURA_ARQUIVO){
              exit(ERRORNUM);
            }
            printf("Digite novamente.\n");
          }
        }while(ERRORNUM);
        printf("Conta debitada com sucesso.\n");
        break;
      }
      case TRANSFERIR:{

        bool contasValidas = false;
        do{
          ERRORNUM = 0;
          printf("Digite o valor que voce deseja transferir: ");
          double valor = atof(fgets(buffer, BUFFER_SIZE, stdin));
          char *contaSaidaTOKEN,*contaEntradaTOKEN;
          do{
            printf("Digite o numero de que conta para que conta voce ira transferir ou sair: ");
            fgets(buffer, BUFFER_SIZE, stdin);
            contaSaidaTOKEN = strtok(buffer, " ");
            contaEntradaTOKEN = strtok(NULL, " ");
            contasValidas = contaEntradaTOKEN != NULL && contaSaidaTOKEN != NULL;
          }while(!contasValidas);

          int numSaida = atoi(contaSaidaTOKEN);
          int numEntrada = atoi(contaEntradaTOKEN);
          realizaTransferencia(numSaida, numEntrada, valor);
          if(ERRORNUM){ 
            printError();
            if(ERRORNUM == ERRO_ABERTURA_ARQUIVO){
              exit(ERRORNUM);
            }
            printf("Digite novamente.\n");
          }
        }while(ERRORNUM);

        printf("Transferencia realizada com sucesso.\n");
        break;
      }
      case CONSULTAR_SALDO:{
        do{
          ERRORNUM = 0;
          printf("Digite o numero da conta: ");
          int numConta = atoi(fgets(buffer, BUFFER_SIZE, stdin));
          struct Conta consulta;
          procuraConta(numConta, &consulta);
          if(!ERRORNUM){ 
            printf("NUMERO DA CONTA: %06d\nSALDO: %.2lf\nTITULAR: %s\n", consulta.numero, consulta.saldo, consulta.titular);
          }else{
            printError();
            if(ERRORNUM == ERRO_ABERTURA_ARQUIVO){
              exit(ERRORNUM);
            }
            printf("Digite novamente.\n");
          }
        }while(ERRORNUM);
        break;
      }
      case SAIR:{ 
        printf("Saindo.\n");
        break;
      }
    }  
  }while(opc != SAIR);
}
