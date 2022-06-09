#include <stdio.h>
#include <stdlib.h>

int arredonda(double x){
  int sign = (x > 0) - (x < 0);
  if(x*sign >= abs((int)x) + 0.5){
    return (int)x + sign;
  }else{
    return (int)x;
  }
}

int main(){
  double x;
  printf("Digite o numero que deseja arredondar: "); 
  scanf("%lf",&x);
  printf("Numero arredondado: %d\n", arredonda(x));
  return 0;
}
