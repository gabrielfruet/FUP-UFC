#include "stdio.h"
#include "math.h"

int main(){
    double pi;
    double divisor;
    for(int i = 0; i < 51; i++){
        divisor = 1 + (2*i);
        if(i % 2 == 0){
            pi += 1/pow(divisor,3);
        }else{
            pi -= 1/pow(divisor,3);
        }
    }
    printf("%lf", cbrt(pi*32));
    return 0;
}