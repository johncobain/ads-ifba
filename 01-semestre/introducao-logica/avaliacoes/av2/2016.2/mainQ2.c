#include <stdio.h>
#define TAM 200

int main(){
    int serie[TAM];
    int n, res, i, dupli;
    for(n=0; n<TAM; n++){
        if(n==0) serie[n] = 0;
        else{
            res = serie[n-1]-n;
            dupli=0;
            for(i=0;i<n;i++){
                if(serie[i]==res)dupli++;
            }
            if(res>0&&dupli==0)serie[n]=res;
            else serie[n] = serie[n-1]+n;
        }
    }
    for(i=0; i<TAM; i++){
        printf("%d ", serie[i]);
    }
    return 0;
}