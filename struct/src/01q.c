#include <stdio.h>
#include <stdlib.h>
#define QTD 5


struct pessoa{
  double salario;
  int idade;
  int numFilhos;
  char sexo;
};

int main(){
  double maiorSalario = 0, somaSalario = 0;
  int somaFilhos = 0;
  int totalMulheres = 0, mulheresMaisQueDezMil = 0;
  struct pessoa pessoas[20];
  printf("Digite os dados de cada pessoa: \n"); 
  for(int i = 0; i < QTD; i++){
    printf("Digite seu salario, idade, numero de filhos e sexo(M ou F): ");
    scanf("%lf", &pessoas[i].salario);
    scanf("%d", &pessoas[i].idade);
    scanf("%d", &pessoas[i].numFilhos);
    scanf(" %c", &pessoas[i].sexo);

    somaSalario += pessoas[i].salario;
    somaFilhos += pessoas[i].numFilhos;

    if(pessoas[i].salario > maiorSalario){
      maiorSalario = pessoas[i].salario;
    }

    if(pessoas[i].sexo == 'F'){
      if(pessoas[i].salario > 10000){
        mulheresMaisQueDezMil++; 
      }
      totalMulheres++;
    }
  
  }
  printf("MEDIA DOS SALARIOS: R$%.2lf\n", somaSalario/QTD);
  printf("MEDIA DE FILHOS: %.2lf\n", somaFilhos/(double)QTD);
  printf("MAIOR SALARIO: %.2lf\n", maiorSalario);
  printf("PORCENTAGEM DE MULHERES QUE GANHAM MAIS QUE R$10.000,00: %.2lf%% \n", mulheresMaisQueDezMil*100/(double)totalMulheres);
  return 0;
}
