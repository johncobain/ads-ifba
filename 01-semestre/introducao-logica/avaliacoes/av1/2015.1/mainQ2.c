#include <stdio.h>

int main(){
    int pass, d3, d2, d1, d0;
    printf("Insira uma senha de 4 digitos:\\> ");
    scanf("%d", &pass);
    d3 = pass/1000;
    d2 = (pass%1000)/100;
    d1 = (pass%100)/10;
    d0 = pass%10;
    if(pass>9999){
        printf("Senha invalida! | Mais que 4 digitos");
    }else if(d0==d1&&d1==d2&&d2==d3){
        printf("Senha invalida! | Algarismos identicos");
    }else if(d1==d0+1&&d2==d1+1&&d3==d2+1){
        printf("Senha invalida! | A senha e formada por uma sequencia decrescente");
    }else if(d2==d3+1&&d1==d2+1&&d0==d1+1){
        printf("Senha invalida! | A senha e formada por uma sequencia crescente");
    }else{
        printf("Senha valida");
    }
    return 0;
}