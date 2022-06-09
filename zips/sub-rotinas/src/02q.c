#include <stdio.h>
#include <stdlib.h>

double calcula(double x, double y, char op){
  switch(op){
    case 'a': return x + y;
    case 's': return x - y;
    case 'm': return x * y;
    case 'd': return x / y;
    default:  return 0;
  }
}

int main(){
  char op;
  double x,y;
  printf("Digite a operacao(a - ADICAO, s - SUBTRACAO, m - MULTIPLICACAO, d - divisao)");
  scanf("%c", &op);
  if(op != 'a' && op != 's' && op != 'm' && op != 'd'){
    printf("Operacao invalida! terminando a execucao do programa!\n");
    exit(1);
  }
  printf("Digite os dois numeros a serem operados: ");
  scanf("%lf %lf", &x, &y);
  if(op == 'd' && y == 0){
    printf("Indeterminacao!\n");
  }else{
    printf("RESULTADO: %lf\n", calcula(x, y, op));
  }
  return 0;
}
