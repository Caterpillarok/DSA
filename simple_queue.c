#include<stdio.h>
#define MAX 10

int queue[MAX];

int front = -1;
int rear = -1;

void enqueue(){
    if(rear == MAX-1){
        printf("Queue overflow\n");
        return;
    }
    int data; 
    printf("Enter the data you want insert\n");
    scanf("%d",&data);

    if(front == -1)
        front = 0;

    queue[++rear] = data;
    printf("Inserted %d to the queue\n",data);

}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue underflow\n");
        return;
    }
    printf("Value %d deleted ",queue[front++]);

    if(front>rear)
        front = rear = -1;
}

void peek() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty!\n");
    } else {
        printf("\nFront element: %d\n", queue[front]);
    }
}
void display() {
    if (front == -1 || front > rear) {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\nQueue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}
int main() {
    int choice;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: return 0;
            default: printf("\nInvalid choice! Try again.\n");
        }
    }
}