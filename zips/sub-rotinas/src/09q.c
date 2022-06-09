#include <stdio.h>
#include <stdlib.h>

unsigned int inverteNumero(unsigned int num){
  unsigned int inv = 0;
  while(num > 0){
    inv = inv*10 + num%10;
    num /= 10;
  }
  return inv;
}

int main(){
  unsigned int inverter, invertido;
  printf("Digite o numero positivo que voce deseja inverter: ");
  scanf("%u",&inverter);
  invertido = inverteNumero(inverter);
  printf("INVERTIDO : %u\n", invertido);
  return 0;
}
