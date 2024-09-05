#include <stdio.h>

int main(void){
    int opcao;

    int sair = 0;

    while(!sair){
        printf("Projeto Escola\n");
        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");

        scanf("%d", &opcao);

        switch(opcao){
            case 0:
                sair = 1;
                break;
            case 1:
                printf("Modulo Aluno\n");
                break;
            case 2:
                printf("Modulo Professor\n");
                break;
            case 3:
                printf("Modulo Disciplina\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    }

    return 0;
}