#include <stdio.h>
#define CAD 50
#define DIC 5

int main(){
    char fita[CAD], dic[DIC][CAD], equi[DIC][CAD];
    int i,j,k,l, diferenca;
    int igual;
    scanf("%s", fita);
    for(i=0; i<DIC;i++){
        scanf("%s", dic[i]);
        scanf("%s", equi[i]);
    }
    for(i=0;i<DIC;i++){
        for(j=0;fita[j]!='\0';j++){
            if(dic[i][0]==fita[j]){igual=1;
                for(k=0;dic[i][k]!='\0'&&igual==1;k++){
                    if(dic[i][k]!=fita[j+k])igual=0;
                }
                if(igual){diferenca=k;
                    for(k=0;equi[i][k]!='\0';k++){
                        fita[j+k]=equi[i][k];
                    }diferenca-=k;
                    for(k=0;k<diferenca;k++){
                        for(l=j;fita[l]!='\0';l++){
                            fita[l]=fita[l+1];
                        }l--;fita[l]='\0';
                    }
                }
            }
        }
    }
    puts(fita);
    return 0;
}