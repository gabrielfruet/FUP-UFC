#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define TOTAL_DE_ALUNOS 3
#define TOTAL_DE_CAMPOS 4

enum campos_e{
    MATRICULA, SEXO, CODIGO, COEF_REND
};

int main(){
    int alunos[TOTAL_DE_ALUNOS][TOTAL_DE_CAMPOS];
    int maiorCRfeminino = INT_MIN;
    printf("PREENCHA OS CAMPOS COM OS DADOS DO %d ALUNOS: \n", TOTAL_DE_ALUNOS);
    for(int aluno = 0; aluno < TOTAL_DE_ALUNOS; aluno++){
        printf("%do ALUNO: \n", aluno + 1);
        printf("\tDigite a matricula d aluno: ");
        scanf("%d", &alunos[aluno][MATRICULA]);
        printf("\tDigite o sexo do aluno(0 - FEM, 1 - MASC): ");
        scanf("%d", &alunos[aluno][SEXO]);
        printf("\tDigite o codigo do aluno: ");
        scanf("%d", &alunos[aluno][CODIGO]);
        printf("\tDigite o coeficiente de rendimento do aluno: ");
        scanf("%d", &alunos[aluno][COEF_REND]);
        if(alunos[aluno][SEXO] == 0 && alunos[aluno][COEF_REND] > maiorCRfeminino){
            maiorCRfeminino = alunos[aluno][COEF_REND];
        }
    }
    for(int aluna = 0; aluna < TOTAL_DE_ALUNOS; aluna++){
        if(maiorCRfeminino == alunos[aluna][COEF_REND] && alunos[aluna][SEXO] == 0){
            printf("MATRICULA DE ALUNA COM CR MAIS ALTO: %d\n", alunos[aluna][MATRICULA]);
        }
    }
    return 0;
}
