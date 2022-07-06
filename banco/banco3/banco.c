#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define CREDITO 1
#define DEBITO 2
#define TRANSFERIR 3
#define CONSULTAR_SALDO 4
#define SAIR 0

/*
 * PROCURA CONTA POR NUM. RETORNA O INDICE CASO EXISTA E -1 CASO NAO EXISTA;
 */
int procuraContaPorNum(int numConta, int* contas_numero, int qntdContas){
    for(int i = 0; i < qntdContas; i++){
      if(contas_numero[i] == numConta){
        return i;
      }
    }
    return -1;
}

bool realizaCredito(double credito, double* saldoDaConta){
    if(credito < 0){
      printf("Valor nao pode ser negativo, voltando ao menu.\n");
      return false;
    }
    *saldoDaConta += credito;
    return true;
}

bool realizaDebito(double debito, double* saldoDaConta){
    if(debito < 0){
      printf("Valor nao pode ser negativo, voltando ao menu.\n");
      return false;
    }
    if(debito > *saldoDaConta){
      printf("Debito nao pode ser maior que o saldo.\n");
      return false;
    }      
    *saldoDaConta -= debito;
    return true;
}

bool realizaTransferencia(double transferencia, double* saldoDaContaSaida, double* saldoDaContaEntrada){ 
  return  realizaDebito(transferencia, saldoDaContaSaida) && realizaCredito(transferencia, saldoDaContaEntrada);
}


int main(){
  char buffer[255];
  int nContas = 0;
  printf("Digite a quantidade de contas que deseja cadastrar: ");
  nContas = atoi(fgets(buffer, 255, stdin));

  int contas_numero[nContas];

  double contas_saldo[nContas];
  memset(contas_saldo, 0, nContas*sizeof(double));

  char contas_tipo[nContas][35];

  for(int i = 0; i < nContas; i++){
    printf("Digite o numero da %da conta: ", i + 1);
    contas_numero[i] = atoi(fgets(buffer, 255, stdin));
    int indice = procuraContaPorNum(contas_numero[i], contas_numero, i);
    if(indice != -1){
      printf("Numero de conta ja existe. Tente novamente.\n");
      i--;
    }
  }

  for(int i = 0; i < nContas; i++){
    printf("Digite o tipo da %da conta: ", i + 1);
    fgets(buffer, 255, stdin);
    if(strcmp(buffer, "\n") == 0){
      printf("Tipo vazio, digite novamente.\n");
      i--;
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
    int indiceConta1, indiceConta2;

    switch(opc){
      case CREDITO:
        printf("Digite o numero da conta que deseja fazer o credito ou uma conta que nao existe para sair: ");
        numConta = atoi(fgets(buffer,255,stdin));
        indiceConta1 = procuraContaPorNum(numConta, contas_numero, nContas);

        if(indiceConta1 == -1){

          printf("Conta selecionada inexiste. Voltando ao menu.\n");

        }else{

          printf("Digite o valor a ser creditado: ");
          double valorCreditado = atof(fgets(buffer, 255, stdin));
          realizaCredito(valorCreditado, &contas_saldo[indiceConta1]);

        }
        break;
      case DEBITO:
        printf("Digite o numero da conta que deseja fazer o debito ou uma conta que nao existe para sair: ");
        numConta = atoi(fgets(buffer,255,stdin));
        indiceConta1 = procuraContaPorNum(numConta, contas_numero, nContas);
        if(indiceConta1 == -1){
          printf("Conta selecionada inexiste. Voltando ao menu.\n");
        }else{
          printf("Digite o valor a ser debitado: ");
          double valorDebitado = atof(fgets(buffer, 255, stdin));
          realizaDebito(valorDebitado, &contas_saldo[indiceConta1]);
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
            indiceConta1 = procuraContaPorNum(numConta1, contas_numero, nContas);
            indiceConta2 = procuraContaPorNum(numConta2, contas_numero, nContas);

            if(indiceConta1 == -1 || indiceConta2 == -1){
              printf("Conta selecionada inexiste. Voltando ao menu.\n");
            }else{
              printf("Digite o valor a ser debitado: ");
              double valorTransferido = atof(fgets(buffer, 255, stdin));
              realizaTransferencia(valorTransferido, &contas_saldo[indiceConta1], &contas_saldo[indiceConta2]);
            }
          }
        }

        break;
      case CONSULTAR_SALDO:
        printf("Digite o numero da conta que voce deseja saber o saldo: ");
        numConta = atoi(fgets(buffer,255, stdin));
        indiceConta1 = procuraContaPorNum(numConta, contas_numero, nContas);

        if(indiceConta1 == -1){
          printf("Conta nao existe. Voltando ao menu.");
        }else{
          printf("SALDO: R$%.2lf", contas_saldo[indiceConta1]);
        }
        break;
      case SAIR:
        printf("Saindo.\n");
        break;
    }
  }while(opc != 0);
  
  return 0;
}
