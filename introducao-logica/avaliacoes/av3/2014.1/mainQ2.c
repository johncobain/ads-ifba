#include <stdio.h>
#define MAX 256

int main(){
    char text[MAX];
    int maiorC=0, somaC, ehConsoante, i, j;

    fgets(text,MAX,stdin);
    for (i = 0; text[i] != '\0'; i++){
        if((text[i]>'a'&&text[i]<='z'&&text[i]!='e'&&text[i]!='i'&&text[i]!='o'&&text[i]!='u')||
        (text[i]>'A'&&text[i]<='Z'&&text[i]!='E'&&text[i]!='I'&&text[i]!='O'&&text[i]!='U')){
            somaC=1; ehConsoante=1;
            for(j=i+1; ehConsoante==1; j++){
                if((text[j]>'a'&&text[j]<='z'&&text[j]!='e'&&text[j]!='i'&&text[j]!='o'&&text[j]!='u')||
                (text[j]>'A'&&text[j]<='Z'&&text[j]!='E'&&text[j]!='I'&&text[j]!='O'&&text[j]!='U')){
                    somaC++;
                }else ehConsoante=0;
            }
            if(somaC>maiorC)maiorC=somaC;
        }
    }
    printf("%d",maiorC);

    return 0;
}