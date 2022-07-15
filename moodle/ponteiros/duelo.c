#include <stdio.h>
#include <stdlib.h>

struct Personagem{
  int vida, ataque;
};

int main(){
  char buffer[255];

  struct Personagem per[2];

  for(int i = 0; i < 2; i++){
    per[i].vida = atoi(fgets(buffer,255,stdin));
    per[i].ataque = atoi(fgets(buffer,255,stdin));
  }

  while(per[0].vida > 0 && per[1].vida > 0){
    per[1].vida -= per[0].ataque;
    per[0].vida -= per[1].ataque;
  }

  if(per[0].vida > per[1].vida){
    printf("Personagem 1\n");
  }else if(per[0].vida < per[1].vida){
    printf("Personagem 2\n");
  }else{
    printf("Empate\n");
  }
  
  return 0;
}
