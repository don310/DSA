#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue
struct queue {
    int size;   // Maximum size of the queue
    int r;      // Index of the rear element
    int f;      // Index of the front element
    int* arr;   // Array to store elements of the queue
};

// Function to check if the queue is full
int isFull(struct queue *q) {
    if (q->r == q->size - 1) {
        return 1; // Queue is full
    }
    return 0; // Queue is not full
}

// Function to check if the queue is empty
int isEmpty(struct queue *q) {
    if (q->r == q->f) {
        return 1; // Queue is empty
    }
    return 0; // Queue is not empty
}

// Function to enqueue an element into the queue
void enqueue(struct queue *q, int val) {
    if (isFull(q)) {
        printf("This Queue is full\n"); // Display message if queue is full
    } else {
        q->r++; // Move rear pointer to the next position
        q->arr[q->r] = val; // Insert the value at the rear position
    }
}

// Function to dequeue an element from the queue
int dequeue(struct queue *q) {
    int a = -1; // Default value indicating an empty queue
    if (isEmpty(q)) {
        printf("This Queue is empty\n"); // Display message if queue is empty
    } else {
        q->f++; // Move front pointer to the next position
        a = q->arr[q->f]; // Get the value at the front position
    }
    return a; // Return the dequeued element
}

// Main function
int main() {
    // Initialize a queue
    struct queue q;
    q.size = 2; // Maximum size of the queue
    q.f = q.r = -1; // Initialize front and rear indices
    q.arr = (int*)malloc(q.size * sizeof(int)); // Allocate memory for the queue array

    // Enqueue elements into the queue
    enqueue(&q, 12);
    enqueue(&q, 15);
    
    // Dequeue elements from the queue and print them
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));

    // Check if the queue is empty and full
    if (isEmpty(&q)) {
        printf("Queue is Empty\n");
    }
    if (isFull(&q)) {
        printf("Queue is Full\n");
    }

    free(q.arr); // Free the dynamically allocated memory for the queue array
    return 0; // Exit from the program
}
