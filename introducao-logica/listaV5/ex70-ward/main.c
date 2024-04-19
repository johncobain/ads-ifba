/*. Escreva um programa que carregue um array com tamanho variável. O tamanho máximo
do array é de 100 posições (carga de array com sentinela).*/
#include <stdio.h>

int main(){
    int arr[100], pos, num, ward = 0, opt;
    do{
        printf("\n-------------------\n");
        printf("Selecione um opcao:\n");
        printf("1-Adicionar no final da fila\n");
        printf("2-Adicionar em uma posicao do vetor(sobrescrever)\n");
        printf("3-Remover no final da fila\n");
        printf("4-Remover em uma posicao do vetor\n");
        printf("5-Mostrar vetor\n");
        printf("0-Sair do programa\n");
        printf(":\\> ");
        scanf("%d", &opt);

        switch(opt){
            case 1: 
                printf("\n-------------------\n");
                printf("1-Adicionar no final da fila\n");
                printf("Insira o valor a ser adicionado:\\> ");
                scanf("%d", &num);
                arr[ward] = num;
                printf("Valor %d adicionado na posicao %d!\n", num, ward);
                ward++;
            break;
            case 2: 
                printf("\n-------------------\n");
                printf("2-Adicionar em uma posicao do vetor(sobrescrever)\n");
                printf("Insira o valor a ser adicionado:\\> ");
                scanf("%d", &num);
                printf("Insira a posicao em que o valor sera adicionado:\\> ");
                scanf("%d", &pos);
                if(pos<ward){
                    arr[pos] = num;
                    printf("Valor %d adicionado na posicao %d!\n", num, pos);
                }else{
                    printf("Posicao invalida!\n");
                }
            break;
            case 3: 
                printf("\n-------------------\n");
                printf("3-Remover no final da fila\n");
                if(!ward){
                    printf("O vetor esta vazio!\n");
                }else{
                    printf("Valor %d removido na posicao %d!\n", arr[ward-1], ward-1);
                    ward--;
                }
            break;
            case 4: 
                printf("\n-------------------\n");
                printf("4-Remover em uma posicao do vetor\n");
                printf("Insira a posicao em que o valor sera removido:\\> ");
                scanf("%d", &pos);
                if(pos<ward){
                    printf("Valor %d removido na posicao %d!\n", arr[pos], pos);
                    for(;pos-1<ward;pos++){
                        arr[pos] = arr[pos+1];
                    }
                    ward--;
                }else{
                    printf("Posicao invalida!\n");
                }
            break;
            case 5: 
                printf("\n-------------------\n");
                printf("5-Mostrar vetor\n");
                if(!ward){
                    printf("O vetor esta vazio!\n");
                }else{
                    for(int i = 0; i<ward; i++){
                        printf("Pos. %d: %d\n", i, arr[i]);
                    }
                }
            break;
            case 0: printf("Saindo do programa...\n"); break;
            default: printf("Opcao invalida\n");
        }
    } while (opt != 0);
    return 0;
}