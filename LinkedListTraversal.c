#include<stdio.h>
#include<stdlib.h>

// Define a structure for a node in a singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to traverse and print the elements of a linked list
void linkedListTraversal(struct Node* ptr) {
    // Traverse the linked list until the end (ptr becomes NULL)
    while (ptr != NULL) {
        // Print the data of the current node
        printf("Element: %d\n", ptr->data);
        // Move the pointer to the next node
        ptr = ptr->next;
    }
}

int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;

    // Allocate memory for nodes in the linked list in the heap
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    // Call the function to traverse and print the linked list
    linkedListTraversal(head);

    // Return 0 to indicate successful completion of the program
    return 0;
}
