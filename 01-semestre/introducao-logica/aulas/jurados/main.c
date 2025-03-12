#include <stdio.h>

int main(){
    int juradosNotas[7], juradosDesp[5], maior, menor, soma=0;
    float media;
    int i, j=0;
    for(i=0; i<7; i++){
        printf("Insira a nota do %do jurado: ", i+1);
        scanf("%d", &juradosNotas[i]);
    }
    maior = juradosNotas[1]; menor = juradosNotas[1];
    for(i=0; i<7; i++){
        if(juradosNotas[i]>maior) maior = juradosNotas[i];
        if(juradosNotas[i]<menor) menor = juradosNotas[i];
    }
    for(i=0;i<7;i++){
        if(juradosNotas[i]==maior)maior=-1;
        else if(juradosNotas[i]==menor)menor=-1;
        else{
            juradosDesp[j] = juradosNotas[i];
            j++;
        } 
    }

    printf("\nNotas consideradas: ");
    for (i = 0; i < 5; i++){
        printf("\nNota %d: %d", i+1, juradosDesp[i]);
        soma+=juradosDesp[i];
    }

    media = soma/5.0;

    printf("\nMedia das notas nao desprezadas: %.2f", media);
    

    return 0;
}