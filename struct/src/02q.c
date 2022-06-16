#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data{
  int dia,mes,ano;
};

struct OS{
  char descricao[100];
  char cliente[50];
  double valor;
  struct data data;
  int num;
};

void converteData(char* src, struct data* dest){
  char* dia = strtok(src, "/");
  char* mes = strtok(NULL, "/");
  char* ano = strtok(NULL, "/");
  dest->dia = atoi(dia);
  dest->mes = atoi(mes);
  dest->ano = atoi(ano);
}

void imprimeData(struct data src){
  printf("%02d/%02d/%d", src.dia, src.mes, src.ano);
}

int main(){
  int n;
  char buffer[100];
  struct OS* pedidoMaisCaro = NULL;
  double somaValores = 0;
  printf("Quantas ordens de servico serao digitadas? \n"); 
  n = atoi(fgets(buffer, 100, stdin));
  struct OS ordens[n]; 
  for(int i = 0; i < n; i++){
    printf("DIGITE A %da ORDEM DE SERVICO: \n", i + 1);
    printf("Digite o numero da ordem de servico: ");
    fgets(buffer, 100, stdin);
    ordens[i].num = atoi(buffer);

    printf("Digite o nome do cliente: ");
    fgets(ordens[i].cliente, 50, stdin);

    printf("Digite a descricao do servico realizado: ");
    fgets(ordens[i].descricao, 100, stdin);

    printf("Digite o valor: ");
    fgets(buffer, 100, stdin);
    ordens[i].valor = atof(buffer);

    printf("Digite o dia mes e ano no formato: DD/MM/AAAA");
    fgets(buffer, 100, stdin);
    converteData(buffer, &ordens[i].data);

    somaValores += ordens[i].valor;

    if(!pedidoMaisCaro || ordens[i].valor > pedidoMaisCaro->valor){
      pedidoMaisCaro = &ordens[i];
    }
  } 
  printf("MEDIA DOS VALORES DO SERVICO: R$%lf\n", somaValores/n);
  printf("DADOS DO PEDIDO MAIS CARO: \n");

  printf("\tNOME DO CLIENTE: %s", pedidoMaisCaro->cliente);
  printf("\tDESCRICAO DO PEDIDO: %s", pedidoMaisCaro->descricao);
  printf("\tDATA DE AQUISICAO: ");
  imprimeData(pedidoMaisCaro->data);
  printf("\n");
  return 0;
}
