#include <stdio.h>
#include <math.h>

int main(){
    int m[10];
    for(int i = 0; i < 10; i++){
        m[i] = pow(i*2 + 1, 2);
    }
    for(int i = 0; i < 10; i++){
        printf("%d, ", m[i]);
    }
    return 0;
}