#include <stdio.h>
#include <stdlib.h>

int potencia(int x, int z){
  int r = 1;
  for(int i = 0; i < z; i++){
    r *= x;
  }
  return r;
}

int main(){
  int x,z;
  printf("Digite a base e o expoente para realizar a potencia: ");
  scanf("%d %d", &x, &z);
  printf("RESULTADO DA POTENCIA: %d\n", potencia(x,z));
  return 0;
}
