#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;

  struct Node *left;
  struct Node *right;
  int hight;
} Node;

Node *newNode(int data);
Node *insert(Node *root, int data); 
Node *remove(Node *root, int data);
Node *balance(Node *root);
Node *rightRotation(Node *root);
Node *leftRotation(Node *root);
Node *leftRightRotation(Node *root);
Node *rightLeftRotation(Node *root);
int hight(Node *root);
int biggerHight(Node *root);
int balanceFactor(Node *root);

Node *newNode(int data){
  Node *new = (Node*)malloc(sizeof(Node));
  if(new){
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->hight = 0;
  }else{
    printf("Memory allocation error\n");
    exit(1);
  }

  return new;
}

Node *insert(Node *root, int data){
  Node *temp = newNode(data);

  if(root == NULL){
    return temp;
  }else{
    if(data < root->data){
      root->left = insert(root->left, data);
    }else{
      root->right = insert(root->right, data);
    }
  }

  root->hight = biggerHight(root)+1;

  root = balance(root);

  return root;
}

Node *remove(Node *root, int data){
  if(root == NULL) return NULL;
  if(root->data == data){
    if(root->left == NULL && root->right == NULL){
      free(root);
      return NULL;
    }else if(root->left != NULL && root->right != NULL){
      Node *temp = root->right;
      while(temp->left != NULL){
        temp = temp->left;
      }
      root->data = temp->data;
      temp->data = data;
      root->right = remove(root->right, data);
      return root;
    }else{
      Node *temp;
      if(root->left != NULL){
        temp = root->left;
      }else{
        temp = root->right;
      }
      free(root);
      return temp;
    }
  }else{
    if(data < root->data){
      root->left = remove(root->left, data);
    }else{
      root->right = remove(root->right, data);
    }
  }

  root->hight = biggerHight(root)+1;

  root = balance(root);

  return root;
}

void inorder_traversal(Node *root){
  if(root){
    inorder_traversal(root->left);
    printf("%d\n", root->data);
    inorder_traversal(root->right);
  }
}

void pre_order(Node *root, int *qtdLeafs){
  if(root){
    printf("%d\n", root->data);
    pre_order(root->left, qtdLeafs);
    pre_order(root->right, qtdLeafs);;
    if(root->left == NULL && root->right == NULL){
      *qtdLeafs = *qtdLeafs + 1;
    }
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

int hight(Node *root){
  if(root == NULL) return -1;
  return root->hight;
}

int biggerHight(Node *root){
  return (root->left->hight > root->right->hight) ? root->left->hight : root->right->hight;
}

int balanceFactor(Node *root){
  if(root == NULL) return 0;

  return hight(root->left) - hight(root->right);
}

Node*  rightRotation(Node *root){
  printf("Right Rotation\n");
  Node *l, *r;
  l = root->left;
  r = root->right;

  l->right = root;
  root->left = r;

  root->hight = biggerHight(root)+1;
  l->hight = biggerHight(l)+1;

  return l;
}

Node* leftRotation(Node *root){
  printf("Left Rotation\n");
  Node *l, *r;
  r = root->right;
  l = root->left;

  r->left = root;
  root->right = l;

  root->hight = biggerHight(root)+1;
  r->hight = biggerHight(r)+1;

  return r;
}

Node* leftRightRotation(Node *root){
  root->left = leftRotation(root->left);
  return rightRotation(root);
}

Node* rightLeftRotation(Node *root){
  root->right = rightRotation(root->right);
  return leftRotation(root);  
}

Node* balance(Node *root){
  int bf = balanceFactor(root);

  if(bf< -1 && balanceFactor(root->right) <= 0){
    root = leftRotation(root);
  }else if(bf > 1 && balanceFactor(root->left) >= 0){
    root = rightRotation(root);
  }else if(bf > 1 && balanceFactor(root->left) < 0){
    root = leftRightRotation(root);
  }else if(bf < -1 && balanceFactor(root->right) > 0){
    root = rightLeftRotation(root);
  }
    
  return root;
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
  {34, 84, 95, 100, 102, 99, 79, 9, 88, 18, 31, 39, 100, 101};

  Node *root = NULL;
  int qtdLeafs = 0;

  for(i=0; i< 14; i++){
    root = insert(root, array[i]);
    printf("\nInserted %d\n", array[i]);
    printf("Balance Factor: %d\n", balanceFactor(root));
    printf("Root: %d\n", root->data);
    printf("Hight: %d\n", hight(root));
  }
  printf("\nInorder traversal:\n");
  inorder_traversal(root);
  printf("\nPreorder:\n");
  pre_order(root , &qtdLeafs);
  printf("Qtd Leafs: %d\n", qtdLeafs);
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