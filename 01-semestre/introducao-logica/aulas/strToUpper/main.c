#include <stdio.h>
#define MAX_STR 256
#define UPPER (-'a'+'A')

int main(){
    char text[MAX_STR];

    printf("Digita ae que o pai joga pra maiusculo:\\> ");
    fgets(text, MAX_STR, stdin);

    for (int i = 0; text[i]!='\0'; i++){
        if(text[i]>='a'&&text[i]<='z'){
            text[i] = text[i]+ UPPER;
        }
    }
    puts(text);
    return 0;
}