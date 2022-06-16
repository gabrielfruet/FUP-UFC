#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_PROPINAS 20

struct data{
  int dia,mes,ano;
};

struct partido{
  char sigla[10];
  double totalPropina;
};

struct propina{
  char descricao[100];
  char nomePolitico[100];
  char siglaPartido[10];
  struct data pagamento; 
  double valor;

};

void converteData(char* src, struct data* dest){
  char* dia = strtok(src, "/");
  char* mes = strtok(NULL, "/");
  char* ano = strtok(NULL, "/");

  dest->dia = atoi(dia);
  dest->mes = atoi(mes);
  dest->ano = atoi(ano);
}

/*
 * ADICIONA PARTIDO AOS PARTIDOS EXISTENTES E RETORNA O PARTIDO CRIADO, CASO O PARTIDO JA EXISTA,
 * RETORNA O ENDERECO DE MEMORIA DO PARTIDO QUE CORRESPONDE A SIGLA.
 */
struct partido* adicionaPartido(char* sigla, struct partido* partido, int* qntdPartidos){
  for(int i = 0; i < *qntdPartidos; i++){
    if(strcmp(sigla, partido[i].sigla) == 0){
      return &partido[i];
    }
  }
  strcpy(partido[*qntdPartidos].sigla, sigla);
  partido->totalPropina = 0;
  (*qntdPartidos) += 1;
  return &partido[*qntdPartidos - 1];
}
/*
 * PROCURA O PARTIDO COM MAIOR PROPINA E RETORNA UM PONTEIRO PARA O PARTIDO
 */
struct partido* procuraPartidoComMaiorPropina(struct partido* partidos, int qntdPartidos){
  struct partido* partidoComMaiorPropina = &partidos[0];
  for(int i = 0; i < qntdPartidos; i++){
    if(partidos[i].totalPropina < partidoComMaiorPropina->totalPropina){
      partidoComMaiorPropina = &partidos[i]; 
    }
  }
  return partidoComMaiorPropina;
}


int main(){
  char buffer[100];

  struct propina propinas[MAX_PROPINAS]; 
  struct partido partidos[MAX_PROPINAS];
  struct partido* partidoAtual;

  int qntdPropinas = 0, qntdPartidos = 0;
  bool continuar = true;

  for(qntdPropinas = 0; qntdPropinas < MAX_PROPINAS && continuar; qntdPropinas++){
    printf("%do PROPINA: \n", qntdPropinas + 1); 
    printf("Digite a descricao da propina: ");
    fgets(propinas[qntdPropinas].descricao, 100, stdin);
    
    printf("Digite o nome do politico: ");
    fgets(propinas[qntdPropinas].nomePolitico, 100, stdin);

    printf("Digite a sigla do partido em maiusculo: ");
    fgets(propinas[qntdPropinas].siglaPartido, 10, stdin);
    partidoAtual = adicionaPartido(propinas[qntdPropinas].siglaPartido, partidos, &qntdPartidos);

    printf("Digite a data do pagamento no formato DD/MM/AAAA: ");
    converteData(fgets(buffer,100,stdin), &propinas[qntdPropinas].pagamento);

    printf("Digite o valor da propina: ");
    propinas[qntdPropinas].valor = atof(fgets(buffer, 100, stdin));
    partidoAtual->totalPropina += propinas[qntdPropinas].valor;
    puts("PASSEI");

    printf("Deseja cadastrar mais uma propina? sim para continuar, qualquer outra coisa para parar");
    fgets(buffer,100,stdin);
    if(strcmp(buffer, "sim\n") != 0) continuar = false;
  }

  struct partido* partidoComMaiorPropina = procuraPartidoComMaiorPropina(partidos, qntdPartidos);
  printf("PARTIDO COM MAIOR PROPINA: \n");
  printf("SIGLA: %s", partidoComMaiorPropina->sigla);
  printf("TOTAL DE PROPINA: R$%0.2lf\n", partidoComMaiorPropina->totalPropina);
  return 0;
}
