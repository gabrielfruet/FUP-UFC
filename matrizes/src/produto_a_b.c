#include <stdio.h>
#include <string.h>

int main(){
    int a[3][2], b[2][5], c[3][5];
    //a x b
    for(int i=0; i<3; i++){
        for(int j=0; j<2; j++){
            printf("Digite o elemento i:%d e j:%d da matriz a: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<5; j++){
            printf("Digite o elemento i:%d e j:%d da matriz b: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    int curr = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            curr = 0;
            for(int k = 0; k < 2; k++){
                curr += a[i][k]*b[k][j];
            }
            c[i][j] = curr;
        }
    }
    puts("Matriz C: ");
    printf("[\n");
    for(int i = 0; i < 3; i++){
        printf("[");
        for(int j = 0; j < 5; j++){
            printf("%d   ", c[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
    return 0;
}
