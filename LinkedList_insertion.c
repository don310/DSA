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

//case 1:
// Function to insert a new node at the beginning of the linked list
struct Node* insertAtFirst(struct Node* head, int data) {
    // Allocate memory for the new node
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    // Set the data of the new node
    ptr->data = data;
    // Set the next pointer of the new node to the current head
    ptr->next = head;
    // Return the new node as the new head of the linked list
    return ptr;
}

//Case 3:
// Function to insert a new node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    // Allocate memory for the new node
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    // Set the data of the new node
    ptr->data = data;
    // Set the next pointer of the new node to NULL (since it will be the last node)
    ptr->next = NULL;
    
    // Traverse the linked list to find the last node
    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    // Link the last node to the new node
    p->next = ptr;
    // Return the head of the linked list
    return head;
}

//Case 3:
// Function to insert a new node at a specified index in the linked list
struct Node* insertAtIndex(struct Node* head, int data, int index) {
    // Allocate memory for the new node
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    // Set the data of the new node
    ptr->data = data;
    
    // Traverse the linked list to find the node at the specified index
    struct Node* p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    // Insert the new node between the current node and the next node
    ptr->next = p->next;
    p->next = ptr;
    // Return the head of the linked list
    return head;
}

//Case 4:
// Function to insert a new node after a specified node in the linked list
struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data) {
    // Allocate memory for the new node
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    // Set the data of the new node
    ptr->data = data;
    // Link the new node to the next node after the specified node
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    // Return the head of the linked list
    return head;
}

// Main function
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

    printf("Linked list before insertion\n");
    // Call the function to traverse and print the linked list
    linkedListTraversal(head);

    // Call the function to insert a new node at the beginning of the linked list
    // head = insertAtFirst(head, 56);

    // Call the function to insert a new node at a specified index in the linked list
    // head = insertAtIndex(head, 56, 1);

    // Call the function to insert a new node at the end of the linked list
    // head = insertAtEnd(head, 56);

    // Call the function to insert a new node after a specified node in the linked list
    head = insertAfterNode(head, third, 45);

    printf("Linked list after insertion\n");
    // Call the function to traverse and print the linked list
    linkedListTraversal(head);
    
    // Return 0 to indicate successful completion of the program
    return 0;
}
