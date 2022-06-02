#include "stdio.h"
#define NAT_A 1.03
#define NAT_B 1.02

int main(){
    int A = 5000000, B = 7000000;
    int year = 0;
    while(A < B){
        printf("POPULACAO DA CIDADE A NO ANO %d: %d\n", year, A);
        printf("POPULACAO DA CIDADE B NO ANO %d: %d\n", year, B);
        year++;
        A *= NAT_A;
        B *= NAT_B;
    }
    printf("ANO QUE ALCANCARA: %d\n",year);
    return 0;
}