#include <stdio.h>

void converte_tempo(int segundos, int *hor, int *min, int *seg){
  *hor = segundos/3600;
  segundos -= (*hor)*3600;
  *min = segundos/60;
  segundos -= (*min)*60;
  *seg = segundos;
}

int main(){
   int tempo, h, m, s;
   scanf("%d", &tempo);

   // Chame a função 'converte_tempo' para converter o valor de 'tempo' em horas
   // minutos e segundos, gravando o resultado nas variáveis 'h', 'm' e 's'.
   converte_tempo(tempo, &h, &m, &s);


   printf("%d:%d:%d\n", h, m, s);
}
