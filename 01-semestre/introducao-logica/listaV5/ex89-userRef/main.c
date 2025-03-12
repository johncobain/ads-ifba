/*Escreva um programa em C, que gere uma string composta pelo último nome, seguido de
virgula e as iniciais dos demais nomes (em ordem), seguida de ponto. Por exemplo, se a
string entrada for “Gabriel Garcia Marquez”, a string gerada deve ser “Marquez, G. G.”.
*/
#include <stdio.h>
#define MAX_STR 256

int main(){
    char fullName[MAX_STR], abrev[MAX_STR];
    int i, j, lastNamePos;
    printf("Digite o seu nome completo:\\> ");
    fgets(fullName, MAX_STR, stdin);

    for(i=0; fullName[i]!='\0';i++)if(fullName[i]=='\n'){fullName[i]='\0';i--;}
    for(lastNamePos=i-1; fullName[lastNamePos]!=' ';lastNamePos--)

    for(j=0, i=lastNamePos; fullName[i]!='\0';i++,j++){
        abrev[j] = fullName[i];
    }
    abrev[j] = ',';j++;

    for(i=0; i<lastNamePos; i++){
        if(i==0||(fullName[i-1]==' '&& (fullName[i]>='A'&&fullName[i]<='Z'))){
            abrev[j] = ' ';j++;
            abrev[j] = fullName[i];j++;
            abrev[j] = '.';j++;
        }
    }
    abrev[j] = '\0';

    puts(abrev);
    return 0;
}