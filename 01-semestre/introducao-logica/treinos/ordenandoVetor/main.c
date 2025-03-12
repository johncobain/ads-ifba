#include <stdio.h>

int main(){
    int vet[5], i, j, aux;
    for(i=0; i<5; i++){
        printf("Digite o %do. numero: ", i+1);
        scanf("%d", &vet[i]);
    }
    for(i=0; i<4; i++){
        for(j=i+1; j<5; j++){
            if(vet[i]>vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j]= aux;
            }
        }
    }
    for(i=0; i<5; i++){
        printf("-%d-",vet[i]);
    }
    return 0;
}