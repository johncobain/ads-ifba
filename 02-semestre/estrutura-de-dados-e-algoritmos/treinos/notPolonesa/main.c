#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXTAM 100

typedef struct {
  float Item[MAXTAM];
  int Topo;
} TPilha;

void initP (TPilha *p) {
  p->Topo = -1;
}

int isEmpty (TPilha *p) {
  if (p->Topo == -1) {
    return 1;
  } else {
    return 0;
  }
}

int push (TPilha *p, int x) {
  if (p->Topo == MAXTAM-1){
    return 0;
  } else {
    if(p->Topo == -1) {
      p->Topo = 0;
    } else {
      p->Topo++;
    }
    p->Item[p->Topo] = x;
    return 1;
  }
}

float pop (TPilha *p) {
  if (isEmpty(p) == 1 ) {
    return 0;
  } else {
    float aux = p->Item[p->Topo];
    p->Topo--;
    return aux;
  }
}

int main() {
    TPilha pilha;
    float lastSum=0;
    initP (&pilha);
    char expressao[MAXTAM];
    printf("Digite a expressao: ");
    scanf("%s", expressao);
    int tamanho = strlen(expressao);
    int i;
    for(i=0;i<tamanho;i++) {
        if(expressao[i]>='0' && expressao[i]<='9') {
            push(&pilha, expressao[i]-'0');
        }else if(expressao[i]=='+' || expressao[i]=='-' || expressao[i]=='*' || expressao[i]=='/') {
            float x, y, sum;
            if(isEmpty(&pilha) == 0) {
                y = pop(&pilha);
                x = pop(&pilha);
                switch(expressao[i]){
                    case '+': sum = x+y; break;
                    case '-': sum = x-y;
                    break;
                    case '*': sum = x*y;
                    break;
                    case '/': sum = x/y;
                    break;
                }
                push(&pilha, sum);
                lastSum = sum;
            }
        }
    }

    printf("%f", lastSum);

    return 0; 
}