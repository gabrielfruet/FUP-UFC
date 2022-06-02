#include <stdio.h>
#define TAM 100

int main(){
    int v[TAM];
    for(int i = 0, k = 5; i < TAM; i++, k += 5){
        v[i] = k;
    }
    for(int i = 0; i < TAM; i++){
        printf("%d,", v[i]);
    }
    return 0;
}