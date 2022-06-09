#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ePrimo(int n){
  for(int i = 2; i <= sqrt(n);i++){
    if(n % i == 0){
      return 0;
    }
  }
  return 1;
}

int main(){
  int n, menorPrimo;
  printf("Digite um numero para procurar o menor primo mais proximo: ");
  scanf("%d", &n);
  for(menorPrimo = n - 1; menorPrimo > 0 && !ePrimo(menorPrimo); menorPrimo--);
  if(menorPrimo == 0){
    printf("NAO EXISTE\n");
  }else{
    printf("MENOR PRIMO: %d", menorPrimo);
  }
  return 0;
}
