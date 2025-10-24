#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void insertAtBeginning(int value){
    
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = head;
    newnode->prev = NULL;

    if(head!=NULL)
        head->prev = newnode;
    
    head = newnode;
}
void insertAtEnd(int value){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(head == NULL){
       head = newnode;
       return;
    }        
    struct Node* temp = head;
    while(temp->next!=NULL){
      temp = temp->next;
    }temp->next = newnode;
    newnode->prev = temp;    
}   

void insertAtPosition(int value,int position){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(position == 1){
        insertAtBeginning(value);
        return;
    }

    struct Node* temp = head;

    for(int i=1;i<position -1 && temp!=NULL;i++)
        temp = temp->next;
    
    if(temp == NULL){
        printf("out of bounds\n");
        free(newnode);
        return;
    }    
    newnode->next = temp->next;
    if(temp->next!=NULL){
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void deleteAtBeginning(){
    if(head ==NULL){
        printf("list is empty\n");
        return;
    }

    struct Node* temp = head ;
    head = head->next;

    if(head!=NULL)
        head->prev = NULL;
    free(temp);

}
void deleteAtPosition(int value,int position){
       if(head ==NULL){
        printf("list is empty\n");
        return;
    }

    if(position == 1){
        deleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    for(int i =1;i<position && temp!=NULL;i++)
        temp = temp->next;
    if(temp == NULL){
        printf("position out of bounds\n");
        return;
    }
    if(temp->prev)
        temp->prev->next = temp->next;
    if(temp->next)
        temp->next->prev = temp->prev;

    free(temp);
 }
 void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: NULL <-> ");
    while (temp != NULL) {
        printf("[%d] <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Position\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &position);
                insertAtPosition(value, position);
                break;
            case 3:
                deleteAtBeginning();
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(position,value);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}


