/*Escreva um programa em C, que dada uma string (normalizada), imprima a maior palavra
dela.*/
#include <stdio.h>
#define MAX_STR 256

int main(){
    char str[MAX_STR], strN[MAX_STR];
    int posIniMax=0, posFimMax=0, tamMax=0;
    int posIniTemp=0, posFimTemp=0, tamTemp=0;
    int i, j;
    printf("Insira um texto:\\> ");
    fgets(str, MAX_STR, stdin);
    j=0;
    for(i=0; str[i]!='\0'; i++){
        if((str[i]!=' ' || str[i+1]!=' ')&&str[i]!='\n'){
            strN[j]= str[i];
            j++;
        }
    }
    strN[j]= '\0';

    for(i=0; strN[i]!='\0'; i++){
        if((strN[i]>='a'||strN[i]<='z')||(strN[i]>='A'&&strN[i]<='Z')){
            posIniTemp=i;
            posFimTemp=i;
            tamTemp=1;
            for(j=i; strN[j]!=' '&&strN[j]!='\0';j++){
                posFimTemp=j;
                tamTemp++;
            }
            if(tamTemp>tamMax){
                posIniMax=posIniTemp;
                posFimMax=posFimTemp;
                tamMax=tamTemp;
            }
        }
    }
    printf("Maior palavra: ");
    for(i=posIniMax; i<=posFimMax; i++){
        printf("%c", strN[i]);
    }

    return 0;
}