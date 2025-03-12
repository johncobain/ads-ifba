#include <stdio.h>

int main(){
    char sexo;
    int idade;
    printf("Informe os dados cadastrais do cidadao:\\> ");
    scanf("%c %d", &sexo, &idade);

    if(sexo == 'M' && idade >= 18){
        printf("ALISTAR");
    }else{
        printf("NAO ALISTAR");
    }

    return 0;
}