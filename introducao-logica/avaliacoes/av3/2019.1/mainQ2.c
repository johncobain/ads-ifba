#include <stdio.h>
#define STR_MAX 256

int main(){
    char text[STR_MAX], num[STR_MAX];
    int i;
    fgets(text, STR_MAX, stdin);
    for(i=0; text[i]!='\0';i++){
        if(text[i]=='\n'){
            text[i]='\0';
            num[i]='\0';
        }else if(text[i]=='0'||text[i]=='1'||text[i]=='-'||text[i]==' '){
            num[i] = text[i];
        }else if(text[i]>='A'&& text[i]<='C'){num[i]='2';
        }else if(text[i]>='D'&& text[i]<='F'){num[i]='3';
        }else if(text[i]>='G'&& text[i]<='I'){num[i]='4';
        }else if(text[i]>='J'&& text[i]<='L'){num[i]='5';
        }else if(text[i]>='M'&& text[i]<='O'){num[i]='6';
        }else if(text[i]>='P'&& text[i]<='S'){num[i]='7';
        }else if(text[i]>='T'&& text[i]<='V'){num[i]='8';
        }else if(text[i]>='W'&& text[i]<='Z'){num[i]='9';
        }
    }
    puts(num);
    return 0;
}