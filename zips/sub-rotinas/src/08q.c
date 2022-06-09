#include <stdio.h>
#include <stdlib.h>
#define TAM 1000
int contaDivisores(int n){ 
  int qntd = 0; 
  for(int i = 1; i <= n; i++) 
    if(n % i == 0) 
      qntd++; 
  return qntd; 
}

int main(){
  int v[TAM], s;
  printf("Digite numeros para calcular a quantidade de divisores e quando quiser parar digite '0'\n");
  for(s = 0; s < TAM; s++){
    printf("Insira: ");
    scanf("%d", &v[s]);
    if(v[s] == 0)
      break;
  }
  for(int i = 0; i < s; i++){
    printf("Numero de divisores de %d : %d\n", v[i], contaDivisores(v[i]));
  }
  return 0;
}
