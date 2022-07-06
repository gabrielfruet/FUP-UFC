#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define CREDITO 1
#define DEBITO 2
#define TRANSFERIR 3
#define CONSULTAR_SALDO 4
#define SAIR 0

int main(){
  char buffer[255];
  int nContas = 0;
  printf("Digite a quantidade de contas que deseja cadastrar: ");
  nContas = atoi(fgets(buffer, 255, stdin));

  int contas_numero[nContas];

  double contas_saldo[nContas];
  memset(contas_saldo, 0, nContas*sizeof(double));

  char contas_tipo[nContas][35];

  bool numerosUnicos = true;

  for(int i = 0; i < nContas; i++){
    printf("Digite o numero da %da conta: ", i + 1);
    contas_numero[i] = atoi(fgets(buffer, 255, stdin));
    for(int j = 0; j < i && numerosUnicos; j++){
      if(contas_numero[i] == contas_numero[j]){
        numerosUnicos = false;
        printf("Numero de conta ja existe, digite novamente.\n");
        i--;
      }
    }
  }

  for(int i = 0; i < nContas; i++){
    printf("Digite o tipo da %da conta: ", i + 1);
    fgets(buffer, 255, stdin);
    if(strcmp(buffer, "") == 0){
      printf("Tipo vazio, digite novamente.");
    }else{
      strncpy(contas_tipo[i], buffer, 35);
    }
  }
  int opc;

  do{
    printf("\nESCOLHA UMA DAS OPCOES\n");
    printf("1..............CREDITO\n");
    printf("2...............DEBITO\n");
    printf("3...........TRANSFERIR\n");
    printf("4......CONSULTAR SALDO\n");
    printf("0.................SAIR\n");
    printf("Digite sua opcao: ");
    bool opcaoValida;
    do{
      opc = atoi(fgets(buffer,255,stdin));
      opcaoValida = opc >= 0 && opc <= 4;
    }while(!opcaoValida);

    int numConta;
    double *saldoContaSelecionada1 = NULL, *saldoContaSelecionada2 = NULL;
    switch(opc){
      case CREDITO:
        printf("Digite o numero da conta que deseja fazer o credito ou uma conta que nao existe para sair: ");
        numConta = atoi(fgets(buffer,255,stdin));
        for(int i = 0; i < nContas; i++){
          if(contas_numero[i] == numConta){
            saldoContaSelecionada1 = &contas_saldo[i];
          }
        }
        if(saldoContaSelecionada1 == NULL){
          printf("Conta selecionada inexiste. Voltando ao menu.\n");
        }else{
          printf("Digite o valor a ser creditado: ");
          double valorCreditado = atof(fgets(buffer, 255, stdin));
          if(valorCreditado < 0){
            printf("Valor nao pode ser negativo, voltando ao menu.\n");
          }else{
            *saldoContaSelecionada1 += valorCreditado;
          }
        }
        break;
      case DEBITO:
        printf("Digite o numero da conta que deseja fazer o debito ou uma conta que nao existe para sair: ");
        numConta = atoi(fgets(buffer,255,stdin));
        for(int i = 0; i < nContas; i++){
          if(contas_numero[i] == numConta){
            saldoContaSelecionada1 = &contas_saldo[i];
          }
        }
        if(saldoContaSelecionada1 == NULL){
          printf("Conta selecionada inexiste. Voltando ao menu.\n");
        }else{
          printf("Digite o valor a ser debitado: ");
          double valorDebitado = atof(fgets(buffer, 255, stdin));
          if(valorDebitado < 0){
            printf("Valor nao pode ser negativo, voltando ao menu.\n");
          }else if(valorDebitado > *saldoContaSelecionada1){
            printf("Debito nao pode ser maior que o saldo.\n");
          }else{
            *saldoContaSelecionada1 -= valorDebitado;
          }
        }

        break;

      case TRANSFERIR:
        printf("Digite o numero da conta que transferira e da que recebera a transferencia: ");
        fgets(buffer,255,stdin);
        char* num1 = strtok(buffer, " ");
        char* num2 = strtok(NULL, " ");
        
        if(num1 == NULL || num2 == NULL){
          printf("Quantidade de contas digitadas insuficiente. Voltando ao menu\n");
        }else{
          int numConta1 = atoi(num1);
          int numConta2 = atoi(num2);
          if(numConta1 == numConta2){
            printf("Impossivel transferir para a mesma conta.\n");
          }else{
            for(int i = 0; i < nContas; i++){
              if(contas_numero[i] == numConta1){
                saldoContaSelecionada1 = &contas_saldo[i];
              }
              if(contas_numero[i] == numConta2){
                saldoContaSelecionada2 = &contas_saldo[i];
              }
            }

            if(saldoContaSelecionada1 == NULL || saldoContaSelecionada2 == NULL){
              printf("Conta selecionada inexiste. Voltando ao menu.\n");
            }else{
              printf("Digite o valor a ser debitado: ");
              double valorTransferido = atof(fgets(buffer, 255, stdin));
              if(valorTransferido < 0){
                printf("Valor nao pode ser negativo, voltando ao menu.\n");
              }else if(valorTransferido > *saldoContaSelecionada1){
                printf("Debito nao pode ser maior que o saldo.\n");
              }else{
                *saldoContaSelecionada1 -= valorTransferido;
                *saldoContaSelecionada2 += valorTransferido; 
              }
            }
          }
        }

        break;
      case CONSULTAR_SALDO:
        printf("Digite o numero da conta que voce deseja saber o saldo: ");
        numConta = atoi(fgets(buffer,255, stdin));

        for(int i = 0; i < nContas; i++){
          if(contas_numero[i] == numConta){
            saldoContaSelecionada1 = &contas_saldo[i];
          }
        }
        if(saldoContaSelecionada1 == NULL){
          printf("Conta nao existe. Voltando ao menu.");
        }else{
          printf("SALDO: R$%.2lf", *saldoContaSelecionada1);
        }

        break;
      case SAIR:
        printf("Saindo.\n");
        break;
    }
  }while(opc != 0);
  
  return 0;
}
