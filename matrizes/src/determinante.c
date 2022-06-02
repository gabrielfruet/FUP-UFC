#include <stdio.h>

int main(){
    int m[3][3], det = 0, diagonal = 1;
    printf("PREENCHA A MATRIZ: ");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &m[i][j]);
        }
    }
    //calculando elem. da diagonal principal
    for(int k = 0; k < 3; k++){
        diagonal = 1;
        for(int i = 0; i < 3;i++){
            diagonal *= m[i][(k + i) % 3];
        }
        det += diagonal;
    }
    //calculando elem. da diagonal secundaria
    for(int k = 0; k < 3; k++){
        diagonal = 1;
        for(int i = 0; i < 3;i++){
            diagonal *= m[i][( 3 + (k - i)) % 3];
        }
        det -= diagonal;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d\t", m[i][j]);
        }
        puts("");
    }
    printf("DET: %d", det);
    return 0;
}
