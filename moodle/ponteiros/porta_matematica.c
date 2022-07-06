#include <stdio.h>
#include <stdlib.h>

int isPerfetctSquare(int n){

  for(int i = 0; i*i <= n; i++){
    if(i*i == n){
      return 1; 
    }
  }
  return 0;

}

int collatz(int n){

  int t = 0;

  for(; n > 1; t++){
    n = n % 2 == 0 ? n/2 : n*3 + 1;
  }

  return t;

}

int main(){
  int s;
  scanf("%d", &s);

  int v[s];
  int maior = 0, porta = -1;


  for(int i = 0; i < s; i++){
    scanf("%d", &v[i]);
  }

  for(int i = 0, c = collatz(v[0]); i < s; i++, c = collatz(v[i])){

    if(c > maior && isPerfetctSquare(v[i])){
      maior = c;
      porta = i;
    }
    
  }
  if(porta == -1){
    printf("a porta nao existe\n");
  }else{
    printf("%d\n", v[porta]);
  }

  
  return porta;
}
