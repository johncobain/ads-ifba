#include <stdio.h>
#define TAM_ALUNO 3

#define CAD_ALUNO_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
typedef struct alu{
    int matricula;
    char sexo;
    int ativo;
} Aluno;

//protótipos das funções
int menuGeral();
int menuAluno();
int cadastrarAluno(Aluno listaAluno[], int qtdAluno);


int main(void){

    Aluno listaAluno[TAM_ALUNO];
    int opcao;
    int qtdAluno = 0;
    int sair = 0;

    while(!sair){
        opcao = menuGeral();

        switch(opcao){
            case 0:
                sair = 1;
                break;
            case 1:
                printf("Modulo Aluno\n");
                int sairAluno = 0;
                int opcaoAluno;
                while(!sairAluno){
                    int matricula;
                    int achou = 0;
                    opcaoAluno = menuAluno();

                    switch(opcaoAluno){
                    case 0:sairAluno = 1;break;
                    case 1:{
                        int retorno=cadastrarAluno(listaAluno, qtdAluno);
                        if(retorno == MATRICULA_INVALIDA){
                            printf("Matricula invalida\n");
                        }else if(retorno == CAD_ALUNO_SUCESSO){
                            printf("Cadastrado com sucesso!\n");
                            qtdAluno++;
                        }else if(retorno == LISTA_CHEIA){
                            printf("Lista de alunos Cheia\n");
                        }
                        break;
                        }
                    case 2:{
                        printf("2 - Listar Aluno\n");
                        if(qtdAluno==0){
                            printf("Lista vazia\n");
                        }else{
                            for(int i = 0; i < qtdAluno; i++){
                                if(listaAluno[i].ativo==1){
                                    printf("Matricula: %d\n", listaAluno[i].matricula);
                                }
                            }
                        }
                        break;
                    }
                    case 3:{
                        printf("3 - Atualizar Aluno\n");
                        printf("Digite a matricula: ");
                        achou = 0;
                        scanf("%d", &matricula);
                        if(matricula<0){
                            printf("Matricula invalida\n");
                        }else{
                            for(int i = 0; i < qtdAluno; i++){
                                if(matricula== listaAluno[i].matricula&&listaAluno[i].ativo==1){
                                    printf("Digite a nova matricula: ");
                                    int novaMatricula;
                                    scanf("%d", &novaMatricula);
                                    listaAluno[i].matricula = novaMatricula;
                                    achou=1;
                                    break;
                                }
                            }
                            if(achou){
                                printf("Aluno Atualizado com Sucesso!\n");
                            }else{
                                printf("Matricula inexistente\n");
                            }
                        }
                        break;
                    }
                    case 4:{
                        printf("4 - Excluir Aluno\n");
                        printf("Digite a matricula: ");
                        achou = 0;
                        scanf("%d", &matricula);
                        if(matricula<0){
                        printf("Matricula invalida\n");
                        }else{
                            for(int i = 0; i < qtdAluno; i++){
                                if(matricula== listaAluno[i].matricula){
                                    listaAluno[i].ativo = -1;
                                    achou = 1;
                                    for(int j = i; j< qtdAluno-1; j++){
                                        listaAluno[j].matricula = listaAluno[j+1].matricula;
                                        listaAluno[j].sexo = listaAluno[j+1].sexo;
                                        listaAluno[j].ativo = listaAluno[j+1].ativo;
                                    }
                                    qtdAluno--;
                                    break;
                                }
                            }
                            if(achou){
                                printf("Aluno Excluido com Sucesso!\n");
                            }else{
                                printf("Matricula inexistente\n");
                            }
                        }
                        break;
                    }
                    default: printf("Opcao invalida\n");
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

// funções
int menuGeral(){
    int opcao;
    printf("Projeto Escola\n");
    printf("-----------------------\n");
    printf("0 - Sair\n");
    printf("1 - Aluno\n");
    printf("2 - Professor\n");
    printf("3 - Disciplina\n");
    scanf("%d", &opcao);
    
    return opcao;
}

int menuAluno(){
    int opcao;
    printf("-----------------------\n");
    printf("0 - Voltar\n");
    printf("1 - Cadastrar Aluno\n");
    printf("2 - Listar Aluno\n");
    printf("3 - Atualizar Aluno\n");
    printf("4 - Excluir Aluno\n");
    scanf("%d", &opcao);

    return opcao;
}

int cadastrarAluno(Aluno listaAluno[], int qtdAluno){
    printf("1 - Cadastrar Aluno\n");

    if(qtdAluno >= TAM_ALUNO) return LISTA_CHEIA;

    printf("Digite a matricula: ");
    int matricula;
    scanf("%d", &matricula);

    if(matricula<0) return MATRICULA_INVALIDA;

    listaAluno[qtdAluno].matricula = matricula;
    listaAluno[qtdAluno].ativo = 1;
    return CAD_ALUNO_SUCESSO;
}