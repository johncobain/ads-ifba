/*QUESTÃO I (5.0)
Na álgebra de inteiros foi definida uma nova operação chamada de maximização de inteiros. A
maximização de dois números inteiros A e B segue as seguintes regras:
1. Inicialmente fazemos A e B terem o mesmo número de dígitos, adicionando zeros à esquerda
conforme necessário.
2. Então cada dígito de A (do menos significativo ao mais significativo) é comparado com o dígito
correspondente de B. Nesta comparação, o dígito de menor valor é eliminado do número a que
pertence (se eles são iguais, nenhum é eliminado).
3. O resultado da operação é a dupla de números formados pelos dígitos remanescentes. Caso não
haja dígitos remanescentes em um dos números, o equivalente na dupla resultado para este número
é -1.
Por exemplo, considere a maximização de 453 e 92. Após o passo 1, teremos: 453 e 092; em
seguida compara-se 4 > 0; 5 < 9 e 3>2. Será eliminado o 5 do primeiro número e serão eliminados
o 0 e o 2 do segundo número. A dupla resultado será (43 e 5).
Sua tarefa é escrever um programa em C, que calcule a operação maximização para dois inteiros
entre 0 e 999
*/
#include <stdio.h>

int main(){
    int numA, numB, d2A, d1A, d0A, d2B, d1B, d0B, resA, resB;
    printf("Insira dois numeros:\\>");
    scanf("%d %d",&numA,&numB);
    d2A = numA/100;d1A = (numA%100)/10;d0A=numA%10;
    d2B = numB/100;d1B = (numB%100)/10;d0B=numB%10;
    if(d2A >d2B){d2B=0;}else if(d2B>d2A){d2A=0;}
    if(d1A >d1B){d1B=0;}else if(d1B>d1A){d1A=0;}
    if(d0A >d0B){d0B=0;}else if(d0B>d0A){d0A=0;}

    if(d0A>0||d0A==d0B){
        resA = d0A; if(d1A>0||d1A==d1B){resA+=d1A*10;
            if(d2A>0|| d2A==d2B){resA+=d2A*100;}
            }else if(d2A>0||d2A==d2B){resA+=d2A*10;}
    }else if(d1A>0||d1A==d1B){resA = d1A;
        if(d2A>0|| d2A==d2B){resA+=d2A*10;}
    }else if(d2A>0||d2A==d2B){resA = d2A;
    }else{resA = -1;}

    if(d0B>0||d0B==d0A){
        resB = d0B; if(d1B>0||d1B==d1A){resB+=d1B*10;
            if(d2B>0|| d2B==d2A){resB+=d2B*100;}
            }else if(d2B>0||d2B==d2A){resB+=d2B*10;}
    }else if(d1B>0||d1B==d1A){resB = d1B;
        if(d2B>0|| d2B==d2A){resB+=d2B*10;}
    }else if(d2B>0||d2B==d2A){resB = d2B;
    }else{resB = -1;}
    printf("Dupla resultado: (%03d, %03d)",resA, resB);
    return 0;
}