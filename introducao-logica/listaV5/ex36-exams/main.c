/*36. Em uma certificação são feitos são feitos 5 exames (I, II, III, IV e V). Escreva um
programa que leia as notas destes exames e imprima a classificação do aluno, sabendo
que a média é 70.
Classificação: A – passou em todos os exames;
B – passou em I, II e IV, mas não em III ou V;
C – passou em I e II, III ou IV, mas não em V.
Reprovado – outras situações.*/
#include <stdio.h>

int main(){
    int pr1,pr2,pr3,pr4,pr5;
    int ex1,ex2,ex3,ex4,ex5;
    printf("Insira a nota das 5 provas: ");
    scanf("%d %d %d %d %d", &pr1,&pr2,&pr3,&pr4,&pr5);
    ex1 = pr1>=70?1:0;
    ex2 = pr2>=70?1:0;
    ex3 = pr3>=70?1:0;
    ex4 = pr4>=70?1:0;
    ex5 = pr5>=70?1:0;
    if(ex1&&ex2&&ex3&&ex4&&ex5){
        printf("NOTA A!");
    }else if(ex1&&ex2&&ex4&& !(ex3||ex5)){
        printf("NOTA B");
    }else if(ex1&&ex2&&(ex3||ex4)&& !ex5){
        printf("NOTA C");
    }else{
        printf("REPROVADO");
    }

    return 0;
}