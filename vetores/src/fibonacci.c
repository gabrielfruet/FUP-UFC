#include <stdio.h>

int main(){
    long long int numeros[50];
    numeros[0] = 1, numeros[1] = 1;
    for(int i = 2; i < 50; i++){
        numeros[i] = numeros[i - 1] + numeros[i - 2];
    }
    puts("FIBONACCI SERIES: ");
    for(int i = 0; i < 50; i++){
        printf("%lli,",numeros[i]);
    }
    return 0;
}