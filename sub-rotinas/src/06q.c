#include <stdio.h>
#include <stdlib.h>

void triangulo(int a, int b, int c){
  if(a < b + c && b < a + c && c < a + b){
    if(a == b && b == c){
      printf("EQUILATERO!\n");
    }else if(a == b || b == c || a == c){
      printf("ISOSCELES\n");
    }else{
      printf("ESCALENO!\n");
    }
  }else{
    printf("TRIANGULO NAO EXISTE\n");
  }
}

int main(){
  int a,b,c;
  printf("Digite os tres lados de um triangulo\n");
  scanf("%d %d %d",&a, &b, &c);
  triangulo(a,b,c);
  return 0;
}
