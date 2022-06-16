#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define QTD 10

struct produto{
  char descricao[100];
  double valor;
  int estoque;
  int codigo;
};

int comparaPorCodigo(const void* p, const void* q){
  int l = ((struct produto*)p)->codigo;
  int r = ((struct produto*)q)->codigo;
  return l - r;
}

void imprimeProduto(const struct produto* p){
  printf("DESCRICAO: %s", p->descricao);
  printf("VALOR: R$%lf\n", p->valor);
  printf("ESTOQUE: %d\n", p->estoque);
  printf("CODIGO: %010d\n", p->codigo);
}

int main(){
  char buffer[100];
  bool codigoRepetido;
  printf("DIGITE AS INFORMACOES DOS 10 PRODUTOS: \n"); 
  struct produto produtos[QTD];
  for(int i = 0; i < QTD; i++){
    do{
      codigoRepetido = false;
      printf("Digite o codigo do produto: ");
      produtos[i].codigo = atoi(fgets(buffer, 100, stdin));

      for(int j = 0; j < i && !codigoRepetido; j++){
        if(produtos[i].codigo == produtos[j].codigo){
          codigoRepetido = true;
        }
      }

    }while(codigoRepetido);

    printf("Digite o valor: ");
    produtos[i].valor = atof(fgets(buffer, 100, stdin));

    printf("Digite o estoque: ");
    produtos[i].estoque = atoi(fgets(buffer, 100, stdin));

    printf("Digite a descricao do produto: ");
    fgets(produtos[i].descricao, 100, stdin);
  }
  qsort(produtos, QTD, sizeof(struct produto), comparaPorCodigo);
  for(int i = 0; i < QTD; i++){
    printf("PRODUTO %d DE %d: ", i + 1, QTD); 
    imprimeProduto(produtos + i);
  }
  return 0;
}
