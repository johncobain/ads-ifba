#include <stdio.h>
#define MAX_STR 256

int main(){
    char text[MAX_STR];
    int ultimo=0, totLetras=0, repete=1, i;
    scanf("%s", text);
    for(i=0; text[i]!='\0'; i++)ultimo++;
    ultimo--;
    for(i=ultimo-1; text[i]!= text[ultimo]; i--) totLetras++;
    ultimo-=totLetras;
    for(i=i-totLetras; text[ultimo]!='\0'&&repete==1; i++, ultimo++){
        if(text[i]!= text[ultimo])repete=0;
    }
    if(repete)text[i]='\0';
    puts(text);
    return 0;
}