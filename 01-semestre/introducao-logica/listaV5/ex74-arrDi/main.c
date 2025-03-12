/*Escreva um programa em C que armazene um vetor de até 30 inteiros. O programa deve
fornecer as seguintes operações:
a. Inserir um elemento no final do vetor
b. Inserir um elemento em uma dada posição
c. Remover um elemento de uma posição indicada
d. Remover todos elementos iguais a um valor indicado
e. Gerar um novo array sem duplicidades a partir deste array*/
#include <stdio.h>
#define QND_POS 30

int main(){
    int arr[QND_POS], arrCopy[QND_POS], pos, num, ward = 0, wardC = 0, opt;
    int aux;
    do{
        printf("\n-------------------\n");
        printf("Selecione um opcao:\n");
        printf("1-Adicionar no final da fila\n");
        printf("2-Adicionar em uma posicao do vetor\n");
        printf("3-Remover em uma posicao do vetor\n");
        printf("4-Remover todos elementos iguais a um valor indicado\n");
        printf("5-Gerar um novo array sem duplicidades a partir deste array\n");
        printf("6-Mostrar vetor\n");
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
                printf("2-Adicionar em uma posicao do vetor\n");
                printf("Insira o valor a ser adicionado:\\> ");
                scanf("%d", &num);
                printf("Insira a posicao em que o valor sera adicionado:\\> ");
                scanf("%d", &pos);
                if(pos<ward){
                    for(aux = ward;aux>pos;aux--){
                        arr[aux] = arr[aux-1];
                    }
                    arr[pos] = num;
                    printf("Valor %d adicionado na posicao %d!\n", num, pos);
                    ward++;
                }else{
                    printf("Posicao invalida!\n");
                }
            break;
            case 3: 
                printf("\n-------------------\n");
                printf("3-Remover em uma posicao do vetor\n");
                printf("Insira a posicao em que o valor sera removido:\\> ");
                scanf("%d", &pos);
                if(!ward){
                    printf("O vetor esta vazio!\n");
                }else{
                    if(pos<ward){
                        printf("Valor %d removido na posicao %d!\n", arr[pos], pos);
                        for(;pos-1<ward;pos++){
                            arr[pos] = arr[pos+1];
                        }
                        ward--;
                    }else{
                        printf("Posicao invalida!\n");
                    }
                }
            break;
            case 4: 
                printf("\n-------------------\n");
                printf("4-Remover todos elementos iguais a um valor indicado\n");
                printf("Insira o valor que sera removido:\\> ");
                scanf("%d", &num);
                if(!ward){
                    printf("O vetor esta vazio!\n");
                }else{
                    for(int i = 0; i<ward; i++){
                        if(arr[i]==num){
                            printf("Valor %d removido na posicao %d!\n", arr[i], i);
                            pos = i;
                            for(;pos-1<ward;pos++){
                                arr[pos] = arr[pos+1];
                            }
                            i--;
                            ward--;
                        }
                    }
                }
            break;
            case 5:
                printf("\n-------------------\n");
                printf("5-Gerar um novo array sem duplicidades a partir deste array\n");
                if(!ward){
                    printf("O vetor esta vazio!\n");
                }else{
                    for(int i = 0; i<ward; i++){
                        arrCopy[i]= arr[i];
                        wardC++;
                    }
                    for(int i = 0; i<wardC; i++){
                        for(int j = i+1; j<wardC; j++){
                            if(arrCopy[i]==arrCopy[j]){
                                pos = j;
                                for(;pos-1<ward;pos++){
                                    arrCopy[pos] = arrCopy[pos+1];
                                }
                                j--;
                                wardC--;
                            }
                        }
                    }
                    printf("Array sem duplicantes:\n");
                    for(int i = 0; i<wardC; i++){
                        printf("Pos. %d: %d\n", i, arrCopy[i]);
                    }
                }          
            break;
            case 6: 
                printf("\n-------------------\n");
                printf("6-Mostrar vetor\n");
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