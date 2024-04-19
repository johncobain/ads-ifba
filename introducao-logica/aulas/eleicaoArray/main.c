#include <stdio.h>
#define QNT_PROP 50

int main(){
    int votos[QNT_PROP], voto;
    for(int i = 0; i<QNT_PROP; i++){
        votos[i]=0;
    }
    printf("----------------------------------------------------------\n");
    printf("------------------ELEICOES-2024-ADS-----------------------\n");
    do{
        printf("----------------------------------------------------------\n");
        printf("|Insira o seu voto:\\> ");
        scanf("%d", &voto);
        if(voto>=0&&voto<QNT_PROP)votos[voto]++;
    }while(voto>=0);
    printf("----------------------------------------------------------\n");
    for(int i = 0; i<QNT_PROP; i++){
        printf("Voto %d: %d\n",i, votos[0]);
    }
  
    return 0;
}