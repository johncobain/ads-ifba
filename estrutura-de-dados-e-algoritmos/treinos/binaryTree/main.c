#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;

  struct Node *left;
  struct Node *right;
} Node;

Node *insert(Node *root, int data){
  Node *temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;

  if(root == NULL){
    root = temp;
  }else{
    Node *current = root;
    Node *parent = NULL;
    while(1){
      parent = current;
      if(data < parent->data){
        current = current->left;

        if(current == NULL){
          parent->left = temp;
          return root;
        }
        
      }else{
        current = current->right;

        if(current == NULL){
          parent->right = temp;
          return root;
        }
      }
    }
  }

  return root;
}

void inorder_traversal(Node *root){
  if(root){
    inorder_traversal(root->left);
    printf("%d\n", root->data);
    inorder_traversal(root->right);
  }
}

void pre_order(Node *root){
  if(root){
    printf("%d\n", root->data);
    pre_order(root->left);
    pre_order(root->right);
  }
}

void post_order(Node *root){
  if(root){
    post_order(root->left);
    post_order(root->right);
    printf("%d\n", root->data);
  }
}

void inorder_dec(Node *root){
  if(root){
    inorder_dec(root->right);
    printf("%d\n", root->data);
    inorder_dec(root->left);
  }
}

int search(Node *root, int data){
  if(root == NULL) return NULL;
  
  if(data == root->data) return root->data;

  if(data < root->data)return search(root->left, data);

  return search(root->right, data);
}

int main(){
  int i;
  int array[14] = 
  {34, 84, 15, 0, 2, 99, 79, 9, 88, 18, 31, 39, 100, 101};

  Node *root = NULL;

  for(i=0; i< 14; i++){
    root = insert(root, array[i]);
    printf("Inserted %d\n", array[i]);
  }

  printf("\nInorder traversal:\n");
  inorder_traversal(root);
  printf("\nPreorder:\n");
  pre_order(root);
  printf("\nPostorder:\n");
  post_order(root);
  printf("\nInorder Dec:\n");
  inorder_dec(root);

  int temp = search(root, 88);
  if(temp != NULL){
    printf("Found %d\n", temp);
  }else{
    printf("Not found\n");
  }

  return 0;
}