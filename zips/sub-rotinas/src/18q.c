#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void par_impar(int n, int a[n], int b[n]){
  int a_p = 0, b_p = 0;
  while(a_p < n && b_p < n){
    while(a[a_p] % 2 == 0){
      a_p++;
    }
    while(b[b_p] % 2 == 1){
      b_p++;
    }
    if(a_p < n && b_p < n) 
      swap(a + a_p, b + b_p);
  } 
}

void imprimeVetor(const int s, int v[s]){
  printf("[");
  for(int i = 0; i < s; i++){
    printf("%d, ", v[i]);
  }
  printf("]\n");
}

int main(){
  srand(time(NULL));
  int n;
  printf("Digite o tamanho dos vetores(par): ");
  scanf("%d",&n);
  int A[n], B[n];
  for(int i = 0; i < n/2; i++){
    printf("Digite dois pares!");
    scanf("%d %d", &A[i], &B[i]);
  }
  for(int i = n/2; i < n; i++){
    printf("Digite dois impares!");
    scanf("%d %d", &A[i], &B[i]);
  }
  puts("ANTES: ");
  printf("A: \n");
  imprimeVetor(n, A);
  printf("B: \n");
  imprimeVetor(n, B);
  par_impar(n, A, B);
  puts("DEPOIS: ");
  printf("A: \n");
  imprimeVetor(n, A);
  printf("B: \n");
  imprimeVetor(n, B);
  return 0;
}
