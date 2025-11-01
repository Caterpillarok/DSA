#include<stdio.h>
#define MAX 10

int front = rear = -1
int cqueue[MAX];

void enqueue(){
    int value;
    printf("Enter the value you want to insert\n");
    scanf("%d",&value);

    if((rear + 1)%MAX ==front){
        printf("Queue overflow\n");
        return;
    }
    if(front ==-1)
        front = 0;
    rear = (rear + 1)%MAX;
    queue[rear] = value;
    printf("value %d inserted ",value);

}
void dequeue(){
    if(front ==-1){
        printf("Queue underflow\n");
        return;
    }
    printf("%d deleted from the queue\n",queue[front]);

    if (front == rear)
        front = rear = -1;
    else
        front = (front +1)%MAX;
}
void peek(){
    if(front ==-1){
        printf("Queue Underflow\n");
        return;
    }
    printf("The element is %d ",queue[rear]);
}
