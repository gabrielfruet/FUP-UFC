#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define CREDITO 1
#define DEBITO 2
#define TRANSFERIR 3
#define CONSULTAR_SALDO 4
#define SAIR 0

struct Conta{
  double saldo;
  int numero;
  char tipo[35];
};

/*
 * PROCURA CONTA POR NUM. RETORNA O PONTEIRO PARA A CONTA CASO EXISTA E NULL CASO NAO EXISTA;
 */
struct Conta* procuraContaPorNum(int numConta, struct Conta* contas, int qntdContas){
    for(int i = 0; i < qntdContas; i++){
      if(contas[i].numero == numConta){
        return &contas[i];
      }
    }
    return NULL;
}

bool realizaCredito(double credito, struct Conta* conta){
    if(credito < 0){
      printf("Valor nao pode ser negativo, voltando ao menu.\n");
      return false;
    }
    conta->saldo += credito;
    return true;
}

bool realizaDebito(double debito, struct Conta* conta){
    if(debito < 0){
      printf("Valor nao pode ser negativo, voltando ao menu.\n");
      return false;
    }
    if(debito > conta->saldo){
      printf("Debito nao pode ser maior que o saldo.\n");
      return false;
    }      
    conta->saldo -= debito;
    return true;
}

bool realizaTransferencia(double transferencia, struct Conta* contaSaida, struct Conta* contaEntrada){ 
  return  realizaDebito(transferencia, contaSaida) && realizaCredito(transferencia, contaEntrada);
}


int main(){
  char buffer[255];
  int nContas = 0;

  printf("Digite a quantidade de contas que deseja cadastrar: ");
  nContas = atoi(fgets(buffer, 255, stdin));

  struct Conta contas[nContas];
  memset(contas, 0, sizeof(struct Conta)*nContas);

  for(int i = 0; i < nContas; i++){
    printf("Digite o numero da %da conta: ", i + 1);
    contas[i].numero = atoi(fgets(buffer, 35, stdin));
    struct Conta* mesmoNumero = procuraContaPorNum(contas[i].numero, contas, i);
    if(mesmoNumero){
      printf("Numero de conta ja existe. Tente novamente.\n");
      i--;
    }
  }

  for(int i = 0; i < nContas; i++){
    printf("Digite o tipo da %da conta: ", i + 1);
    fgets(contas[i].tipo, 35, stdin);
    if(strcmp(contas[i].tipo, "\n") == 0){
      printf("Tipo invalido. Digite novamente\n");
      i--;
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
    struct Conta *conta1 = NULL, *conta2 = NULL;

    switch(opc){
      case CREDITO:
        printf("Digite o numero da conta que deseja fazer o credito ou uma conta que nao existe para sair: ");
        numConta = atoi(fgets(buffer,255,stdin));
        conta1 = procuraContaPorNum(numConta, contas, nContas);

        if(conta1 == NULL){

          printf("Conta selecionada inexiste. Voltando ao menu.\n");

        }else{

          printf("Digite o valor a ser creditado: ");
          double valorCreditado = atof(fgets(buffer, 255, stdin));
          realizaCredito(valorCreditado, conta1);

        }
        break;
      case DEBITO:
        printf("Digite o numero da conta que deseja fazer o debito ou uma conta que nao existe para sair: ");
        numConta = atoi(fgets(buffer,255,stdin));
        conta1 = procuraContaPorNum(numConta, contas, nContas);
        if(conta1 == NULL){
          printf("Conta selecionada inexiste. Voltando ao menu.\n");
        }else{
          printf("Digite o valor a ser debitado: ");
          double valorDebitado = atof(fgets(buffer, 255, stdin));
          realizaDebito(valorDebitado, conta1);
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
            conta1 = procuraContaPorNum(numConta1, contas, nContas);
            conta2 = procuraContaPorNum(numConta2, contas, nContas);

            if(conta1 == NULL || conta2 == NULL){
              printf("Conta selecionada inexiste. Voltando ao menu.\n");
            }else{
              printf("Digite o valor a ser debitado: ");
              double valorTransferido = atof(fgets(buffer, 255, stdin));
              realizaTransferencia(valorTransferido, conta1, conta2);
            }
          }
        }

        break;
      case CONSULTAR_SALDO:
        printf("Digite o numero da conta que voce deseja saber o saldo: ");
        numConta = atoi(fgets(buffer,255, stdin));
        conta1 = procuraContaPorNum(numConta, contas, nContas);

        if(conta1 == NULL){
          printf("Conta nao existe. Voltando ao menu.");
        }else{
          printf("SALDO: R$%.2lf", conta1->saldo);
        }
        break;
      case SAIR:
        printf("Saindo.\n");
        break;
    }
  }while(opc != 0);
  
  return 0;
}
