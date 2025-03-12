#include <stdio.h>

int main(){
    float n1, n2, n3, n4, avg;
    printf("Insira as 4 notas do aluno://> ");
    scanf("%f %f %f %f",&n1,&n2,&n3,&n4);
    if(n1<n2&&n1<n3&&n1<n4){
        n1=0;
    }else if(n2<n1&&n2<n3&&n2<n4){
        n2=0;
    }else if(n3<n1&&n3<n2&&n3<n4){
        n3=0;
    }else if(n4<n1&&n4<n2&&n4<n3){
        n4=0;
    }else if(n1==n2&&n2==n3&&n3==n4){ n1=0;}
    avg =(n1+n2+n3+n4)/3;
    printf("Media = %f",avg);
    return 0;
}