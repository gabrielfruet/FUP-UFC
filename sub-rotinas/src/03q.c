#include <stdio.h>
#include <stdlib.h>

int converteTempo(int numHoras, char tipo){
  return 
    tipo == 'h' ? numHoras : 
    tipo == 'm' ? numHoras * 60:
    tipo == 's' ? numHoras * 60 * 60 :
    0; 
}

int main(){
  int h;
  char u;
  printf("Digite uma quantidade em horas e a unidade para converter: "); 
  scanf("%d %c",&h, &u);
  printf("TEMPO CONVERTIDO PARA %c : %d\n", u, converteTempo(h, u));
  return 0;
}
