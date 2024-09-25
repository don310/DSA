#include<stdio.h>
#include<string.h>

// Global variables
char stack[20]; // Stack to store characters
int top = -1;   // Top of the stack

// Function prototypes
void push(char);
void pop();

int main() {
    // Variables
    char str[20], ch;
    int l, i;
    
    // Input string from the user
    printf("Welcome to the string reverse program\n");
    printf("Enter String: ");
    fgets(str, 20, stdin);  // Read input string
    l = strlen(str);        // Calculate length of string
    
    // Push each character of the string onto the stack
    for (i = 0; i < l; i++)
        push(str[i]);

    // Print reversed string by popping each character from the stack
    printf("Reversed string: ");
    for (i = 0; i < l; i++) {
        pop();
    }
    printf("\n");
    return 0;
}

// Function to push a character onto the stack
void push(char c) {
    top++;
    stack[top] = c;
}

// Function to pop a character from the stack and print it
void pop() {
    printf("%c", stack[top]);
    top--;
}
