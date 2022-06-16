#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define QTD_ESTILISTA 5
#define QTD_ESTACAO 4
#define QTD_ROUPA 10

struct estilista{
  char nome[50];
  double salario;
  int codigo;
};

struct estacao{
  char nome[50];
  int codigo;
};

struct roupa{
  char descricao[50];
  int codigo;
  int codigoEstilista;
  int codigoEstacao;
  int ano;
};

void imprimeRoupa(struct roupa roupa){
  printf("-------------------------------------------------------------------\n");
  printf("DESCRICAO: %s", roupa.descricao);
  printf("CODIGO DA ROUPA: %d\n", roupa.codigo);
  printf("CODIGO DO ESTILISTA: %d\n", roupa.codigoEstilista);
  printf("CODIGO DA ESTACAO: %d\n", roupa.codigoEstacao);
  printf("ANO DE LANCAMENTO: %d\n", roupa.ano);
  printf("-------------------------------------------------------------------\n");
}

int main(){
  char buffer[100];
  bool codigoRepetido, nomeRepetido;
  bool estilistaExiste, estacaoExiste;
  struct estilista estilistas[QTD_ESTILISTA];
  struct estacao estacoes[QTD_ESTACAO];
  struct roupa roupas[QTD_ROUPA];
  puts("CADASTRANDO ESTACOES: ");
  for(int i = 0; i < QTD_ESTACAO; i++){
    printf("ESTACAO %d:\n", i + 1);
    //ATRIBUI NOME A ESTACAO
    do{
      nomeRepetido = false;
      printf("Digite o nome da estacao: ");
      fgets(estacoes[i].nome, 50, stdin);

      for(int j= 0; j < i && !nomeRepetido; j++){
        if(strcmp(estacoes[i].nome, estacoes[j].nome) == 0){
          puts("Nome repetido. Digite novamente");
          nomeRepetido = true;
        }
      }
    }while(nomeRepetido);
    //ATRIBUI CODIGO A ESTACAO
    do{
      codigoRepetido = false;
      printf("Digite o codigo da estacao: ");
      estacoes[i].codigo = atoi(fgets(buffer, 100, stdin));

      for(int j = 0; j < i && !codigoRepetido; j++){
        if(estacoes[i].codigo == estacoes[j].codigo){
          puts("Codigo repetido. Digite novamente.");
          codigoRepetido = true;
        }
      }
    }while(codigoRepetido);
  }
  puts("CADASTRANDO ESTILISTAS: ");
  for(int i = 0; i < QTD_ESTILISTA; i++){
    printf("ESTILISTA %d:\n", i + 1);
    //ATRIBUI NOME AO ESTILISTA
    printf("Digite o nome do estilista: ");
    fgets(estilistas[i].nome, 50, stdin);

    //ATRIBUI CODIGO AO ESTILISTA 
    do{
      codigoRepetido = false;
      printf("Digite o codigo do estilista: ");
      estilistas[i].codigo = atoi(fgets(buffer, 100, stdin));

      for(int j = 0; j < i && !codigoRepetido; j++){
        if(estilistas[i].codigo == estilistas[j].codigo){
          puts("Codigo repetido. Digite novamente.");
          codigoRepetido = true;
        }
      }
    }while(codigoRepetido);
    
    //ATRIBUI SALARIO AO ESTILISTA
    printf("Digite o salario do estilista: ");
    estilistas[i].salario = atof(fgets(buffer, 100, stdin));
  }
  puts("CADASTRANDO ROUPAS: ");
  for(int i = 0; i < QTD_ROUPA; i++){
    printf("ROUPA %d:\n", i + 1);
    //ATRIBUI DESCRICAO A ROUPA
    printf("Digite a descricao da roupa");
    fgets(roupas[i].descricao, 50, stdin);

    //ATRIBUI CODIGO A ROUPA  
    do{
      codigoRepetido = false;
      printf("Digite o codigo da roupa: ");
      roupas[i].codigo = atoi(fgets(buffer, 100, stdin));

      for(int j = 0; j < i && !codigoRepetido; j++){
        if(roupas[i].codigo == roupas[j].codigo){
          puts("Codigo repetido. Digite novamente.");
          codigoRepetido = true;
        }
      }
    }while(codigoRepetido);

    //ATRIBUI ESTILISTA A ROUPA 
    do{
      estilistaExiste = false;
      printf("Digite o codigo do estilista: ");
      roupas[i].codigoEstilista = atoi(fgets(buffer, 100, stdin));

      for(int j = 0; j < QTD_ESTILISTA; j++){
        if(roupas[i].codigoEstilista == estilistas[j].codigo){
          estilistaExiste = true;
        }
      }
      if(!estilistaExiste){
          puts("Estilista inexistente. Digite novamente.");
      }

    }while(!estilistaExiste);

    //ATRIBUI ESTACAO A ROUPA 
    do{
      estacaoExiste = false;
      printf("Digite o codigo da estacao: ");
      roupas[i].codigoEstacao = atoi(fgets(buffer, 100, stdin));

      for(int j = 0; j < QTD_ESTACAO && !estacaoExiste; j++){
        if(roupas[i].codigoEstacao == estacoes[j].codigo){
          estacaoExiste = true;
        }
      }
      if(!estacaoExiste){
          puts("Estacao inexistente. Digite novamente.");
      }

    }while(!estacaoExiste);

    printf("Digite o ano da roupa: ");
    roupas[i].ano = atoi(fgets(buffer, 100, stdin));
  }
  int codigoDaEstacao = 0;
  //PEGA A ESTACAO
  do{
    estacaoExiste = false;

    printf("Digite o nome de uma estacao para imprimir todas as roupas que pertencem a ela: ");
    fgets(buffer, 100, stdin);

    for(int j = 0; j < QTD_ESTACAO; j++){
      if(strcmp(buffer, estacoes[j].nome) == 0){
        codigoDaEstacao = estacoes[j].codigo;
        estacaoExiste = true;
      }
    }
    if(!estacaoExiste){
      puts("Estacao nao existe. Digite novamente.");
    }

  }while(!estacaoExiste);
  
  //IMPRIME ROUPAS
  for(int i = 0; i < QTD_ROUPA; i++){
    if(roupas[i].codigo == codigoDaEstacao){
      imprimeRoupa(roupas[i]);
    } 
  }
  return 0;

}
