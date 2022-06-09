#include <stdio.h>
#include <stdlib.h>

unsigned char calculaParidade(unsigned char byte){
  int on = 0;
  for(int i = 0; i < 8; i++){
    if(byte & 1 << i){
      on++;
    }
  }
  return on % 2;
}

int main(){
  unsigned char byte;
  printf("Digite um byte (0 a 255) para calcular sua paridade: "); 
  scanf("%u",&byte);
  printf("Paridade do byte %b : %u\n", byte, calculaParidade(byte));
  return 0;
}
