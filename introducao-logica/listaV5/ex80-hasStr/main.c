/*Escreva um programa em C que leia duas string e informe se a primeira contém a
segunda.*/
#include <stdio.h>

int main(){
    char str1[50], str2[50];
    int isInStr = 0;
    printf("Informe a primeira string:\\> ");
    fgets(str1,50,stdin);
    printf("Informe a segunda string:\\> ");
    fgets(str2,50,stdin);
    for(int i=0; str1[i]!='\0'; i++){
        if(isInStr==0){
            isInStr = str1[i]==str2[0];
            if(str1[i]==str2[0]){
                for(int j=0; str2[j+1]!='\0';j++){
                    isInStr = str1[i+j]==str2[j];
                }
            }
        }
    }
    if(isInStr){
        printf("A primeira string contem a segunda!");
    }else{
        printf("A primeira string nao contem a segunda!");
    }
    return 0;
}