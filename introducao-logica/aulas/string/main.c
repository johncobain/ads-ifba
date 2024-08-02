#include <stdio.h>
#define MAX_STR 256
int main(){
    char string[MAX_STR];
    int tamanho;
    puts("Informe a string desejada :\\>");

    fgets(string, MAX_STR, stdin);
    for(tamanho=0; string[tamanho]!='\0'; tamanho++){
        if(string[tamanho]=='A'||string[tamanho]=='a')
            string[tamanho--]='@';
        if(string[tamanho]=='E'||string[tamanho]=='e')
            string[tamanho--]='3';
        if(string[tamanho]=='I'||string[tamanho]=='i')
            string[tamanho--]='1';
        if(string[tamanho]=='O'||string[tamanho]=='o')
            string[tamanho--]='0';
    }

    puts(string);

    return 0;
}