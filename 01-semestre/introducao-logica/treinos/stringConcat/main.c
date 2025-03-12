#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[100], str2[100], conc[100];
    gets(str1);
    gets(str2);
    strcat(conc, str1);
    strcat(conc, str2);
    printf("\n%s\n", conc);
    printf("%c %c", str1[1], str2[1]);
    return 0;
}