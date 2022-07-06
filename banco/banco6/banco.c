#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define CONTA_FORMAT "%d,%lf,'%s'\n"
#define CRIAR_CONTA 1
#define REMOVER_CONTA 2
#define CREDITO 3
#define DEBITO 4
#define TRANSFERIR 5
#define CONSULTAR_SALDO 6
#define LIMPAR_TELA 7
#define SAIR 0
#define CONTAS_PATH "./data/contas.dat"
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
    printf("7..........LIMPAR TELA\n");
    printf("0.................SAIR\n");
    printf("Digite sua opcao: ");
    do{
      opc = atoi(fgets(buffer, BUFFER_SIZE, stdin));
      opcaoValida = opc <= 7 && opc >= 0;
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

          FILE* conta_READ = fopen(CONTAS_PATH, "rb");
          if(conta_READ == NULL){
            printf("ERRO NA ABERTURA DO ARQUIVO.\n");
            exit(1);
          }

          numeroValido = true;
          printf("Digite o numero da conta: "); 
          contaCriada.numero = atoi(fgets(buffer, BUFFER_SIZE, stdin));
          struct Conta contaCompara;

          while(numeroValido && fread(&contaCompara, sizeof(struct Conta), 1, conta_READ) == 1){
            numeroValido = contaCompara.numero != contaCriada.numero;
          }

          if(!numeroValido){
            printf("Numero invalido. Digite novamente.\n");
          }
          
          fclose(conta_READ);
        }while(!numeroValido);

        FILE *conta_APPEND = fopen(CONTAS_PATH, "ab");
        if(conta_APPEND == NULL){
          printf("ERRO NA ABERTURA DO ARQUIVO.\n");
          exit(1);
        }

        fwrite(&contaCriada, sizeof(struct Conta), 1, conta_APPEND);

        fclose(conta_APPEND);
        break;
      }
      case REMOVER_CONTA:{
        bool numeroValido = false;
        bool sair = false;
        int posicaoParaRemover = 0;
        struct Conta contaCompara;
        do{
          numeroValido = false;
          FILE* conta_READ = fopen(CONTAS_PATH, "rb");
          printf("Digite o numero da conta que voce deseja remover ou sair: ");
          int numParaRemover = atoi(fgets(buffer, BUFFER_SIZE, stdin));
          if(strcmp(buffer, "sair\n") == 0){
            sair = true;
            break;
          }

          for(
              posicaoParaRemover = 0; 
              !numeroValido && fread(&contaCompara, sizeof(struct Conta), 1, conta_READ); 
              posicaoParaRemover++
              ){
            numeroValido = contaCompara.numero == numParaRemover;
          }
          posicaoParaRemover--;
          if(!numeroValido){
            printf("Numero invalido. Digite novamente.\n");
            posicaoParaRemover = -1;
          } 
          fclose(conta_READ); 
        }while(!numeroValido); 
        if(sair) break;

        FILE* conta_READ = fopen(CONTAS_PATH, "rb");
        FILE* conta_WRITE_TEMP = fopen(TEMP_PATH, "wb");
        if(conta_READ == NULL || conta_WRITE_TEMP == NULL){
          printf("ERRO NA ABERTURA DOS ARQUIVOS.\n");
          exit(1);
        }

        struct Conta leitora;
        
        for(int posicao = 0; fread(&leitora, sizeof(struct Conta), 1, conta_READ) == 1; posicao++){
          if(posicao != posicaoParaRemover){
            fwrite(&leitora, sizeof(struct Conta), 1, conta_WRITE_TEMP);
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
        int posicaoParaCreditar = 0;
        struct Conta contaCredito;

        do{
          printf("Digite o numero da conta ou sair: ");
          int numeroConta = atoi(fgets(buffer, BUFFER_SIZE, stdin));
          if(strcmp(buffer, "sair\n") == 0){
            sair = true;
            break;
          }

          FILE* conta_READ = fopen(CONTAS_PATH, "rb");
          for(
              posicaoParaCreditar = 0;
              !numeroValido && fread(&contaCredito, sizeof(struct Conta), 1, conta_READ) == 1;
              posicaoParaCreditar++
             ){
            numeroValido = contaCredito.numero == numeroConta;
          }
          posicaoParaCreditar--;
          if(!numeroValido){
            posicaoParaCreditar = -1;
            printf("Numero invalido. Digite novamente.\n");
          }          
          fclose(conta_READ);

        }while(!numeroValido);

        if(sair) break;

        contaCredito.saldo += credito;
        
        FILE* conta_READ = fopen(CONTAS_PATH, "rb");
        FILE* conta_WRITE_TEMP = fopen(TEMP_PATH, "wb");
        if(conta_READ == NULL || conta_WRITE_TEMP == NULL){
          printf("ERRO NA ABERTURA DOS ARQUIVOS.\n");
          exit(1);
        }

        struct Conta leitora;
        
        for(int posicao = 0; fread(&leitora, sizeof(struct Conta), 1, conta_READ) == 1; posicao++){
          struct Conta* escrita;
          if(posicao == posicaoParaCreditar){
            escrita = &contaCredito;
          }else{
            escrita = &leitora;
          }
          fwrite(escrita, sizeof(struct Conta), 1, conta_WRITE_TEMP);
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
        int posicaoDebitar = 0;
        struct Conta contaDebito;

        do{
          printf("Digite o numero da conta ou sair: ");
          int numeroConta = atoi(fgets(buffer, BUFFER_SIZE, stdin));
          if(strcmp(buffer, "sair\n") == 0){
            sair = true;
            break;
          }

          FILE* conta_READ = fopen(CONTAS_PATH, "rb");
          for(
              posicaoDebitar = 0;
              !numeroValido && fread(&contaDebito, sizeof(struct Conta), 1, conta_READ) == 1;
              posicaoDebitar++
             ){
            numeroValido = contaDebito.numero == numeroConta;
          }
          posicaoDebitar--;
          if(!numeroValido){
            posicaoDebitar = -1;
            printf("Numero invalido. Digite novamente.\n");
          }          
          fclose(conta_READ);
        }while(!numeroValido);

        if(sair) break;
        
        if(contaDebito.saldo < debito){
          printf("Saldo insuficiente. Voltando ao menu.");
          break;
        }

        contaDebito.saldo -= debito;
        
        FILE* conta_READ = fopen(CONTAS_PATH, "rb");
        FILE* conta_WRITE_TEMP = fopen(TEMP_PATH, "wb");
        if(conta_READ == NULL || conta_WRITE_TEMP == NULL){
          printf("ERRO NA ABERTURA DOS ARQUIVOS.\n");
          exit(1);
        }

        struct Conta leitora;
        
        for(int posicao = 0; fread(&leitora, sizeof(struct Conta), 1, conta_READ) == 1; posicao++){
          struct Conta* escrita;
          if(posicao == posicaoDebitar){
            escrita = &contaDebito;
          }else{
            escrita = &leitora;
          }
          fwrite(escrita, sizeof(struct Conta), 1, conta_WRITE_TEMP);
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
        int posicaoDeSaida = -1;
        int posicaoDeEntrada = -1;
        struct Conta contaSaida;
        struct Conta contaEntrada;
        struct Conta leitora;

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

          FILE* conta_READ = fopen(CONTAS_PATH, "r");
          for(
              int posicao = 0;
              (!numeroValidoSaida || !numeroValidoEntrada) && fread(&leitora, sizeof(struct Conta), 1, conta_READ) == 1;
              posicao++
             ){
            numeroValidoSaida = leitora.numero == numeroContaSaida;
            numeroValidoEntrada = leitora.numero == numeroContaEntrada;
            if(numeroValidoSaida){
              posicaoDeSaida = posicao;
              memcpy(&contaSaida, &leitora, sizeof(struct Conta));
            }
            if(numeroValidoEntrada){
              posicaoDeEntrada = posicao;
              memcpy(&contaEntrada, &leitora, sizeof(struct Conta));
            }

          }
          if(posicaoDeEntrada == -1 || posicaoDeSaida == -1){
            printf("Numero invalido. Digite novamente.\n");
          }          
          fclose(conta_READ);
        }while(posicaoDeEntrada == -1 || posicaoDeSaida == -1);

        if(sair) break;

        if(contaSaida.saldo < transferencia){
          printf("Saldo insuficiente. Voltando ao menu.\n");
          break;
        }

        contaSaida.saldo -= transferencia;
        contaEntrada.saldo += transferencia;
        
        FILE* conta_READ = fopen(CONTAS_PATH, "rb");
        FILE* conta_WRITE_TEMP = fopen(TEMP_PATH, "wb");
        if(conta_READ == NULL || conta_WRITE_TEMP == NULL){
          printf("ERRO NA ABERTURA DOS ARQUIVOS.\n");
          exit(1);
        }
        
        for(int linha = 0; fread(&leitora, sizeof(struct Conta), 1, conta_READ) == 1; linha++){
          struct Conta* escrita;
          if(linha == posicaoDeSaida){
            escrita = &contaSaida;
          }else if(linha == posicaoDeEntrada){
            escrita = &contaEntrada;
          }else{
            escrita = &leitora;
          }
          fwrite(escrita, sizeof(struct Conta), 1, conta_WRITE_TEMP);
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

          FILE* conta_READ = fopen(CONTAS_PATH, "rb");

          for(
              int posicao = 0;
              !numeroValido && fread(&consultaSaldo, sizeof(struct Conta), 1, conta_READ) == 1;
              posicao++
             ){
            numeroValido = consultaSaldo.numero == numConta;
          }
          if(!numeroValido){
            printf("Numero invalido. Digite novamente.\n");
          }          
          fclose(conta_READ);
        }while(!numeroValido);
        printf("NUMERO DA CONTA: %06d\nSALDO DA CONTA: R$%.2lf\nTITULAR: %s\n", consultaSaldo.numero, consultaSaldo.saldo, consultaSaldo.titular);
        break;
      }
      case LIMPAR_TELA:{
        system("clear");
        break;
      }
      case SAIR:{ 
        printf("Saindo.\n");
        break;
      }
    }  
  }while(opc != SAIR);
}
