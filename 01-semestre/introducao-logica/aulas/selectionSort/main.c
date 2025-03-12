#include <stdio.h>
#define TAM_VETOR 10

int main(){
    int vetor[TAM_VETOR] = {15, 7, 9, 8, 6, 5, 99, 18, 22, 58};
    int i, j, k;
    int aux;

    for(i = 0; i<TAM_VETOR-1; i++){
        for (j = i+1; j < TAM_VETOR; j++){
            if(vetor[j]<vetor[i]){
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
            }
        }
        for(k=0; k<TAM_VETOR; k++){
            printf("%d ",vetor[k]);
        }
        printf("\n");
        
    }
    return 0;
}