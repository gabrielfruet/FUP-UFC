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
  int conta1_numero = -1;
  int conta2_numero = -1;
  int conta3_numero = -1;

  double conta1_saldo = 0;
  double conta2_saldo = 0;
  double conta3_saldo = 0;

  char conta1_tipo[35];
  char conta2_tipo[35];
  char conta3_tipo[35];

  char buffer[255];

  bool numerosUnicos = true;
  bool numerosSuficientes = true;

  do{
    printf("Digite o numero da conta 1, 2 e 3 respectivamente: ");
    fgets(buffer,255, stdin);

    char* numero1 = strtok(buffer, " ");
    char* numero2 = strtok(NULL, " ");
    char* numero3 = strtok(NULL, " ");
    numerosSuficientes = numero1 != NULL && numero2 != NULL && numero3 != NULL;

    if(!numerosSuficientes){
      printf("Numeros digitados nao sao suficientes!\n");
      numerosSuficientes = false; 
    }else{
      conta1_numero = atoi(numero1);
      conta2_numero = atoi(numero2);
      conta3_numero = atoi(numero3);
      numerosUnicos = conta1_numero != conta2_numero && conta2_numero != conta3_numero && conta3_numero != conta1_numero;
      if(!numerosUnicos){
        printf("As contas possuem numeros iguais, digite novamente.\n");
      }
    }
  }while(!numerosUnicos || !numerosSuficientes);

  bool tiposSuficientes = true;
  do{
    printf("Digite os tipos das contas 1, 2 e 3 separados por vigula: ");
    fgets(buffer, 255, stdin);
    char* tipo1 = strtok(buffer, ",");
    char* tipo2 = strtok(NULL, ",");
    char* tipo3 = strtok(NULL, ",");
    tiposSuficientes = tipo1 != NULL && tipo2 != NULL && tipo3 != NULL;
    if(!tiposSuficientes){
      printf("Tipos insuficientes. Digite novamente.\n");
    }else{
      strncpy(conta1_tipo, tipo1, 35);
      strncpy(conta2_tipo, tipo2, 35);
      strncpy(conta3_tipo, tipo3, 35);
    }
  }while(!tiposSuficientes);

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
    switch(opc){
      case CREDITO:
        printf("Digite o numero da conta que deseja fazer o credito ou uma conta que nao existe para sair: ");
        numConta = atoi(fgets(buffer,255,stdin));
        
        printf("Digite o valor a ser creditado: ");
        double valorCreditado = atof(fgets(buffer, 255, stdin));
        if(valorCreditado < 0){
          printf("Valor nao pode ser negativo, voltando ao menu.");
        }else{
          if(numConta == conta1_numero){
            conta1_saldo += valorCreditado;
            printf("Operacao realizada com sucesso.\n");
          }else if(numConta == conta2_numero){
            conta2_saldo += valorCreditado;
            printf("Operacao realizada com sucesso.\n");
          }else if(numConta == conta3_numero){
            conta3_saldo += valorCreditado;
            printf("Operacao realizada com sucesso.\n");
          }else{
            printf("Conta invalida!, voltando ao menu.\n");
          }
        }
        break;
      case DEBITO:
        printf("Digite o numero da conta que deseja fazer o debito ou uma conta que nao existe para sair: ");
        numConta = atoi(fgets(buffer,255,stdin));
        
        printf("Digite o valor a ser debitado: ");
        double valorDebitado = atof(fgets(buffer, 255, stdin));
        if(valorDebitado < 0){
          printf("Valor nao pode ser negativo, voltando ao menu.");
        }else{
          if(numConta == conta1_numero && valorDebitado <= conta1_saldo){
            conta1_saldo -= valorDebitado;
            printf("Operacao realizada com sucesso.\n");
          }else if(numConta == conta2_numero && valorDebitado <= conta2_saldo){
            conta2_saldo -= valorDebitado;
            printf("Operacao realizada com sucesso.\n");
          }else if(numConta == conta3_numero && valorDebitado <= conta3_saldo){
            conta3_saldo -= valorDebitado;
            printf("Operacao realizada com sucesso.\n");
          }else{
            printf("Conta invalida ou saldo insuficiente!, voltando ao menu.\n");
          }
        }
        break;

      case TRANSFERIR:
        printf("Digite o numero da conta que transferira e da que recebera a transferencia: ");
        fgets(buffer,255,stdin);
        char* num1 = strtok(buffer, " ");
        char* num2 = strtok(NULL, " ");
        
        if(num1 == NULL || num2 == NULL){
          printf("Quantidade de contas digitadas insuficiente\n");
        }else{
          int numConta1 = atoi(num1);
          int numConta2 = atoi(num2);
          bool existeContaNum1 = numConta1 == conta1_numero || numConta1 == conta2_numero || numConta1 == conta3_numero;
          bool existeContaNum2 = numConta2 == conta1_numero || numConta2 == conta2_numero || numConta2 == conta3_numero;

          if(numConta1 == numConta2 || !existeContaNum1 || !existeContaNum2){
            printf("Numero das contas invalido. Voltando ao menu\n");
          }else{
            printf("Digite o valor a ser transferido: ");
            double valorTransferido = atof(fgets(buffer,255, stdin));
            bool saldoInsuficiente = false;
            if(valorTransferido < 0){
              printf("Valor deve ser maior que 0. Voltando ao menu\n");
            }else{
              //DEBITANDO
              if(numConta1 == conta1_numero && valorTransferido <= conta1_saldo){
                conta1_saldo -= valorTransferido;
              }else if(numConta1 == conta2_numero && valorTransferido <= conta2_saldo){
                conta2_saldo -= valorTransferido;
              }else if(numConta1 == conta3_numero && valorTransferido <= conta3_saldo){
                conta3_saldo -= valorTransferido;
              }else{
                saldoInsuficiente = true;
              }
              //CREDITANDO
              if(saldoInsuficiente){
                printf("Saldo insuficiente.\n");
              }else{
                if(numConta2 == conta1_numero){
                  conta1_saldo += valorTransferido;
                }else if(numConta2 == conta2_numero){
                  conta2_saldo += valorTransferido;
                }else if(numConta2 == conta3_numero){
                  conta3_saldo += valorTransferido;
                }
                printf("Operacao realizada com sucesso.\n");
              }
            }
          }
        }

        break;
      case CONSULTAR_SALDO:
        printf("Digite o numero da conta que voce deseja saber o saldo: ");
        numConta = atoi(fgets(buffer,255, stdin));

        bool existeContaNum = numConta == conta1_numero || numConta == conta2_numero || numConta == conta3_numero;

        if(!existeContaNum){
          printf("Conta nao existe. Voltando ao menu.\n");
        }else{
          double* saldoDaContaEscolhida;

          if(numConta == conta1_numero){
            saldoDaContaEscolhida = &conta1_saldo;
          }else if(numConta == conta2_numero){
            saldoDaContaEscolhida = &conta2_saldo;
          }else if(numConta == conta3_numero){
            saldoDaContaEscolhida = &conta3_saldo;
          }

          printf("SALDO: R$%0.2lf\n", *saldoDaContaEscolhida);
          printf("Operacao realizada com sucesso.\n");
        }
        break;
      case SAIR:
        printf("Saindo.\n");
        break;
    }
  }while(opc != 0);
  
  return 0;
}
