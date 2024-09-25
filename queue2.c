#include<stdio.h>
#include<stdlib.h>
#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x){
    if(rear == N-1){
        printf("Overflow: Queue is full\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Underflow: Queue is Empty\n");
    }
    else if(front == rear){
        front = rear = -1;
    }
    else{
        printf("The enqueue element is %d\n",queue[front]);
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
       printf("queue is full\n");
    }
    for(int i=front; i<=rear+1; i++){
        printf("%d\n",&queue[i]);
    }

}

void peek(){
    if(front == -1 && rear == -1){
        printf("queue is empty\n");
    }
    else{
        printf("%d",queue[front]);
    }
}

int main()
{
    int value, choice;
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Peek\n");
    printf("5. Exit\n");
    
    while(1){
    printf("Enter your choice:\n");
    scanf("\n%d",&choice);
        switch(choice){
            case 1:
        printf("Enter the value:\n");
        scanf("\n%d",&value);
        enqueue(value);
        break;

        case 2:
        dequeue();
        break;

        case 3:
        display();
        break;

        case 4:
        peek();
        break;

        case 5:
        exit(0);
        break;
        
        default:
        printf("Invalid input");
        break;

        }
    }
    return 0;
}