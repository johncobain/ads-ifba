/*Escreva um número que leia um número em Romano e imprima o equivalente em
decimal (base 10)*/
#include <stdio.h>
#define MAX_STR 256

int main(){
    char str[MAX_STR], strN[MAX_STR];
    int i, j;
    int dec=0;
    printf("Insira um numero em Romano:\\> ");
    fgets(str, MAX_STR, stdin);
    j=0;
    for(i=0; str[i]!='\0'; i++){
        if(str[i]!=' '&&str[i]!='\n'){
            strN[j]= str[i];
            j++;
        }
        if(str[i]=='\n')str[i]='\0';
    }
    for(i=0; strN[i]!='\0'; i++){
        switch(strN[i]){
            case 'I':
                if(strN[i+1]=='V'){
                    dec+=4;
                    i++;
                }else if(strN[i+1]=='X'){
                    dec+=9;
                    i++;
                }else{
                    dec+=1;
                }
            break;
            case 'V':
                dec+=5;
            break;
            case 'X':
                if(strN[i+1]=='L'){
                    dec+=40;
                    i++;
                }else if(strN[i+1]=='C'){
                    dec+=90;
                    i++;
                }else{
                    dec+=10;
                }
            break;
            case 'L':
                dec+=50;
            break;
            case 'C':
                if(strN[i+1]=='D'){
                    dec+=400;
                    i++;
                }else if(strN[i+1]=='M'){
                    dec+=900;
                    i++;
                }else{
                    dec+=100;
                }
            break;
            case 'D':
                dec+=500;
            break;
            case 'M':
                dec+=1000;
            break;
        }
    }

    printf("%s em decimal eh %d", strN, dec);
    return 0;
}