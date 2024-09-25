#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

// Function prototypes
void push(int);
int pop();
void display();

// Global variables
int stack[25] = {0}; // Stack array to store operands
int top = -1; // Top of the stack

int main() {
    char postfix[25] = {'\0'}, ele; // Variable to store postfix expression and current element
    int i, num1, num2, ans; // Loop variable, operands, and result of the operation
    
    // Input postfix expression from the user
    printf("\nEnter postfix expression: ");
    scanf("%s", postfix);
    printf("\nPostfix expression: %s", postfix);

    // Traverse the postfix expression
    i = 0;
    while (i <= strlen(postfix) - 1) {
        ele = postfix[i]; // Get the current element
        
        // If the current element is a digit, push it onto the stack
        if (isdigit(ele)) {
            push(ele - '0'); // Convert character to integer and push
        } else {
            // If the current element is an operator, pop two operands from the stack,
            // perform the operation, and push the result back onto the stack
            num1 = pop();
            num2 = pop();
            switch (ele) {
                case '^':
                    ans = pow(num2, num1);
                    break;
                case '/':
                    ans = num2 / num1;
                    break;
                case '*':
                    ans = num2 * num1;
                    break;
                case '+':
                    ans = num2 + num1;
                    break;
                case '-':
                    ans = num2 - num1;
                    break;
            }
            push(ans); // Push the result onto the stack
        }
        i++;
    }
    printf("\nAns = %d\n", pop()); // Display the final result
    return 0;
}

// User-defined function to push an element onto the stack
void push(int ele) {
    if (top == 24) {
        printf("\nStack is full");
    } else {
        top++;
        stack[top] = ele;
    }
}

// User-defined function to pop an element from the stack
int pop() {
    int ch;
    if (top == -1) {
        printf("\nStack is empty");
        return -1; // Return some default value to indicate stack underflow
    } else {
        ch = stack[top];
        top--;
        return ch;
    }
}

// User-defined function to display the elements of the stack (not used in main)
void display() {
    int i;
    printf("\nStack: ");
    for (i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
