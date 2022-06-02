#include <stdio.h>
#include <stdlib.h>

int fatorial(int x){
  return x > 0 ? x*fatorial(x-1) : 1;
}

int main(){
  int x;
  printf("Digite um numero para calcular seu fatorial: "); 
  scanf("%d",&x);
  printf("FATORIAL: %d\n", fatorial(x));
  return 0;
}
