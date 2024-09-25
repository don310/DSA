#include<stdio.h>
#define MAXSTACK 5 // Define max size of stack

int stack[MAXSTACK], top = -1; // Initialize top of stack to -1
void push();
void pop();
void show();

int main() {
    int choice;
    do {
        printf("\n1-For Push\n");
        printf("2-For Pop\n");
        printf("3-For Show\n");
        printf("4-For Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                return 0; // Exiting the program
            default:
                printf("Invalid input!\n");
        }
    } while (1);
    return 0;
}

void push() {
    if (top == MAXSTACK - 1) { // Check if stack is full
        printf("Stack is full\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &stack[++top]); // Increment top and then push value
    }
}

void pop() {
    if (top == -1) { // Check if stack is empty
        printf("Stack is empty\n");
    } else {
        printf("Popped element is: %d\n", stack[top--]); // Pop and then decrement top
    }
}

void show() {
    if (top == -1) { // Check if stack is empty
        printf("Stack is empty\n");
    } else {
        printf("Stack elements are: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]); // Print elements of stack
        }
        printf("\n");
    }
}
