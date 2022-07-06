#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define CRIAR_CONTA 1
#define REMOVER_CONTA 2
#define CREDITO 3
#define DEBITO 4
#define TRANSFERIR 5
#define CONSULTAR_SALDO 6
#define SAIR 0
#define CONTA_FORMAT "%d,%lf,'%s'\n"
#define CONTAS_PATH "./data/contas.csv"
#define TEMP_PATH "./data/contas.temp"
#define BUFFER_SIZE 512
#define TITULAR_SIZE 50

struct Conta{
  char titular[TITULAR_SIZE];
  double saldo;
  int numero;
};


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

        bool numeroValido = true;
        //LE O NUMERO E VERIFICA SE EXISTE
        do{

          FILE* conta_READ = fopen(CONTAS_PATH, "r");
          if(conta_READ == NULL){
            printf("ERRO NA ABERTURA DO ARQUIVO.\n");
            exit(1);
          }

          numeroValido = true;
          printf("Digite o numero da conta: "); 
          contaCriada.numero = atoi(fgets(buffer, BUFFER_SIZE, stdin));

          while(fgets(buffer, BUFFER_SIZE, conta_READ) != NULL && numeroValido){
            numeroValido = atoi(buffer) != contaCriada.numero;
          }

          if(!numeroValido){
            printf("Numero invalido. Digite novamente.\n");
          }
          
          fclose(conta_READ);
        }while(!numeroValido);

        FILE *conta_APPEND = fopen(CONTAS_PATH, "a");
        if(conta_APPEND == NULL){
          printf("ERRO NA ABERTURA DO ARQUIVO.\n");
          exit(1);
        }

        fprintf(conta_APPEND, CONTA_FORMAT, contaCriada.numero, contaCriada.saldo, contaCriada.titular);

        fclose(conta_APPEND);
        break;
      }
      case REMOVER_CONTA:{
        bool numeroValido = false;
        bool sair = false;
        int linhaParaRemover = 0;
        do{
          numeroValido = false;
          FILE* conta_READ = fopen(CONTAS_PATH, "r");
          printf("Digite o numero da conta que voce deseja remover ou sair: ");
          int numParaRemover = atoi(fgets(buffer, BUFFER_SIZE, stdin));
          if(strcmp(buffer, "sair\n") == 0){
            sair = true;
            break;
          }

          for(
              linhaParaRemover = 0; 
              !numeroValido && fgets(buffer, BUFFER_SIZE, conta_READ) != NULL; 
              linhaParaRemover++
              ){
            numeroValido = atoi(buffer) == numParaRemover;
          }
          linhaParaRemover--;
          if(!numeroValido){
            printf("Numero invalido. Digite novamente.\n");
            linhaParaRemover = -1;
          } 
          fclose(conta_READ); 
        }while(!numeroValido); 

        if(sair) break;

        FILE* conta_READ = fopen(CONTAS_PATH, "r");
        FILE* conta_WRITE_TEMP = fopen(TEMP_PATH, "w");
        if(conta_READ == NULL || conta_WRITE_TEMP == NULL){
          printf("ERRO NA ABERTURA DOS ARQUIVOS.\n");
          exit(1);
        }
        
        for(int linha = 0; fgets(buffer, BUFFER_SIZE, conta_READ) != NULL; linha++){
          if(linha != linhaParaRemover){
            fputs(buffer, conta_WRITE_TEMP);
          }
        }

        fclose(conta_WRITE_TEMP);
        fclose(conta_READ);
        
        remove(CONTAS_PATH);
        rename(TEMP_PATH, CONTAS_PATH);
        printf("Conta excluida com sucesso.\n");
        break;
      }
      case CREDITO:{
        printf("Digite o valor que voce deseja creditar: ");
        double credito = atof(fgets(buffer, BUFFER_SIZE, stdin));
        if(credito < 0){
          printf("Credito menor que zero. Voltando ao menu.\n");
          break;
        }
        bool numeroValido = false;
        bool sair = false;
        int linhaParaCreditar = 0;
        struct Conta contaCredito;

        do{
          printf("Digite o numero da conta ou sair: ");
          int numeroConta = atoi(fgets(buffer, BUFFER_SIZE, stdin));
          if(strcmp(buffer, "sair\n") == 0){
            sair = true;
            break;
          }

          FILE* conta_READ = fopen(CONTAS_PATH, "r");
          for(
              linhaParaCreditar = 0;
              !numeroValido && fgets(buffer, BUFFER_SIZE, conta_READ) != NULL;
              linhaParaCreditar++
             ){
            numeroValido = atoi(buffer) == numeroConta;
          }
          linhaParaCreditar--;
          if(!numeroValido){
            linhaParaCreditar = -1;
            printf("Numero invalido. Digite novamente.\n");
          }else{
            char* numero = strtok(buffer, ",");
            char* saldo = strtok(NULL, ",'");
            char* titular = strtok(NULL, "'");

            contaCredito.numero = atoi(numero);
            contaCredito.saldo = atof(saldo);
            strncpy(contaCredito.titular, titular, TITULAR_SIZE);
          }
          fclose(conta_READ);
        }while(!numeroValido);

        if(sair) break;

        contaCredito.saldo += credito;
        
        FILE* conta_READ = fopen(CONTAS_PATH, "r");
        FILE* conta_WRITE_TEMP = fopen(TEMP_PATH, "w");
        if(conta_READ == NULL || conta_WRITE_TEMP == NULL){
          printf("ERRO NA ABERTURA DOS ARQUIVOS.\n");
          exit(1);
        }
        
        for(int linha = 0; fgets(buffer, BUFFER_SIZE, conta_READ) != NULL; linha++){
          if(linha == linhaParaCreditar){
            fprintf(conta_WRITE_TEMP, CONTA_FORMAT, contaCredito.numero, contaCredito.saldo, contaCredito.titular);
          }else{
            fputs(buffer, conta_WRITE_TEMP);
          }
        }

        fclose(conta_WRITE_TEMP);
        fclose(conta_READ);
        
        remove(CONTAS_PATH);
        rename(TEMP_PATH, CONTAS_PATH);
        printf("Conta creditada com sucesso.\n");
        break;
      }
      case DEBITO:{

        printf("Digite o valor que voce deseja debitar: ");
        double debito = atof(fgets(buffer, BUFFER_SIZE, stdin));
        if(debito < 0){
          printf("Debito menor que zero. Voltando ao menu.\n");
          break;
        }
        bool numeroValido = false;
        bool sair = false;
        int linhaParaDebitar = 0;
        struct Conta contaDebito;

        do{
          printf("Digite o numero da conta ou sair: ");
          int numeroConta = atoi(fgets(buffer, BUFFER_SIZE, stdin));
          if(strcmp(buffer, "sair\n") == 0){
            sair = true;
            break;
          }

          FILE* conta_READ = fopen(CONTAS_PATH, "r");
          for(
              linhaParaDebitar = 0;
              !numeroValido && fgets(buffer, BUFFER_SIZE, conta_READ) != NULL;
              linhaParaDebitar++
             ){
            numeroValido = atoi(buffer) == numeroConta;
          }
          linhaParaDebitar--;
          if(!numeroValido){
            linhaParaDebitar = -1;
            printf("Numero invalido. Digite novamente.\n");
          }else{
            char* numero = strtok(buffer, ",");
            char* saldo = strtok(NULL, ",'");
            char* titular = strtok(NULL, "'");

            contaDebito.numero = atoi(numero);
            contaDebito.saldo = atof(saldo);
            strncpy(contaDebito.titular, titular, TITULAR_SIZE);
          }
          fclose(conta_READ);
        }while(!numeroValido);

        if(sair) break;
        
        if(contaDebito.saldo < debito){
          printf("Saldo insuficiente. Voltando ao menu.");
          break;
        }

        contaDebito.saldo -= debito;
        
        FILE* conta_READ = fopen(CONTAS_PATH, "r");
        FILE* conta_WRITE_TEMP = fopen(TEMP_PATH, "w");
        if(conta_READ == NULL || conta_WRITE_TEMP == NULL){
          printf("ERRO NA ABERTURA DOS ARQUIVOS.\n");
          exit(1);
        }
        
        for(int linha = 0; fgets(buffer, BUFFER_SIZE, conta_READ) != NULL; linha++){
          if(linha == linhaParaDebitar){
            fprintf(conta_WRITE_TEMP, CONTA_FORMAT, contaDebito.numero, contaDebito.saldo, contaDebito.titular);
          }else{
            fputs(buffer, conta_WRITE_TEMP);
          }
        }

        fclose(conta_WRITE_TEMP);
        fclose(conta_READ);
        
        remove(CONTAS_PATH);
        rename(TEMP_PATH, CONTAS_PATH);
        printf("Conta debitada com sucesso.\n");
        break;
      }
      case TRANSFERIR:{

        printf("Digite o valor que voce deseja transferir: ");
        double transferencia = atof(fgets(buffer, BUFFER_SIZE, stdin));
        if(transferencia < 0){
          printf("Credito menor que zero. Voltando ao menu.\n");
          break;
        }
        bool numeroValidoSaida = false;
        bool numeroValidoEntrada = false;
        bool sair = false;
        int linhaDeSaida = -1;
        int linhaDeEntrada = -1;
        struct Conta contaSaida;
        struct Conta contaEntrada;

        do{
          printf("Digite o numero de que conta para que conta voce ira transferir ou sair: ");
          fgets(buffer, BUFFER_SIZE, stdin);
          char* contaSaidaTOKEN = strtok(buffer, " ");
          char* contaEntradaTOKEN = strtok(NULL, " ");

          if(contaEntradaTOKEN == NULL || contaSaidaTOKEN == NULL){
            printf("Contas insuficientes. Voltando ao menu.\n");
            sair = true;
            break;
          }

          int numeroContaSaida = atoi(contaSaidaTOKEN);
          int numeroContaEntrada = atoi(contaEntradaTOKEN);

          if(strcmp(buffer, "sair\n") == 0){
            sair = true;
            break;
          }

          char contaSaidaLinha[BUFFER_SIZE];
          char contaEntradaLinha[BUFFER_SIZE];

          FILE* conta_READ = fopen(CONTAS_PATH, "r");
          for(
              int linha = 0;
              (!numeroValidoSaida || !numeroValidoEntrada) && fgets(buffer, BUFFER_SIZE, conta_READ) != NULL;
              linha++
             ){
            numeroValidoSaida = atoi(buffer) == numeroContaSaida;
            numeroValidoEntrada = atoi(buffer) == numeroContaEntrada;
            if(numeroValidoSaida){
              linhaDeSaida = linha;
              strcpy(contaSaidaLinha, buffer);
            }
            if(numeroValidoEntrada){
              linhaDeEntrada = linha;
              strcpy(contaEntradaLinha, buffer);
            }

          }
          if(linhaDeEntrada == -1 || linhaDeSaida == -1){
            printf("Numero invalido. Digite novamente.\n");
          }else{
            char* numeroSaida = strtok(contaSaidaLinha, ",");
            char* saldoSaida = strtok(NULL, ",'");
            char* titularSaida = strtok(NULL, "'");

            contaSaida.numero = atoi(numeroSaida);
            contaSaida.saldo = atof(saldoSaida);
            strncpy(contaSaida.titular, titularSaida, TITULAR_SIZE);

            char* numeroEntrada = strtok(contaEntradaLinha, ",");
            char* saldoEntrada = strtok(NULL, ",'");
            char* titularEntrada = strtok(NULL, "'");

            contaEntrada.numero = atoi(numeroEntrada);
            contaEntrada.saldo = atof(saldoEntrada);
            strncpy(contaEntrada.titular, titularEntrada, TITULAR_SIZE);
          }
          fclose(conta_READ);
        }while(linhaDeEntrada == -1 || linhaDeSaida == -1);

        if(sair) break;

        if(contaSaida.saldo < transferencia){
          printf("Saldo insuficiente. Voltando ao menu.\n");
          break;
        }

        contaSaida.saldo -= transferencia;
        contaEntrada.saldo += transferencia;
        
        FILE* conta_READ = fopen(CONTAS_PATH, "r");
        FILE* conta_WRITE_TEMP = fopen(TEMP_PATH, "w");
        if(conta_READ == NULL || conta_WRITE_TEMP == NULL){
          printf("ERRO NA ABERTURA DOS ARQUIVOS.\n");
          exit(1);
        }
        
        for(int linha = 0; fgets(buffer, BUFFER_SIZE, conta_READ) != NULL; linha++){
          if(linha == linhaDeSaida){
            fprintf(conta_WRITE_TEMP, CONTA_FORMAT, contaSaida.numero, contaSaida.saldo, contaSaida.titular);
          }else if(linha == linhaDeEntrada){
            fprintf(conta_WRITE_TEMP, CONTA_FORMAT, contaEntrada.numero, contaEntrada.saldo, contaEntrada.titular);
          }else{
            fputs(buffer, conta_WRITE_TEMP);
          }
        }

        fclose(conta_WRITE_TEMP);
        fclose(conta_READ);
        
        remove(CONTAS_PATH);
        rename(TEMP_PATH, CONTAS_PATH);
        printf("Transferencia realizada com sucesso.\n");
        break;
      }
      case CONSULTAR_SALDO:{
        bool numeroValido = false;
        struct Conta consultaSaldo;
        do{
          printf("Digite o numero da conta: ");
          int numConta = atoi(fgets(buffer, BUFFER_SIZE, stdin));

          FILE* conta_READ = fopen(CONTAS_PATH, "r");

          for(
              int linha = 0;
              !numeroValido && fgets(buffer, BUFFER_SIZE, conta_READ) != NULL;
              linha++
             ){
            numeroValido = atoi(buffer) == numConta;
          }
          if(!numeroValido){
            printf("Numero invalido. Digite novamente.\n");
          }else{
            char* numero = strtok(buffer, ",");
            char* saldo = strtok(NULL, ",'");
            char* titular = strtok(NULL, "'");

            consultaSaldo.numero = atoi(numero);
            consultaSaldo.saldo = atof(saldo);
            strncpy(consultaSaldo.titular, titular, TITULAR_SIZE);
          }
          fclose(conta_READ);
        }while(!numeroValido);
        printf("NUMERO DA CONTA: %06d\nSALDO DA CONTA: R$%.2lf\nTITULAR: %s\n", consultaSaldo.numero, consultaSaldo.saldo, consultaSaldo.titular);
        break;
      }
      case SAIR:{ 
        printf("Saindo.\n");
        break;
      }
    }  
  }while(opc != SAIR);
}
