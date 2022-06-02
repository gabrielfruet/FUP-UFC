#include <stdio.h>
#define TAM 100

int main(){
    int v[TAM], j = TAM*2;
    for(int i = 0; i < TAM; i++, j--){
        v[i] = j;
    }
    for(int i = 0; i < TAM; i++){
        printf("%d, ", v[i]);
    }
    return 0;
}