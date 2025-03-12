#include <stdio.h>

int main(){
    char letter;
    scanf("%c", &letter);
    if(letter>='a'&&letter<='z'){
        if(letter=='a'||letter=='e'||letter=='i'||letter=='o'||letter=='u')         {
            printf("%c eh uma vogal",letter);
        }else{printf("%c eh uma consoante",letter);}   
    }else if(letter>='0' && letter <='9'){
        printf("%c eh um numero", letter);
    }else{printf("%c eh um simbolo",letter);}
    return 0;
}