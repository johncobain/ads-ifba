#include <stdio.h>
#define MAX_STR 256
#define TOTAL_STR 10

int main(){
    char strKey[MAX_STR], strComp[TOTAL_STR][MAX_STR], aux[MAX_STR];
    int keyTam=0, pos, i, j;
    float dist[TOTAL_STR], auxDist;

    printf("Insira a palavra chave:\\> ");
    fgets(strKey, MAX_STR, stdin);
    for (i = 0; strKey[i]!='\0'; i++){
        keyTam++;
        if(strKey[i]=='\n'){
            strKey[i]='\0';
            keyTam--;
        }
    }
    keyTam--;

    for(i=0; i<TOTAL_STR; i++){
        fgets(strComp[i], MAX_STR, stdin);
        dist[i]=0;
    }

    for(pos=0; pos<TOTAL_STR; pos++){
        for(i=0; strComp[pos][i]!='\0'; i++){
            if(strComp[pos][i]=='\n'){
                strComp[pos][i]='\0';
                i--;
            }else if(i<=keyTam){
                if(strComp[pos][i]!= strKey[i]) dist[pos]++;
            }
        }
        i--;
        if(i<=keyTam) dist[pos]+=((keyTam-i)/2.0);
        else dist[pos]+=((i-keyTam)/2.0);
    }
    
    for(pos=0; pos<TOTAL_STR-1; pos++){
        for(i=pos+1; i<TOTAL_STR; i++){
            if(dist[pos]>dist[i]){
                for(j=0;strComp[pos][j]!='\0';j++) aux[j] = strComp[pos][j];
                aux[j]='\0';
                for(j=0;strComp[i][j]!='\0';j++) strComp[pos][j] = strComp[i][j];
                strComp[pos][j]='\0';
                for(j=0;aux[j]!='\0';j++) strComp[i][j] = aux[j];
                strComp[i][j]='\0';

                auxDist = dist[pos];
                dist[pos] = dist[i];
                dist[i] = auxDist;
            }
        }
    }
    printf("\nPalavra chave: %s", strKey);
    printf("\n\nPalavra - Distancia\n\n");

    for(pos=0; pos<TOTAL_STR; pos++){
        printf("%s - %.1f\n",strComp[pos],dist[pos]);
    }

    return 0;
}