#include <stdio.h>

int main(){
    int acima=0, abaixo=0,i;
    float media, vet[50], tot=0;
    for(i=0; i<50; i++){
        scanf("%f", &vet[i]);
        tot+= vet[i];
    }
    media = tot/50.0;
    for(i=0; i<50; i++){
        if(vet[i]<media-(media/50)){
            abaixo+=1;
        }else if (vet[i]>media+(media/50)){
            acima++;
        }        
    }
    printf("Acima de 10%%: %d\nAbaixo de 10%%: %d",acima, abaixo);
    return 0;
}