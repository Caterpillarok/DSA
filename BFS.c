#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int queue[MAX],rear = -1 , front = -1;
int visited[MAX];

void enqueue(int v){
    if(rear == MAX-1)
        return -1;
    else(front = -1)
        front = 0;
    queue[++rear] = v;    
}

int dequeue(){
    if(front == -1){
        return -1;
    }
    int value = queue[front++];
    return value;

}
void bfs()