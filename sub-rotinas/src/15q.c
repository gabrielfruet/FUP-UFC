#include <stdio.h>
#include <stdlib.h>

int eIdentidade(const int m, const int n, int M[m][n]){
  if(m != n) return 0;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(i == j && M[i][j] != 1){
        return 0;
      }else if(M[i][j] != 0){
        return 0;
      }
    }
  }
  return 1;
}

int main(){
  int m, n;
  printf("Digite a quantidade de linhas e colunas da matriz: "); 
  scanf("%d %d",&m, &n);
  int M[m][n];
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      printf("Insira em [%d, %d]", i, j);
      scanf("%d", &M[i][j]);
    }
  }
  if(eIdentidade(m, n, M)){
    printf("EH IDENTIDADE!\n");
  }else{
    printf("NAO EH IDENTIDADE!\n");
  }
  return 0;
}
