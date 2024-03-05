#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char vetNames[5][100];
    int i;
    for (i = 0; i<5; i++){
        printf("Digite um nome:\n");
        gets(vetNames[i]);
    }
    printf("Os nomes digitados foram:\n");
    for(i=0; i<5; i++){
        printf("%s\n", vetNames[i]);
    }
    
    return 0;
}