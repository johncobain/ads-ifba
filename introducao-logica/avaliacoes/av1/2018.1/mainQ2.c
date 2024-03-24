#include <stdio.h>

int main(){
    int atk1,atk2,atk3, count  = 0;
    scanf("%d %d %d",&atk1, &atk2,&atk3);
    if(atk1>10||atk2>10||atk3>10){
        count++;
    }
    if(atk1%2==0||atk2%2==0||atk3%2==0){
        count++;
    }
    if(atk1!=0&&atk2!=0&&atk3!=0){
        count++;
    }
    if(count==3){
        printf("Rattata sera derrotado!");
    }else{
        printf("Rattata nao sera derrotado!");
    }
    return 0;
}