#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

int main(){
  int n, c, m;  
  scanf("%d %d %d", &n, &c, &m);
  int album[n];
  int carimbadas[c];
  memset(album, 0, sizeof(int)*n);
  memset(carimbadas, 0, sizeof(int)*c);

  int carimbadas_faltando = 0;

  for(int i = 0; i < c; i++){
    scanf("%d", &carimbadas[i]); 
  }

  for(int i = 0; i < m; i++){
    int pos = 0;
    scanf("%d", &pos);
    album[pos - 1] = 1;
  }

  for(int i = 0; i < c; i++){
    if(album[carimbadas[i] - 1] == false){
      carimbadas_faltando++;
    }
  }

  printf("%d", carimbadas_faltando);

  return 0;
}
