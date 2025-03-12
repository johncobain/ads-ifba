#include <stdio.h>

int main(){
    int num1, f2, f1,f0, num2, s2, s1, s0;
    printf("Insira 2 numeros entre 0 e 7:\\> ");
    scanf("%d %d", &num1, &num2);
    if(num1>7||num2>7){
        printf("Numero invalido");
    }else{
        f0 = num1%2; f1 = (num1/2)%2; f2 = (num1/4)%2;
        s0 = num2%2; s1 = (num2/2)%2; s2 = (num2/4)%2;
        if((f2==s2&&f1==s1&&f0!=s0)||(f2==s2&&f1!=s1&&f0==s0)||(f2!=s2&&f1==s1&&f0==s0)){
            printf("%d e %d SAO numeros potencialmente sequenciais", num1, num2);
        }else{
            printf("%d e %d NAO sao numeros potencialmente sequenciais", num1, num2);
        }
    }
    return 0;
}