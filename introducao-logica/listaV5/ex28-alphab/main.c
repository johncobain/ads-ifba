#include <stdio.h>

int main(){
    char letter;
    printf("Insira uma letra: ");
    scanf("%c", &letter);
    if(letter == 'a'||letter == 'e'||letter == 'i'||letter == 'o'||letter == 'u'){
        printf("A letra %c e uma vogal!", letter);
    }else{
        printf("A letra %c e uma consoante!", letter);
    }
    return 0;
}