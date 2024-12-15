#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int val;
    struct list *next;
}list;

void initList(list *l);
void push(list **l, int val);
int pop(list **l);
/*
void insertEnd();
void insertByIndex();
int removeEnd();
int removeByIndex();
*/

void printList(list *l);


int menu(){
    int opt;
    printf("------------------------\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print\n");
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
        opt = menu();
        switch(opt){
            case 1:
                int val;
                printf("Value: ");
                scanf("%d", &val);
                system("clear");
                if(val >= 0){
                    push(&myList, val);
                }else{
                    printf("Invalid value\n");
                }
                break;
            case 2:
                system("clear");
                int retVal = pop(&myList);
                if(retVal != -1){
                    printf("Value: %d\n", retVal);
                }else{
                    printf("List is empty\n");
                }
                break;
            case 3:
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

void push(list **l, int val){
    list *newL = malloc(sizeof(list));
    newL->next = *l;
    newL->val = val;
    *l = newL;
}

int pop(list **l){
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