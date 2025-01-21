#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int val;
    struct no *next;    
}No;

int push(No **top, int val);
int pop(No**top);
void printStack(No*top);

int main(){
    No *top = NULL;
    int opt;

    do{
        printf("\n0 - Sair\n1 - Empilhar\n2 - Desemplilhar\n3 - Imprimir\n");
        scanf("%d", &opt);
        switch (opt){
        case 1:
            int val;
            printf("Digite o valor :\\> ");
            scanf("%d", &val);
            push(&top, val);
            break;
        case 2:
            int ret = pop(&top);
            printf("%d", ret);
            break;
        case 3:
            printStack(top);
            break;
        case 0:
            
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }while(opt != 0);
    return 0;
}

int push(No **top, int val){
    No *newNode = malloc(sizeof(No)); 
    if(newNode){
        newNode->val = val;
        newNode->next = *top;
        *top = newNode;
        return 1;
    }else return 0;
}
int pop(No**top){
    No *remove = *top;
    *top = remove->next;
    int retVal = remove->val;
    free(remove);
    return retVal;
}

void printStack(No*top){
    No *temp = top;
    while(temp != NULL){
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL");
}