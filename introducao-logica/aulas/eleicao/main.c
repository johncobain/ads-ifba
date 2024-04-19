#include <stdio.h>

int main(){
    int vt0=0, vt1=0, vt2=0, voto;
    printf("----------------------------------------------------------\n");
    printf("------------------ELEICOES-2024-ADS-----------------------\n");
    while(voto>=0){
        printf("----------------------------------------------------------\n");
        printf("|Insira o seu voto:\n|0-Jenifer & Jansey\n|1-Roberto & Rafael\n|2-Gabriel & Gabriel\n|-1-SAIR\n:\\> ");
        scanf("%d", &voto);
        if(voto==2){
            vt2++;
        }else if(voto==1){
            vt1++;
        }else if(voto==0){
            vt0++;
        }
    }
    printf("----------------------------------------------------------\n");
    printf("O ganhador da eleicao foi: ");
    if(vt0>vt1&&vt0>vt2){
        printf("Jenifer & Jansey! com %d votos!", vt0);
    }else if(vt1>vt0&& vt1>vt2){
        printf("Roberto & Rafael! com %d votos!", vt1);
    }else if(vt2>vt1&& vt2>vt0){
        printf("Gabriel & Gabriel! com %d votos!", vt2);
    }
    return 0;
}