#include <stdio.h>

int main(){
    int i, num, bit, base, bin, oct;
    char ch = ' ';
    
    printf("|------------------------------------------------------|\n");
    printf("|--------------------TABELA-ASCII----------------------|\n");
    printf("|------------------------------------------------------|\n");
    for(i=32;i<128;i++){
        base = 1; bin = 0;
        for(num = ch; num>0; num/=2){
            bit = num%2;
            bin+= bit*base;
            base*=10;
        }
        base = 1; oct = 0;
        for(num = ch; num>0; num/=8){
            bit = num%8;
            oct+= bit*base;
            base*=10;
        }
        printf("|               |             |            |           |\n");
        if(ch==127)printf("|Bin: %08d  |  Oct: %04d  |  Dec: %03d  |  Char:%c    |\n",bin, oct, ch, ch);
        else printf("|Bin: %08d  |  Oct: %04d  |  Dec: %03d  |  Char:%c   |\n",bin, oct, ch, ch);
        ch++;
    }
    printf("|------------------------------------------------------|\n");
    printf("|------------------BY-JOHN-COBAIN----------------------|\n");
    printf("|------------------------------------------------------|\n");
 
    return 0;
}