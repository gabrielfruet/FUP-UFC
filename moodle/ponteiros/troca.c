#include <stdio.h>

// Implemente a função 'troca'.
void troca(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(){

   int x = 0, y = 0;

   scanf("%d %d", &x, &y);

   // Chame a função 'troca' para trocar os valores de x e y.

   printf("%d %d", x, y);
}
