#include <stdio.h>

int main(){
    int ze = 0,gal = 0,gil = 0;
    int opcao = 1;
    while(opcao){
        printf("ESCOLHA UMA DAS OPCOES PARA VOTAR!\n");
        printf("0 - NULO/SAIR\n");
        printf("1 - ZE\n");
        printf("2 - GAL\n");
        printf("3 - GIL\n");
        scanf("%d", &opcao);
        switch(opcao) {
            case 0 :
                break;
            case 1 :
                ze++;
                break;
            case 2 :
                gal++;
                break;
            case 3 :
                gil++;
                break;
            default:
                printf("Opcao invalida!");
        }
    }
    printf("VENCEDOR: ");
    if(ze*2 > gal + gil)
        printf("ZE!, %d VOTOS", ze);
    else if(gal*2 > ze + gil)
        printf("GAL!, %d VOTOS", gal);
    else if(gil*2 > ze + gal)
        printf("GIL!, %d VOTOS", gil);
    else
        printf("EMPATE!");
    printf("\n");
    return 0;
}