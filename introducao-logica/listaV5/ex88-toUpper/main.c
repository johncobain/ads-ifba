/*. Escreva um programa em C, que coloque a string lida toda em caixa alta.*/
#include <stdio.h>
#define STR_MAX 256
#define UPPER (-'a'+'A')

int main(){
    char str[STR_MAX];
    int i;
    printf("Insira um texto:\\> ");
    fgets(str, STR_MAX, stdin);
    for(i=0; str[i]; i++){
        if(str[i]>='a'&&str[i]<='z'){
            str[i] = str[i]+UPPER;
        }
    }

    puts(str);

    return 0;
}
