#include <stdio.h>

int main(){
    int m[3][3];
    int c[3], l[3], diag[2];
    printf("Preencha a matriz:\n");
    for(int i=0; i< 3; i++){
        for(int j=0; j< 3; j++){
            printf("Preencha o elemento i:%d e j:%d",i,j);
            scanf("%d",&m[i][j]);
        }
    }


    for(int i=0; i<3; i++){
        l[i] = 0;
        for(int j = 0; j < 3; j++){
            l[i] += m[i][j];
        }
    }
    for(int j = 0; j < 3; j++){
        c[j] = 0;
        for(int i = 0; i < 3; i++){
            c[j] += m[i][j];
        }
    }
    diag[0] = 0;
    for(int i = 0; i < 4; i++){
        diag[0] += m[i][i];
    }
    diag[1] = 0;
    for(int i = 0; i < 4; i++){
        diag[1] += m[i][3 - i];
    }
    for(int i = 0; i < 3; i++){
        printf("LINHA %d SOMA: %d\n", i, l[i]);
    }
    for(int i = 0; i < 3; i++){
        printf("COLUNA %d SOMA: %d\n", i, c[i]);
    }
    printf("DIAGONAL PRINCPAL: %d\n", diag[0]);
    printf("DIAGONAL SECUNDARIA: %d\n", diag[1]);
    int equal = 1;
    for(int i = 0; i < 2 && equal == 1; i++){
        if(c[i] != c[i + 1]){
            equal = 0; 
        }
    }
    if(c[2] != l[0]){
        equal = 0;
    }
    for(int i = 0; i < 2 && equal == 1; i++){
        if(l[i] != l[i + 1]){
            equal = 0;
        }
    }
    if(l[2] != diag[0] || diag[0] != diag[1]){
        equal = 0;
    }

    if(equal){
        puts("Eh um quadrado magico!");
    }else{
        puts("Nao eh quadrado magico!");
    }

}
