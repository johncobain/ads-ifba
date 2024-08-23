#include <stdio.h>
#define TAM 256

int main(){
    char text[TAM], pares[TAM][2], aux;
    int i,j,k;
    fgets(text,TAM,stdin);
    for(i=0; text[i]!='\0';i++){
        if(text[i]==' '){
            for(j=i;text[j]!='\0';j++){
                text[j] = text[j+1];
            }
        }
        if(text[i]=='\n'){
            text[i]='\0'; i--;
        }
    }
    for(i=0;text[i]!='\0';i++){
        for(j=i+1;text[j]!='\0';j++){
            if(text[i]>text[j]){
                aux = text[i];
                text[i] = text[j];
                text[j] = aux;
            }
        }
    }

    for(i=0,j=0,k=0; text[k]!='\0';k++){
        if(j==0){pares[i][0]=text[k]; pares[i][1]=text[k];}
        j++;
        while (j!=0){
            if(pares[i][1]==text[k+1]|| pares[i][1]+1==text[k+1]){
                pares[i][1]=text[k+1];
                k++;
            }else{
                i++; j=0;
            }
        }
    }
    pares[i][0] = '\0';
    for(i=0; pares[i][0]!='\0';i++){
        printf("%c:%c ",pares[i][0], pares[i][1]);
    }
    return 0;
}