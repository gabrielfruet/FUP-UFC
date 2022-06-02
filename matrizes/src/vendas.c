#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MESES 12
#define SEMANAS 4

void imprime_tabela(const int m, const int n, float tab[m][n]){
    printf("\tSEMANAS\t\t1\t\t2\t\t3\t\t4\n");
    printf("MESES\n");
    for(int i = 0; i < m; i++){
        printf("%02d\t\t\t", i + 1);
        for(int j = 0; j < n; j++){
           printf("R$%8.2f\t", tab[i][j]); 
        }
        printf("\n");
    }
    printf("\n");
    
}

int main(){
    srand(time(NULL));
    float vendas[MESES][SEMANAS], t_meses[MESES], t_semanas[SEMANAS], t_ano = 0;
    char opc;
    printf("Voce deseja digitar os numeros?(s/n) ");
    scanf(" %c", &opc);

    //setando os vetores t_meses e t_semanas para 0
    memset(t_meses, 0, sizeof(float)*MESES);
    memset(t_semanas, 0, sizeof(float)*SEMANAS);

    printf("Preencha a matriz de vendas!\n");
    for(int mes = 0; mes < MESES; mes++){
        if(opc == 's')
            printf("Digite as vendas no %do mes!\n", mes + 1);
        for(int semana = 0; semana < SEMANAS; semana++){
            if(opc == 's')
                scanf("%f", &vendas[mes][semana]);
            else
                vendas[mes][semana] = (rand() % (1 << 16)) / 23.0;
            t_semanas[semana] += vendas[mes][semana];
            t_meses[mes] += vendas[mes][semana];
            t_ano += vendas[mes][semana];
        }
    }
    imprime_tabela(MESES, SEMANAS, vendas);

    puts("TOTAL DE VENDAS EM CADA SEMANA DE TODOS OS MESES: ");
    for(int semana = 0; semana < SEMANAS; semana++){
        printf("\tSEMANA %d: R$%8.2f\n", semana + 1, t_semanas[semana]);
    }

    puts("TOTAL DE VENDAS EM CADA MES");
    for(int mes = 0; mes < MESES; mes++){
        printf("\tMES %02d:   R$%8.2f\n", mes + 1, t_meses[mes]);
    }

    printf("TOTAL DE VENDAS NO ANO: R$%8.2f\n", t_ano);
    return 0;
}
