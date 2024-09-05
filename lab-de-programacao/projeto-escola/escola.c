#include <stdio.h>
#define TAM_ALUNO 3

int main(void){

    int listaAluno[TAM_ALUNO];
    int opcao;
    int qtdAluno = 0;
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
                int sairAluno = 0;
                int opcaoAluno;
                while(!sairAluno){
                    printf("0 - Voltar\n");
                    printf("1 - Cadastrar Aluno\n");
                    printf("2 - Listar Aluno\n");
                    printf("3 - Atualizar Aluno\n");
                    printf("4 - Excluir Aluno\n");

                    scanf("%d", &opcaoAluno);

                    switch(opcaoAluno){
                    case 0:
                        sairAluno = 1;
                        break;
                    case 1:
                        printf("1 - Cadastrar Aluno\n");
                        printf("Digite a matricula\n");
                        int matricula;
                        scanf("%d", &matricula);
                        if(matricula<0){
                            printf("Matricula invalida\n");
                        }else{
                            if(qtdAluno >= TAM_ALUNO){
                                printf("Lista de alunos Cheia");
                            }else{
                                listaAluno[qtdAluno] = matricula;
                                qtdAluno++;
                            }
                        }

                        break;
                    case 2:
                        printf("2 - Listar Aluno\n");

                        break;
                    case 3:
                        printf("3 - Atualizar Aluno\n");

                        break;
                    case 4:
                        printf("4 - Excluir Aluno\n");

                        break;
                    default:
                        printf("Opcao invalida\n");
                    }
                }
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