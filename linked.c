#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtbeginnig(int value){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode-> data = value;
    newnode -> next = head;

    head = newnode;
}
void insertAtEnd(int value){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
}