#include<stdio.h>

// Function prototype
void hanoi(int n, char src, char dest, char aux);

int main() {
    int n;

    // Prompt the user to enter the number of discs
    printf("Enter the number of discs:");
    scanf("%d", &n);

    // Call the hanoi function to solve the Tower of Hanoi problem
    hanoi(n, 'A', 'B', 'C');

    return 0;
}

// Recursive function to solve the Tower of Hanoi problem
// n: Number of discs to move
// src: Source peg
// dest: Destination peg
// aux: Auxiliary peg
void hanoi(int n, char src, char dest, char aux) {
    // Base case: If n is invalid (less than or equal to 0)
    if (n <= 0) {
        printf("Invalid Value");
    }
    // Base case: If there is only one disc to move
    else if (n == 1) {
        printf("\n Move disc %d from %c to %c", n, src, dest);
    }
    // Recursive case: If there are more than one disc to move
    else {
        // Move n-1 discs from source to auxiliary peg using destination peg as auxiliary
        hanoi(n - 1, src, aux, dest);
        
        // Move the remaining disc from source to destination peg directly
        printf("\n Move disc %d from %c to %c", n, src, dest);
        
        // Move the n-1 discs from auxiliary to destination peg using source peg as auxiliary
        hanoi(n - 1, aux, dest, src);
    }
}
