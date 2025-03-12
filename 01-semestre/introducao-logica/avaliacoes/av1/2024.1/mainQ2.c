#include <stdio.h>

int main(){
    int atual, a1, a2, a3, senha, s1, s2, s3, total=0;
    int dif, difV; //diferença entre os digitos, e a volta dele(0->9 ou 9->0)
    printf("Insira a configuracao atual e a senha:\\> ");
    scanf("%d %d",&atual, &senha);
    a1 = atual/100; a2 = (atual%100)/10; a3 = atual%10;
    s1 = senha/100; s2 = (senha%100)/10; s3 = senha%10;

    if(a1<s1){
        dif = s1-a1; difV = (a1+10)-s1;
    }else if(s1<a1){
        dif = a1-s1; difV = (s1+10)-a1;
    }else{dif = 0; difV = 0;}

    if(dif<=difV){
        total+=dif;
    }else{
        total+=difV;
    }

    if(a2<s2){
        dif = s2-a2; difV = (a2+10)-s2;
    }else if(s2<a2){
        dif = a2-s2; difV = (s2+10)-a2;
    }else{dif = 0; difV = 0;}

    if(dif<=difV){
        total+=dif;
    }else{
        total+=difV;
    }

    if(a3<s3){
        dif = s3-a3; difV = (a3+10)-s3;
    }else if(s3<a3){
        dif = a3-s3; difV = (s3+10)-a3;
    }else{dif = 0; difV = 0;}

    if(dif<=difV){
        total+=dif;
    }else{
        total+=difV;
    }

    printf("%d", total);
    return 0;
}