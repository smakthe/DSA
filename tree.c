#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *left;
    int data;
    struct Node *right;
} Node;

Node *create(int data){
    Node *new = (Node *)malloc(sizeof(Node));
    new->left,new->right = NULL;
    new->data = data;
    return new;
}

Node *insert(Node *root, int value){
    if(root == NULL){
        return create(value);
    }
    if(root->data > value){
        root->left = insert(root->left,value);
    }
    else{
        root->right = insert(root->right,value);
    }
    return root;
}

void preOrderTraversal(Node* root) {
    if (root != NULL) {
        printf("%i ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%i ", root->data);
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%i ", root->data);
    }
}

void main(){

    Node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 5);
    root = insert(root, 19);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 16);
    root = insert(root, 33);
    postOrderTraversal(root);

}