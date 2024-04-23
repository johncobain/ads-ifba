/*Escreva um programa em C, que leia uma string, gere uma nova string com o texto
invertido e imprima esta nova string*/
#include <stdio.h>

int main(){
    char str[50], strRev[50];
    int countC=0;
    fgets(str, 50, stdin);
    for(int i = 0; str[i]!= '\0'; i++)countC++;
    for(int i = 0; countC>=0; i++){
        countC--;
        if(countC>=0){
        strRev[i]=str[countC];
        }else{
            strRev[i] = '\0'; 
        }
    }

    for (int i = 0; strRev[i]!='\0'; i++){
        printf("%c", strRev[i]);
    }
    return 0;
    
}