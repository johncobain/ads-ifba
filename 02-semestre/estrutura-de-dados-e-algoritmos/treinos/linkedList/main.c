#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int val;
    struct list *next;
}list;

void initList(list *l);
int push(list **l, int val);
int pop(list **l);
int unshift(list **l, int val);
int shift(list **l);

int insert(list **l, int val, int index);
int removeL(list **l, int index);

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
    printf("5. Insert\n");
    printf("6. Remove\n");
    printf("7. Print\n");
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
        int val, retVal, len, index;
        opt = menu();
        switch(opt){
            case 1:
                printf("Value: ");
                scanf("%d", &val);
                system("clear");
                if(val >= 0){
                    len = push(&myList, val);
                    printf("Length: %d\n", len);
                }else{
                    printf("Invalid value\n");
                }
                break;
            case 2:
                system("clear");
                retVal = pop(&myList);  
                if(retVal != -1){
                    printf("Value: %d\n", retVal);
                }else{
                    printf("List is empty\n");
                }
                break;
            case 3:
                printf("Value: ");
                scanf("%d", &val);
                system("clear");
                if(val >= 0){
                    len = unshift(&myList, val);
                    printf("Length: %d\n", len);
                }else{
                    printf("Invalid value\n");
                }
                break;
            case 4:
                system("clear");
                retVal = shift(&myList);
                if(retVal != -1){
                    printf("Value: %d\n", retVal);
                }else{
                    printf("List is empty\n");
                }
                break;
            case 5:
                printf("Value: ");
                scanf("%d", &val);
                printf("Index: ");
                scanf("%d", &index);
                system("clear");
                if(val >= 0 && index >= 0){
                    len = insert(&myList, val, index);
                    if(len == -1){
                        printf("Invalid index\n");
                    }else{
                        printf("Length: %d\n", len);
                    }
                }else{
                    printf("Invalid value\n");
                }
                break;
            case 6:
                printf("Index: ");
                scanf("%d", &index);
                system("clear");
                if(index >= 0){
                    retVal = removeL(&myList, index);
                    if(retVal != -1){
                        printf("Value: %d\n", retVal);
                    }else{
                        printf("Invalid index\n");
                    }
                }
                break;
            case 7:
                system("clear");
                printList(myList);
                break;
            case 0:
                system("clear");
                printf("Bye!\n");
                break;
            default:
                system("clear");
                printf("Invalid option\n");
        }
    }while(opt != 0);

    return 0;
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

void initList(list *l){
    l = (list*)malloc(sizeof(list));
}

int push(list **l, int val){
    int len = 1;
    list *currentL = *l;
    list *newL = malloc(sizeof(list));
    if(currentL != NULL){
        while(currentL->next != NULL){
            currentL = currentL->next;
            len++;
        }
        newL->val = val;
        newL->next = NULL;
        currentL->next = newL;
        len++;
    }else{
        newL->val = val;
        newL->next = NULL;
        *l = newL;
    }

    return len;
}

int pop(list **l){
    int retVal;
    list *currentL = *l;
    if(*l == NULL){
        return -1;
    }

    if(currentL->next == NULL){
        retVal = currentL->val;
        free(currentL);
        *l = NULL;
        return retVal;
    }
    while(currentL->next->next != NULL){
        currentL = currentL->next;
    }

    retVal = currentL->next->val;
    free(currentL->next);
    currentL->next = NULL;

    return retVal;
}

int unshift(list **l, int val){
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

int shift(list **l){
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

int insert(list **l, int val, int index){
    int len = 1, i=0;
    list *currentL = *l;
    if(index == 0){
        return unshift(l, val);
    }
    while(i < index-1){
        if(currentL->next == NULL){
            return -1;
        }
        currentL = currentL->next;
        len++;
        i++;
    }
    list *newL = malloc(sizeof(list));
    newL->val = val;
    newL->next = currentL->next;
    currentL->next = newL;
    while(currentL->next != NULL){
        currentL = currentL->next;
        len++;
    }
    return len;
}

int removeL(list **l, int index){
    int retVal, i=0;
    list *currentL = *l;
    if(index == 0){
        return shift(l);
    }
    while(i < index-1){
        if(currentL->next == NULL){
            return -1;
        }
        currentL = currentL->next;
        i++;
    }
    retVal = currentL->next->val;
    list *nextL = currentL->next->next;
    free(currentL->next);
    currentL->next = nextL;
    return retVal;
}