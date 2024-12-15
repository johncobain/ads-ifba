#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int val;
    struct list *next;
}list;

void initList(list *l);
int Unshift(list **l, int val);
int Shift(list **l);
/*
void insertEnd();
void insertByIndex();
int removeEnd();
int removeByIndex();
*/
/*
    Push() -> adiciona um elemento ao final de um array e retorna o tamanho deste array
    Pop() -> remove o último elemento de um array e retorna este elemento
    Unshift() -> adiciona um elemento no início de um array e retorna o tamanho deste array
    Shift() -> remove o primeiro elemento de um array e retorna esse elemento
*/

void printList(list *l);


int menu(){
    int opt;
    printf("------------------------\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Unshift\n");
    printf("4. Shift\n");
    printf("5. Print\n");
    printf("0. Exit\n");
    printf("Option: ");
    scanf("%d", &opt);
    return opt;
}

int main(){
    list * myList = NULL;
    initList(myList);

    int opt;
    do{
        int val;
        opt = menu();
        switch(opt){
            case 1:
                printf("Value: ");
                scanf("%d", &val);
                system("clear");
                break;
            case 2:
                system("clear");
                break;
            case 3:
                printf("Value: ");
                scanf("%d", &val);
                system("clear");
                if(val >= 0){
                    int len = Unshift(&myList, val);
                    printf("Length: %d\n", len);
                }else{
                    printf("Invalid value\n");
                }
                break;
            case 4:
                system("clear");
                int retVal = Shift(&myList);
                if(retVal != -1){
                    printf("Value: %d\n", retVal);
                }else{
                    printf("List is empty\n");
                }
                break;
            case 5:
                system("clear");
                printList(myList);
                break;
            case 0:
                system("clear");
                printf("Bye!\n");
                break;
        }
    }while(opt != 0);

    return 0;
}

void initList(list *l){
    l = (list*)malloc(sizeof(list));
}

int Unshift(list **l, int val){
    int len = 1;
    list *newL = malloc(sizeof(list));
    newL->next = *l;
    newL->val = val;
    *l = newL;

    list *currentL = *l;
    while(currentL->next != NULL){
        currentL = currentL->next;
        len++;
    }
    return len;
}

int Shift(list **l){
    int retVal;
    if(*l == NULL){
        return -1;
    }
    list *nextL = NULL;
    nextL = (*l)->next;
    retVal = (*l)->val;
    free(*l);
    *l = nextL;
    return retVal; 
}

void printList(list *l){
    if(l != NULL){    
        while(l->next != NULL){
            printf("%d -> ", l->val);
            l = l->next;
        }
        printf("%d\n", l->val);
    }else{
        printf("List is empty\n");
    }
}