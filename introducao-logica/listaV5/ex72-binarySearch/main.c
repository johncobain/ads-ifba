/*. Escreva um programa que leia um vetor de 10 posições ordenados de inteiros e um
inteiro. O programa deve informar a primeira posição onde este inteiro ocorre no vetor ou
-1 caso o valor não ocorra no vetor (Busca Binária).*/
#include <stdio.h>

int main(){
    int arr[10], num;
    int start, end, mid, i, index;
    start = 0; end = 9; index = -1;
    for(i=0; i<10; i++){
        printf("Posicao %d: ",i);
        scanf("%d", &arr[i]);
    }
    printf("Insira o numero:\\> ");
    scanf("%d", &num);

    do{
        mid = (start+end)/2;
        printf("\nPosicao inicial: %d\nPosicao central: %d\nPosicao final: %d\nValor central(%d): %d\n",start, mid, end, mid, arr[mid]);
        if(arr[mid]>num){
            end = mid-1;
        }else if(arr[mid]<num){
            start = mid+1;
        }else{
            index = mid;
        }
    }while(arr[mid]!=num&&mid!=start&&mid!=end);
    printf("\nPosicao: %d", index);
    return 0;
}