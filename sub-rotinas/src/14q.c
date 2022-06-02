#include <stdio.h>
#include <stdlib.h>

int contido(double A[], double B[], int s_A, int s_B){
  int contido = 0;
  for(int i = 0; i < s_A; i++){
    contido = 0;
    for(int j = 0; j < s_B && !contido; j++){
      if(B[j] == A[i]){
        contido = 1;
      }
    }
    if(!contido){
      return 0;
    }
  }
  return 1;
}

int main(){
  int s_A, s_B;
  printf("Digite o tamanho dos conjuntos A e B: ");
  scanf("%d %d",&s_A, &s_B);
  double A[s_A], B[s_B];
  for(int i = 0; i < s_A; i++){
    printf("Insira em A:");
    scanf("%lf", &A[i]);
  }
  for(int i = 0; i < s_B; i++){
    printf("Insira em B:");
    scanf("%lf", &B[i]);
  }
  if(contido(A, B, s_A, s_B)){
    printf("A esta contido em B.\n");
  }else{
    printf("A nao esta contido em B.\n");
  }
  return 0;
}
