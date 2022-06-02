#include <stdio.h>
#include <limits.h>

int main(){
    int A[6][3], min = INT_MAX, max = INT_MAX;
    printf("Preencha a matriz 6x3:\n");
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 3; j++){
            printf("Preencha a posicao i:%d e j:%d: ");
            scanf("%d", &A[i][j]);
            if(A[i][j] > max){
                max = A[i][j];
            }            
            if(A[i][j] < min){
                min = A[i][j];
            }
 
        }
    }
    printf("MAIOR: %d\nMENOR: %d\n", max, min);
    return 0;
}
