#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

int isEmpty(){
    return top == NULL;
}

void push(int value){
    struct Node* Newnode = (struct Node*)malloc(sizeof(struct Node));
    if (Newnode == NULL){
        printf("stack overflow\n");
        return;
    }
    Newnode->data = value;
    Newnode->next = top;
    top = Newnode;
}

void pop(){
    if(isEmpty()){
        printf("stack underflow \n");
        return;
    }
    struct Node* temp = top;
    printf("The eleement popped fromt the stack is %d\n ",temp->data);
    top = top->next;
    free(temp);
}
void peek(){
    if(isEmpty()){
        printf("stack underlfow\n");
        return;
    }
    printf("The top element is %d ",top->data);
}


