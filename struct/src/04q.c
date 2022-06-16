#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QTD 15

struct data{
  int dia,mes,ano;
};

struct boleto{
  struct data vencimento;
  struct data pagamento;
  double valor, juros;
  int codCliente, codDocumento;
};

void converteData(char* src, struct data* dest){
  char* dia = strtok(src, "/");
  char* mes = strtok(NULL, "/");
  char* ano = strtok(NULL, "/");

  dest->dia = atoi(dia);
  dest->mes = atoi(mes);
  dest->ano = atoi(ano);
}

double calculaJuros(struct boleto boleto){
  struct data pagamento = boleto.pagamento;
  struct data vencimento = boleto.vencimento;
  int diasPagamento = pagamento.ano*365 + pagamento.mes*30 + pagamento.dia;
  int diasVencimento = vencimento.ano*365 + vencimento.mes*30 + vencimento.dia;

  return diasPagamento > diasVencimento ? (diasPagamento - diasVencimento)*0.0002 : 0;
}

int main(){
  struct boleto boletos[QTD];  
  char buffer[100];
  double arrecadado = 0;
  for(int i = 0; i < QTD; i++){
    printf("Digite o valor do boleto: ");
    boletos[i].valor = atof(fgets(buffer, 100, stdin));

    printf("Digite o codigo do cliente: ");
    boletos[i].codCliente = atof(fgets(buffer, 100, stdin));

    printf("Digite o codigo do documento: ");
    boletos[i].codDocumento = atof(fgets(buffer, 100, stdin));

    printf("Digite a data do pagamento no formato DD/MM/AAAA: ");
    fgets(buffer, 100, stdin);
    converteData(buffer, &boletos[i].pagamento);

    printf("Digite a data do vencimento no formato DD/MM/AAAA: ");
    fgets(buffer, 100, stdin);
    converteData(buffer, &boletos[i].vencimento);

    boletos[i].juros = calculaJuros(boletos[i]);
    arrecadado += boletos[i].valor * boletos[i].juros;
  }
  printf("TOTAL ARRECADA EM JUROS: R$%.2lf\n", arrecadado);
  return 0;
}
