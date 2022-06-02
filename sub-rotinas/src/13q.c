#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void troca(void* a, void* b, size_t n){
  void* c = malloc(n);
  memcpy(c, a, n);
  memcpy(a, b, n);
  memcpy(b, c, n);
  free(c);
}

int main(){
  double a,b;
  printf("Digite dois numeros para trocar as variaveis: ");
  scanf("%lf %lf",&a, &b);
  printf("ANTES DA TROCA:\nA:%lf\tB:%lf\n",a,b);
  troca(&a, &b, sizeof(double));
  printf("DEPOIS DA TROCA:\nA:%lf\tB:%lf\n",a,b);
  return 0;
}
