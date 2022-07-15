#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  

typedef struct laranja{
  char nome[100];
  double valor;
}Laranja;


int main(){
  
  int qntd;
  scanf("%d", &qntd);

  Laranja funcionarios[qntd];

  for(int i = 0; i < qntd; i++){

    scanf("%s", funcionarios[i].nome);
    scanf("%lf", &funcionarios[i].valor);
    
  }
  char vencedor[100];
  double propina_vencedor = 0;
  double propina_atual = 0;

  for(int i = 0; i < qntd; i++){
    propina_atual = 0;
    for(int j = 0; j < qntd; j++){
      if(strcmp(funcionarios[i].nome, funcionarios[j].nome) == 0){
        propina_atual += funcionarios[j].valor;
      }

      if((propina_atual > propina_vencedor) || (propina_atual == propina_vencedor && strcmp(vencedor, funcionarios[i].nome) > 0)){

        strcpy(vencedor, funcionarios[i].nome);
        propina_vencedor = propina_atual;
          
      }
    }
  }

  printf("%s\n", vencedor);

  return 0;
}
