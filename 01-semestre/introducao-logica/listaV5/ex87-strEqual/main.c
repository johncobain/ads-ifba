/*. Escreva um programa em C, que verifique se duas strings são iguais, independente da
caixa das letras. Por exemplo, este programa deve dizer que “Teste”é igual a “TeStE”.*/
#include <stdio.h>
#define MAX_STR 256
#define UPPER (-'a'+'A')

int main(){
    char str1[MAX_STR], str2[MAX_STR];
    int i, equal=1;

    printf("Digite a primeira string:\\> ");
    fgets(str1, MAX_STR, stdin);
    printf("Digite a segunda string:\\> ");
    fgets(str2, MAX_STR, stdin);
    for(i=0;(str1[i]!='\0'||str2[i]!='\0')&&equal!=0;i++){
        if(str1[i]>='a'&&str1[i]<='z'){
            if(str2[i]>='a'&&str2[i]<='z'){
                equal = str1[i]==str2[i];
            }else if(str2[i]>='A'&&str2[i]<='Z'){
                equal = str1[i]+UPPER==str2[i];
            }else equal = str1[i]==str2[i];

        }else if(str1[i]>='A'&&str1[i]<='Z'){
            if(str2[i]>='A'&&str2[i]<='Z'){
                equal = str1[i]==str2[i];
            }else if(str2[i]>='a'&&str2[i]<='a'){
                equal = str1[i]==str2[i]+UPPER;
            }else equal = str1[i]==str2[i];
            
        }else equal = str1[i]==str2[i];
    }
    if(equal){
        printf("\"%s\" eh igual a \"%s\"",str1, str2);
    }else{
        printf("\"%s\" NAO eh igual a \"%s\"",str1, str2);
    }

    return 0;
}