/*. Escreva um programa que leia um vetor de 10 posições de inteiros e um inteiro. O
programa deve informar a primeira posição onde este inteiro ocorre no vetor ou -1 caso o
valor não ocorra no vetor (Busca Sequencial).*/
#include <stdio.h>

int main(){
    int arr[10], num;
    int res = -1;
    for(int i = 0; i<10; i++){
        printf("Pos %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Insira um numero:\\> ");
    scanf("%d", &num);
    for(int i = 0; i<10; i++){
        if(arr[i]==num && res==-1) res = i;
    }
    printf("Posicao: %d", res);

    return 0;
}
