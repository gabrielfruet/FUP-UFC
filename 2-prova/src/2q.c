#include <stdio.h>
#include <stdlib.h>

int calcula_meses(double contribuicao, double esperado,  double juros){


  double atual = contribuicao;
  int meses = 1;

  for(meses = 1; esperado >= atual; meses++){
    atual *= (1 + juros);
    atual += contribuicao;
  }

  return meses;
}

int main(){

  double salario = 0;
  double contribuicao = 0;
  scanf("%lf", &salario);
  scanf("%lf", &contribuicao);

  double valor_final = salario/0.004;

  int meses = calcula_meses(contribuicao, valor_final, 0.004);

  printf("%d\n", meses);
  
  return 0;
}
