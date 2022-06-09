#include <stdio.h>
#include <stdlib.h>

void separa(double n, int *i, double* f){
  *i = (int)n;
  *f = n - *i;
}

int main(){
  int i;
  double f, n;
  printf("Digite um numero para separar sua parte fracionada e parte inteira: ");
  scanf("%lf", &n);
  separa(n, &i, &f);
  printf("Parte inteira: %d\nParte fracionada: %lf\n", i, f);
  return 0;
}
