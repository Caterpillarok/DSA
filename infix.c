#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define MAX 100

char stack[MAX];

int top =-1;

void push(char c){
    if(top==MAX-1)
        printf("stack overflow\n");
    else
        stack[++top] = c;
}

char pop(){
    if(top==-1){
        printf("stack underflow\n");
        return -1;
     } else{
        return stack[top--];    
    }
  
}

int precendence(char c){
    if(c =='^')
        return 3;
    else if (c =='*' || c =='/')
        return 2;
    else if(c =='+' || c=='-' )
        return 1;
    else
        return 0;

}

