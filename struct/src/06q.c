#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_TOMBO 20

struct data{
  int dia,mes,ano;
};

struct obra{
  struct data compra;
  int numTombo;
  int numExempl;
};

struct tombo{
  char nomeObra[100];
  char nomeAutor[100];
  char nomeEditora[100];
  struct obra *obras[3];
  int obrasRegistradas;
  int numTombo;
  int ano;
};

/*
 * RECEBE UMA STRING NO FORMATO "DD/MM/AAAA" E ESCREVE OS DADOS
 * PARA UMA STRUCT DATA
 */
void converteData(char* src, struct data* dest){
  char* dia = strtok(src, "/");
  char* mes = strtok(NULL, "/");
  char* ano = strtok(NULL, "/");

  dest->dia = atoi(dia);
  dest->mes = atoi(mes);
  dest->ano = atoi(ano);
}

/*
 * IMPRIME OS TOMBOS QUE TEM MENOS DE 3 OBRAS CADASTRADAS
 */
void mostraNumeroDosTombosDisponiveis(struct tombo* tombos, int qntdTombos){
  printf("NUMERO DOS TOMBOS DISPONIVEIS: ");
  for(int i = 0; i < qntdTombos; i++){
    if(tombos[i].obrasRegistradas < 3){
      printf("%d\t", tombos[i].numTombo);
    }
  }
  printf("\n");
}

/*
 * PROCURA TOMBO POR NUMERO, CASO NAO ENCONTRE RETORNA "NULL"
 */
struct tombo* procuraTomboPorNum(struct tombo* tombos, int qntdTombos, int numTombo){
  for(int i = 0; i < qntdTombos; i++){
    if(tombos[i].numTombo == numTombo){
      return &tombos[i];
    }
  }
  return NULL;
}

bool verificaSeExisteNumeroDoTombo(struct tombo* tombos, int qntdTombos, int numTombo){
  return procuraTomboPorNum(tombos, qntdTombos, numTombo) != NULL;
}

/*
 * ASSOCIA OBRA A TOMBO POR MEIO DE UM VETOR DE PONTEIROS PARA OBRA.
 */
struct tombo* associaObraATombo(struct tombo* tombos, int qntdTombos, int numTombo, struct obra* obra){
  int obrasRegistradas = 0;
  struct tombo* associar = procuraTomboPorNum(tombos, qntdTombos, numTombo);
  if(associar){
      obrasRegistradas = associar->obrasRegistradas;
      if(obrasRegistradas < 3){
        associar->obras[obrasRegistradas] = obra;
        associar->obrasRegistradas++;
        return associar;
      } 
  }
  return NULL;
}

void imprimeData(const struct data* data){
  printf("%02d/%02d/%d\n", data->dia, data->mes, data->ano);
}


void imprimeObra(const struct obra* obra){
  printf("DATA DE COMPRA: ");
  imprimeData(&(obra->compra));
  printf("NUMERO DO EXEMPLAR: %d\n",obra->numExempl);
  printf("NUMERO DO TOMBO: %d\n", obra->numTombo);
}

void imprimeObrasDeTombo(const struct tombo* tombo){
  for(int i = 0; i < tombo->obrasRegistradas; i++){
    imprimeObra(tombo->obras[i]); 
  }
}

int main(){
  char buffer[150];
  struct tombo tombos[MAX_TOMBO];
  int qntdTombos = 0, qntdObras = 0;
  bool existeTombo = false;
  bool obraAssociada = false;
  bool continuar = false;
  //CADASTRANDO TOMBOS
  for(qntdTombos = 0; qntdTombos < MAX_TOMBO && continuar; qntdTombos++){
    printf("CADASTRANDO %do TOMBO: \n", qntdTombos + 1);
    printf("Digite o nome da obra: ");
    fgets(tombos[qntdTombos].nomeObra, 100, stdin);

    printf("Digite o nome da editora: ");
    fgets(tombos[qntdTombos].nomeEditora, 100, stdin);

    printf("Digite o nome do autor: ");
    fgets(tombos[qntdTombos].nomeAutor, 100, stdin);

    printf("Digite o ano: ");
    tombos[qntdTombos].ano = atoi(fgets(buffer, 100, stdin));

    do{
      printf("Digite o numero do tombo: ");
      tombos[qntdTombos].numTombo = atoi(fgets(buffer, 100, stdin));
      existeTombo = verificaSeExisteNumeroDoTombo(tombos, qntdTombos, tombos[qntdTombos].numTombo);
      if(existeTombo){
        printf("Numero de tombo ja cadastrado, digite novamente.\n");
      }
    }while(existeTombo);
    tombos[qntdTombos].obrasRegistradas = 0;

    printf("Deseja cadastrar mais um tombo? sim para continuar, qualquer outra coisa para parar");
    fgets(buffer,150,stdin);
    if(strcmp(buffer, "sim\n") != 0) continuar = false;
    
  }
  //CADASTRANDO OBRAS
  int max_obras = qntdTombos*3;
  struct obra obras[max_obras];
  continuar = true;
  for(qntdObras = 0; qntdObras < max_obras && continuar; qntdObras++){
    printf("CADASTRANDO %do OBRA: \n", qntdObras + 1);
    do{
      printf("Digite o numero do tombo:\n");
      mostraNumeroDosTombosDisponiveis(tombos, qntdTombos);
      obras[qntdObras].numTombo = atoi(fgets(buffer, 100, stdin));
      existeTombo = verificaSeExisteNumeroDoTombo(tombos, qntdTombos, obras[qntdObras].numTombo);

      if(!existeTombo){
        printf("Tombo nao existe, digite novamente.\n");
      }else{
        obraAssociada = associaObraATombo(tombos, qntdTombos, obras[qntdObras].numTombo, &obras[qntdObras]);
        if(!obraAssociada){
          printf("Tombo esta com a quantidade maxima de obras.");
        }
      }
    }while(!existeTombo || !obraAssociada);

    printf("Digite a data de compra da obra no formato DD/MM/AAAA: ");
    converteData(fgets(buffer,100,stdin), &(obras[qntdObras].compra)); 
    obras[qntdObras].numExempl = procuraTomboPorNum(tombos, qntdTombos, obras[qntdObras].numTombo)->obrasRegistradas;

    printf("Deseja cadastrar mais uma obra? sim para continuar, qualquer outra coisa para parar");
    fgets(buffer,150,stdin);
    if(strcmp(buffer, "sim\n") != 0) continuar = false;
  } 
  //MOSTRANDO OBRAS POR ANO  
  printf("Digite o ano que voce deseja mostrar as obras: ");
  int anoDeProcura = atoi(fgets(buffer,100,stdin));
  for(int i = 0; i < qntdTombos; i++){
    if(tombos[i].ano == anoDeProcura){
      imprimeObrasDeTombo(&tombos[i]);
    }
  }
  //MOSTRA OBRAS POR AUTOR
  printf("Digite o autor que voce deseja mostrar as obras: ");
  char autor[100];
  fgets(autor, 100, stdin);
  for(int i = 0; i < qntdTombos; i++){
    if(strcmp(autor,tombos[i].nomeAutor) == 0){
      imprimeObrasDeTombo(&tombos[i]);
    }
  }

  //MOSTRA OBRAS POR EDITORA
  printf("Digite a editora que voce deseja mostrar as obras: ");
  char editora[100];
  fgets(editora, 100, stdin);
  for(int i = 0; i < qntdTombos; i++){
    if(strcmp(autor,tombos[i].nomeEditora) == 0){
      imprimeObrasDeTombo(&tombos[i]);
    }
  }

  return 0;
}
