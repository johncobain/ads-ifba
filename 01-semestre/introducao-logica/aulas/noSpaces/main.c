#include <stdio.h>
#define MAX_STR 256
int main(){
    char text[MAX_STR];
    printf("Digita ae q o pai cuida dos espacos:\\>");
    fgets(text, MAX_STR, stdin);
    for (int i = 0; text[i]!='\0';){
        if (text[i]==' '&& text[i+1]==' '){
            for(int j = i; text[j]!='\0'; j++){
                text[j] = text[j+1];
            }
        }else i++;
        
    }
    puts(text);

    return 0;
}