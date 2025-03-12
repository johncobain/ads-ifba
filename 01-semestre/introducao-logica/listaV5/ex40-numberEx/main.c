#include <stdio.h>

int main(){
    int num, uni, dez; scanf("%d", &num);
    if(num==100){printf("Cem");}
    else if(num<100){
        dez = num/10; uni = num%10;
        if(dez == 1){
            switch (uni){
            case 0:printf("Dez");break;
            case 1:printf("Onze");break;
            case 2:printf("Doze");break;
            case 3:printf("Treze");break;
            case 4:printf("Quatorze");break;
            case 5:printf("Quinze");break;
            case 6:printf("Dezesseis");break;
            case 7:printf("Dezessete");break;
            case 8:printf("Dezoito");break;
            case 9:printf("Dezenove");break;
            }
        }else{
            switch (dez){
            case 2:printf("Vinte");break;
            case 3:printf("Trinta");break;
            case 4:printf("Quarenta");break;
            case 5:printf("Cinquenta");break;
            case 6:printf("Sessenta");break;
            case 7:printf("Setenta");break;
            case 8:printf("Oitenta");break;
            case 9:printf("Noventa");break;
            }if(dez>=2&&uni>=1){printf(" e ");}
            switch(uni){
                case 1: printf("Um"); break;
                case 2: printf("Dois"); break;
                case 3: printf("Tres"); break;
                case 4: printf("Quatro"); break;
                case 5: printf("Cinco"); break;
                case 6: printf("Seis"); break;
                case 7: printf("Sete"); break;
                case 8: printf("Oito"); break;
                case 9: printf("Nove"); break;
            }
    }}else{printf("Numero invalido");}

    return 0;
}