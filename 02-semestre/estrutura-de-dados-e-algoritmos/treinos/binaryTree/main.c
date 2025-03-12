#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  int data;

  struct Node *left;
  struct Node *right;
  int hight;
} Node;

Node *newNode(int data){
  Node *new = malloc(sizeof(Node));
  if(new){
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    new->hight = 0;
  }else{
    printf("Memory allocation error\n");
  }

  return new;
}

int biggerHight(int a, int b){
  return (a > b) ? a : b;
}

int hight(Node *root){
  if(root == NULL) return -1;
  return root->hight;
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

  root->hight = biggerHight(hight(root->left), hight(root->right))+1;
  l->hight = biggerHight(hight(l->left), hight(l->right))+1;

  return l;
}

Node* leftRotation(Node *root){
  printf("Left Rotation\n");
  Node *l, *r;
  r = root->right;
  l = root->left;

  r->left = root;
  root->right = l;

  root->hight = biggerHight(hight(root->left), hight(root->right))+1;
  r->hight = biggerHight(hight(r->left), hight(r->right))+1;

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

Node *insert(Node *root, int data){
  if(root == NULL){
    return newNode(data);
  }else{
    if(data < root->data){
      root->left = insert(root->left, data);
    }else{
      root->right = insert(root->right, data);
    }
  }

  root->hight = biggerHight(hight(root->left), hight(root->right))+1;

  root = balance(root);

  return root;
}


Node *removeNo(Node *root, int data){
  if(root == NULL) {
    return NULL;
  }else{
    if(root->data == data){
      if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
      }else {
        if(root->left != NULL && root->right != NULL){
        Node *temp = root->right;
        while(temp->left != NULL){
          temp = temp->left;
        }
        root->data = temp->data;
        temp->data = data;
        root->right = removeNo(root->right, data);
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
      }
    }else{
      if(data < root->data){
        root->left = removeNo(root->left, data);
      }else{
        root->right = removeNo(root->right, data);
      }
    }
  }

  root->hight = biggerHight(hight(root->left), hight(root->right))+1;

  root = balance(root);

  return root;
}

void printTree(Node *root, int level){
  int i;
  if(root){
    printTree(root->right, level+1);
    printf("\n\n");

    for(i=0; i< level; i++){
      printf("\t");
    }
    printf("%d\n", root->data);
    printTree(root->left, level+1);
  }
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

int qtdLeafs(Node *root){
  if(root == NULL){
    return 0; // Árvore vazia ou subárvore inexistente, não há folhas
  }
  else if(root->left == NULL && root->right == NULL){
    return 1; // Nó folha encontrado
  }
  else{
    return qtdLeafs(root->left) + qtdLeafs(root->right); // Soma os nós folha das subárvores esquerda e direita
  }
}


int search(Node *root, int data){
  if(root == NULL) return NULL;
  
  if(data == root->data) return root->data;

  if(data < root->data)return search(root->left, data);

  return search(root->right, data);
}

int main(){
  int opt, val;
  Node *root = NULL;

  do{
    printf("\n\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n");
    scanf("%d", &opt);
    switch (opt){
    case 1:
      printf("Digite o valor :\\> ");
      scanf("%d", &val);
      root = insert(root, val);
      break;
    case 2:
      printf("Digite o valor :\\> ");
      scanf("%d", &val);
      root = removeNo(root, val);
      break;
    case 3:
      printTree(root, 0);
      break;
    default:
      break;
    }

  }while(opt != 0);

  return 0;
}
