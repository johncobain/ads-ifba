#include <stdio.h>

int main(){
    int fX, fY, fH, fV, sX, sY, sH, sV;
    int resX, resY, resH, resV;
    printf("Insira os valores dos dois terrenos:\\> ");
    scanf("%d %d %d %d %d %d %d %d",&fX,&fY,&fH,&fV,&sX,&sY,&sH,&sV);
    if(fX<sX&&sX<fX+fH){
        resX = sX;
        if(sX+sH<fX+fH){
            resH=sH;
        }else{
            resH=fX+fH-sX;
        }
    }else if(sX<fX&&fX<sX+sH){
        resX = fX;
        if(fX+fH<sX+sH){
            resH=fH;
        }else{
            resH=sX+sH-fX;
        }
    }else{
        resX=0; resH=0;
    }

    if(fY<sY&&sY<fY+fV){
        resY = sY;
        if(sY+sV<fY+fV){
            resV=sV;
        }else{
            resV=fY+fV-sY;
        }
    }else if(sY<fY&&fY<sY+sV){
        resY = fY;
        if(fY+fV<sY+sV){
            resV=fV;
        }else{
            resV=sY+sV-fY;
        }
    }else{
        resY=0; resV=0;
    }

    if((resX==0 &&resH==0)|| (resY==0&&resV==0)){
        printf("NAO EXISTE AREA SUGERIDA!");
    }else{
        printf("AREA SUGERIDA: (%d, %d, %d, %d)",resX,resY,resH,resV);
    }
    return 0;
}