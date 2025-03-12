#include <stdio.h>

int main(){
    int vet[30], vetReversed[30];
    int i,j;

    for(i=0; i<30; i++){
        scanf("%d", &vet[i]);
    }
    i=0;
    for(j=29; j>=0; j--){
        vetReversed[i] = vet[j];
        i++;
    }
    for(i=0; i<30; i++){
        printf("\n%d -- %d\n", vet[i], vetReversed[i]);
    }

    return 0;
}