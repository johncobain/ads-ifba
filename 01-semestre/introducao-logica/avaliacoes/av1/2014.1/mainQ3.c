/*Questão III
Escreva um algoritmo em linguagem C que calcule e imprima a média obtida pelo aluno
para aprovação direta (se superior a 7.0) ou o valor mínimo que o aluno (não aprovado
por média) precisa obter numa prova final para ser aprovado. Considere que são
realizadas três provas durante o semestre e que para aprovação em final a média obtida
de acordo com a equação abaixo precisa ser igual ou superior a 5.0. (Valor 2,0)
MédiaFinal=((média aritmética das três avaliações parciais)x 2+(notada provafinal) x1)/3
*/
#include <stdio.h>

int main(){
    float av1, av2, av3, pf, media;
    printf("Insira a nota das tres avaliacoes semestrais do aluno:\\> ");
    scanf("%f %f %f",&av1,&av2,&av3);
    media = (av1+av2+av3)/3;
    if(media>=7) printf("ALUNO APROVADO");
    else{
        pf = (5-(media*2)/3)*3;
        if(pf > 10) printf("ALUNO REPROVADO");
        else{
            printf("NECESSARIO PROVA FINAL\nPONTOS PARA ALCANCAR A MEDIA(5.0): %f",pf);
        }
    }

    return 0;
}