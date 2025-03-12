/*Escreva um programa que leia uma string representando um número hexadecimal (base
16) e imprima sua representação em decimal (base 10).*/
#include <stdio.h>
#define MAX_STR 256
#define UPPER (-'a'+'A')

int main(){
    char hexa[MAX_STR];
    int i, base=1, num, dec=0;
    printf("Digite o valor em Hexadecimal:\\> ");
    fgets(hexa, MAX_STR, stdin);
    for (i = 0; hexa[i]!='\0'; i++){
        if(hexa[i]>='a'&&hexa[i]<='z')hexa[i] = hexa[i]+ UPPER;
        if(hexa[i]=='\n')hexa[i]='\0';
    }
    i-=2;
    for(; i>=0;i--){
        switch (hexa[i]){
        case '1':num=1;break;
        case '2':num=2;break;
        case '3':num=3;break;
        case '4':num=4;break;
        case '5':num=5;break;
        case '6':num=6;break;
        case '7':num=7;break;
        case '8':num=8;break;
        case '9':num=9;break;
        case 'A':num=10;break;
        case 'B':num=11;break;
        case 'C':num=12;break;
        case 'D':num=13;break;
        case 'E':num=14;break;
        case 'F':num=15;break;
        default:num=0;break;
        }
        dec += (num*base);
        base*=16;
    }
 
    printf("{%s} em decimal eh = %d",hexa, dec);

    return 0;
}