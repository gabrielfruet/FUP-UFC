#include <stdio.h>

int main(){
    int m[3][3];
    int m_id[3][3] = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
    };
    int m_in[3][3];
    printf("Preencha a matriz 3x3:\n");
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("Digite o elemento i:%d e j:%d: ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
            }
        }
    }
    return 0;
}
