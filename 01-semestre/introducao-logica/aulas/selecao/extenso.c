#include <stdio.h>

int main(){
    int num;
    printf("Entre o numero :\\> ");
    scanf("%d",&num);

    switch(num){
        case 0:printf("ZERO\n");break;
        case 1:printf("UM\n");break;
        case 2:printf("DOIS\n");break;
        case 3:printf("TRES\n");break;
        case 4:printf("QUATRO\n");break;
        case 5:printf("CINCO\n");break;
        case 6:printf("SEIS\n");break;  
        case 7:printf("SETE\n");break;
        case 8:printf("OITO\n");break;
        case 9:printf("NOVE\n");break;
        default:printf("FORA DA FAIXA\n");
    }
}