#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Function to display the linked list
void display() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at beginning
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at specific position
void insertAtPosition(int data, int position) {
    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

// Delete from position
void deleteFromPosition(int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    if (position == 1) {
        head = temp->next;
        free(temp);
        return;
    }

    for (int i = 1; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }

    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

// Search for an element
void search(int key) {
    struct Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element %d not found\n", key);
}

// Count number of nodes
int countNodes() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Main function (menu-driven)
int main() {
    int choice, data, pos;

    while (1) {
        printf("\n--- Singly Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Count Nodes\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(data, pos);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteFromPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 9:
                printf("Number of nodes = %d\n", countNodes());
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
