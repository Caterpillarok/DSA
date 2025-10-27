#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node * createNode(int data){
    struct Node *newnode =(struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnde->left = newnode->right = NULL;
    return newnode;
}

struct Node* insert(struct Node*root,int data){
    if(root == NULL)
        createNode(data);
    if(data > root->data)
        root ->right = insert(root->right,data)
    else if(data < root-data)
        root -> left = insert(root->left,data);
    else
        printf("Duplicate value not allowed\n");

    return root;
}
struct Node*search(struct Node* root,int key){
    if(root == NULL || root->data ==key)
        return root;
    
    if(key > root->data)
        return search(root->right,data);
    else
        return search(root->left,data);

}

void inorder(struct Node*root){
    if(root!=NULL)
        inorder(root->data);
        
}
        






    
