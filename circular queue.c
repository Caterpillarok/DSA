#include <stdio.h>
#define SIZE 5  // maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return ((rear + 1) % SIZE == front);
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element (enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty()) {
        front = 0; // first element
    }
    rear = (rear + 1) % SIZE; // move rear forward circularly
    queue[rear] = value;       // insert value
    printf("Inserted %d\n", value);
}

// Function to remove an element (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = queue[front];  // get the front element
    if (front == rear) {
        // Queue had only one element, now empty
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE; // move front forward circularly
    }
    return value;
}

// Function to display the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;          // stop at rear
        i = (i + 1) % SIZE;            // move forward circularly
    }
    printf("\n");
}

// Main function with menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                value = dequeue();
                if (value != -1) {
                    printf("Dequeued: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
